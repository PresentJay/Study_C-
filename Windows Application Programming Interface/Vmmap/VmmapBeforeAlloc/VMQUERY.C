/************************************************************
Module name: VMQuery.C
Notices: Copyright (c) 1995 Jeffrey Richter
************************************************************/


#include "..\AdvWin32.H"     /* See Appendix B for details */
#include <windows.h>
#include <windowsx.h>

#pragma warning(disable: 4001)      /* Single-line comment */

#include "VMQuery.H"


/////////////////////////////////////////////////////////////


typedef struct {
   DWORD dwRgnSize;
   DWORD dwRgnStorage;     // MEM_*: Free, Image,
                           //        Mapped, Private
   DWORD dwRgnBlocks;
   DWORD dwRgnGuardBlks;   // If > 0, region contains
                           // thread stack
   BOOL  fRgnIsAStack;     // TRUE if region contains
                           // thread stack
} VMQUERY_HELP;


// Global-static variable that holds the 
// allocation granularity value for this CPU platform. This
// variable is initialized the first time VMQuery is called.
static DWORD gs_dwAllocGran = 0;


/////////////////////////////////////////////////////////////


// When NTBUG_VIRTUALQUERY is defined, the code below 
// compensates for a bug in Windows NT's implementation of 
// the VirtualQuery function.
#define NTBUG_VIRTUALQUERY    

#ifdef NTBUG_VIRTUALQUERY
DWORD NTBug_VirtualQuery (LPVOID lpvAddress, 
   PMEMORY_BASIC_INFORMATION pmbiBuffer, DWORD cbLength) {

   DWORD dwRetVal = VirtualQuery(lpvAddress, 
      pmbiBuffer, cbLength);

   if (dwRetVal == cbLength) {
      // If successful, correct the MBI structure's values.

      if (((DWORD) pmbiBuffer->AllocationBase % 0x1000)
         == 0xFFF) {
         // If the AllocationBase member ends with 0xFFF, 
         // the address is 1 byte off.
         pmbiBuffer->AllocationBase = (PVOID) 
            ((PBYTE) pmbiBuffer->AllocationBase + 1);
      }  

      if ((pmbiBuffer->RegionSize % 0x1000) == 0xFFF) {
         // If the RegionSize member ends with 0xFFF, 
         // the size is 1 byte off.
         pmbiBuffer->RegionSize++;
      }

      if ((pmbiBuffer->State != MEM_FREE) &&
          (pmbiBuffer->AllocationProtect == 0)) {
         // If the the region is not free and the 
         // AllocationProtect member is 0, AllocationProtect 
         // should be PAGE_READONLY.
         pmbiBuffer->AllocationProtect = PAGE_READONLY;
      }
   }

   return(dwRetVal);
}


#define VirtualQuery NTBug_VirtualQuery
#endif


/////////////////////////////////////////////////////////////


