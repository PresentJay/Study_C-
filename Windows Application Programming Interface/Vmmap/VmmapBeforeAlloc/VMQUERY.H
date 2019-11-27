/************************************************************
Module name: VMQuery.H
Notices: Copyright (c) 1995 Jeffrey Richter
************************************************************/


typedef struct {
   // Region information
   PVOID pvRgnBaseAddress;
   DWORD dwRgnProtection;  // PAGE_*
   DWORD dwRgnSize;
   DWORD dwRgnStorage;     // MEM_*: Free, Image,
                           //        Mapped, Private
   DWORD dwRgnBlocks;
   DWORD dwRgnGuardBlks;   // If > 0, region contains
                           // thread stack
   BOOL  fRgnIsAStack;     // TRUE if region contains
                           // thread stack

   // Block information
   PVOID pvBlkBaseAddress;
   DWORD dwBlkProtection;  // PAGE_*
   DWORD dwBlkSize;
   DWORD dwBlkStorage;     // MEM_*: Free, Reserve, Image,
                           //        Mapped, Private
} VMQUERY, *PVMQUERY;


/////////////////////////////////////////////////////////////


BOOL VMQuery (PVOID pvAddress, PVMQUERY pVMQ);


//////////////////////// End Of File ////////////////////////