// This function iterates through all the blocks in a 
// region and initializes a structure with its findings.
static BOOL VMQueryHelp (PVOID pvAddress,
   VMQUERY_HELP *pVMQHelp) {

   MEMORY_BASIC_INFORMATION MBI;
   PVOID pvRgnBaseAddress, pvAddressBlk;
   BOOL fOk; 
   DWORD dwProtectBlock[4] = { 0 };
      // 0 = reserved, PAGE_NOACCESS, PAGE_READWRITE

   // Zero the contents of the structure.
   memset(pVMQHelp, 0, sizeof(*pVMQHelp));

   // From the passed memory address, obtain the
   // base address of the region that contains it.
   fOk = (VirtualQuery(pvAddress, 
      &MBI, sizeof(MBI)) == sizeof(MBI));

   if (!fOk) {
      // If we can't get any information about the passed 
      // address, return FALSE, indicating an error.
      // GetLastError() will report the actual problem.
      return(fOk);
   }

   // pvRgnBaseAddress identifies the region's
   // base address and will never change.
   pvRgnBaseAddress = MBI.AllocationBase;

   // pvAddress identifies the address of the first block
   // and will change as we iterate through the blocks.
   pvAddressBlk = pvRgnBaseAddress;

   // Save the memory type of the physical storage block.
   pVMQHelp->dwRgnStorage = MBI.Type;

   for (;;) {
      // Get info about the current block.
      fOk = VirtualQuery(pvAddressBlk, &MBI, sizeof(MBI));
      if (!fOk) {
         // Couldn't get the information, end loop.
         break;
      }

      // Check to see whether the block we got info for is
      // contained in the requested region.
      if (MBI.AllocationBase != pvRgnBaseAddress) {
         // Found a block in the next region; end loop.
         break;
      }


      // We have found a block contained
      // in the requested region.


      // The following if statement is for detecting stacks in 
      // Windows 95. Windows 95 stacks are in a region wherein
      // the last 4 blocks have the following attributes:
      // reserved block, PAGE_NOACCESS, PAGE_READWRITE,
      // and another reserved block.
      if (pVMQHelp->dwRgnBlocks < 4) {
         // If this is the 0th through 3rd block, make
         // a note of the block's protection in our array.
         dwProtectBlock[pVMQHelp->dwRgnBlocks] = 
            (MBI.State == MEM_RESERVE) ? 0 : MBI.Protect;
      } else {
         // We have already seen 4 blocks in this region.
         // Shift the protection values down in the array.
         MoveMemory(&dwProtectBlock[0], &dwProtectBlock[1], 
            sizeof(dwProtectBlock) - sizeof(DWORD));

         // Add the new protection value to the end
         // of the array.
         dwProtectBlock[3] = 
            (MBI.State == MEM_RESERVE) ? 0 : MBI.Protect;
      }


      // Add 1 to the number of blocks in the region.
      pVMQHelp->dwRgnBlocks++;

      // Add the block's size to the reserved region size.
      pVMQHelp->dwRgnSize += MBI.RegionSize;

      // If the block has the PAGE_GUARD protection attribute 
      // flag, add 1 to the number of blocks with this flag.
      if (MBI.Protect & PAGE_GUARD) {
         pVMQHelp->dwRgnGuardBlks++;
      }


      // Take a best guess as to the type of physical storage
      // committed to the block. This is a guess because some
      // blocks can convert from MEM_IMAGE to MEM_PRIVATE or
      // from MEM_MAPPED to MEM_PRIVATE; MEM_PRIVATE can
      // always be overridden by MEM_IMAGE or MEM_MAPPED.
      if (pVMQHelp->dwRgnStorage == MEM_PRIVATE) {
         pVMQHelp->dwRgnStorage = MBI.Type;
      }


      // Get the address of the next block.
      pvAddressBlk = (PVOID)
         ((PBYTE) pvAddressBlk + MBI.RegionSize);
   }

   // After examining the region, check to see whether it is
   // a thread stack.
   // Windows NT: Assume a thread stack if the region contains
   //             at least 1 block with the PAGE_GUARD flag.
   // Windows 95: Assume a thread stack if the region contains
   //             at least 4 blocks wherein the last 4 blocks
   //             have the following attributes:
   //             3rd block from end: reserved
   //             2nd block from end: PAGE_NOACCESS
   //             1st block from end: PAGE_READWRITE
   //             block at end: another reserved block.
   pVMQHelp->fRgnIsAStack =
      (pVMQHelp->dwRgnGuardBlks > 0) ||
      ((pVMQHelp->dwRgnBlocks >= 4) &&
       (dwProtectBlock[0] == 0) && 
       (dwProtectBlock[1] == PAGE_NOACCESS) &&
       (dwProtectBlock[2] == PAGE_READWRITE) &&
       (dwProtectBlock[3] == 0));

   // Return that the function completed successfully.
   return(TRUE);
}


/////////////////////////////////////////////////////////////


BOOL VMQuery (PVOID pvAddress, PVMQUERY pVMQ) {

   MEMORY_BASIC_INFORMATION MBI;
   VMQUERY_HELP VMQHelp;
   BOOL fOk;

   if (gs_dwAllocGran == 0) {
      // If this is the very first time a thread in this 
      // application is calling us, we must obtain the size 
      // of a page used on this system and save this value
      // in a global-static variable.
      SYSTEM_INFO SI;
      GetSystemInfo(&SI);
      gs_dwAllocGran = SI.dwAllocationGranularity;
   }


   // Zero the contents of the structure.
   memset(pVMQ, 0, sizeof(*pVMQ));

   // Get the MEMORY_BASIC_INFORMATION for the passed address.
   fOk = VirtualQuery(pvAddress, 
      &MBI, sizeof(MBI)) == sizeof(MBI);

   if (!fOk) {
      // If we can't get any information about the passed 
      // address, return FALSE, indicating an error.
      // GetLastError() will report the actual problem.
      return(fOk);
   }

   // The MEMORY_BASIC_INFORMATION structure contains valid
   // information. Time to start setting the members
   // of our own VMQUERY structure.


   // First, fill in the block members. We'll get the
   // data for the region containing the block later.
   switch (MBI.State) {
      case MEM_FREE:
         // We have a block of free address space that
         // has not been reserved.
         pVMQ->pvBlkBaseAddress = NULL;
         pVMQ->dwBlkSize = 0;
         pVMQ->dwBlkProtection = 0;
         pVMQ->dwBlkStorage = MEM_FREE;
         break;

      case MEM_RESERVE:
         // We have a block of reserved address space that
         // does NOT have physical storage committed to it.
         pVMQ->pvBlkBaseAddress = MBI.BaseAddress;
         pVMQ->dwBlkSize = MBI.RegionSize;

         // For an uncommitted block, MBI.Protect is invalid.
         // So we will show that the reserved block inherits
         // the protection attribute of the region in which it
         // is contained.
         pVMQ->dwBlkProtection = MBI.AllocationProtect;  
         pVMQ->dwBlkStorage = MEM_RESERVE;
         break;

      case MEM_COMMIT:
         // We have a block of reserved address space that
         // DOES have physical storage committed to it.
         pVMQ->pvBlkBaseAddress = MBI.BaseAddress;
         pVMQ->dwBlkSize = MBI.RegionSize;
         pVMQ->dwBlkProtection = MBI.Protect;   
         pVMQ->dwBlkStorage = MBI.Type;
         break;
   }

   // Second, fill in the region members now that we have
   // used the MBI data obtained from the first call to
   // VirtualQuery. We might have to call VirtualQuery again
   // to obtain complete region information.
   switch (MBI.State) {
      case MEM_FREE:
         // We have a block of address space
         // that has not been reserved.
         pVMQ->pvRgnBaseAddress = MBI.BaseAddress;
         pVMQ->dwRgnProtection = MBI.AllocationProtect;
         pVMQ->dwRgnSize = MBI.RegionSize;
         pVMQ->dwRgnStorage = MEM_FREE;
         pVMQ->dwRgnBlocks = 0;
         pVMQ->dwRgnGuardBlks = 0;
         pVMQ->fRgnIsAStack = FALSE;
         break;

      case MEM_RESERVE:
         // We have a reserved region that does NOT have 
         // physical storage committed to it.
         pVMQ->pvRgnBaseAddress = MBI.AllocationBase;
         pVMQ->dwRgnProtection = MBI.AllocationProtect;

         // To get complete information about the region, we
         // must iterate through all the region's blocks.
         VMQueryHelp(pvAddress, &VMQHelp);

         pVMQ->dwRgnSize = VMQHelp.dwRgnSize;
         pVMQ->dwRgnStorage = VMQHelp.dwRgnStorage;
         pVMQ->dwRgnBlocks = VMQHelp.dwRgnBlocks;
         pVMQ->dwRgnGuardBlks = VMQHelp.dwRgnGuardBlks;
         pVMQ->fRgnIsAStack = VMQHelp.fRgnIsAStack;
         break;

      case MEM_COMMIT:
         // We have a reserved region that DOES have 
         // physical storage committed to it.
         pVMQ->pvRgnBaseAddress = MBI.AllocationBase;
         pVMQ->dwRgnProtection = MBI.AllocationProtect;

         // To get complete information on the region, we
         // must iterate through all the region's blocks.
         VMQueryHelp(pvAddress, &VMQHelp);

         pVMQ->dwRgnSize = VMQHelp.dwRgnSize;
         pVMQ->dwRgnStorage = VMQHelp.dwRgnStorage;
         pVMQ->dwRgnBlocks = VMQHelp.dwRgnBlocks;
         pVMQ->dwRgnGuardBlks = VMQHelp.dwRgnGuardBlks;
         pVMQ->fRgnIsAStack = VMQHelp.fRgnIsAStack;
         break;
   }

   // Return that the function completed successfully.
   return(fOk);
}


//////////////////////// End Of File ////////////////////////
