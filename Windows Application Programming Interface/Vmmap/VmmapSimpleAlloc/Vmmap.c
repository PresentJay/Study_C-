/************************************************************
Module name: VMMap.C
Notices: Copyright (c) 1995 Jeffrey Richter
************************************************************/


#include "..\AdvWin32.H"    /* See Appendix B for details. */
#include <windows.h>
#include <windowsx.h>

#pragma warning(disable: 4001)      /* Single-line comment */

#include <tchar.h>
#include <stdio.h>             // For sprintf
#include <string.h>            // For strchr
#include "Resource.H"
#include "VMQuery.H"


/////////////////////////////////////////////////////////////


// Set COPYTOCLIPBOARD to TRUE if you want the 
// memory map to be copied to the clipboard.
#define COPYTOCLIPBOARD    FALSE


#if COPYTOCLIPBOARD
// Function to copy the contents of a list box to the clipboard.
// I used this function to obtain the memory map dumps
// for the figures in this book.


void CopyControlToClipboard (HWND hwnd) {
   int nCount, nNum;
   TCHAR szClipData[20000] = { 0 };
   HGLOBAL hClipData;
   LPTSTR lpClipData;
   BOOL fOk;

   nCount = ListBox_GetCount(hwnd);
   for (nNum = 0; nNum < nCount; nNum++) {
      TCHAR szLine[1000];
      ListBox_GetText(hwnd, nNum, szLine);
      _tcscat(szClipData, szLine);
      _tcscat(szClipData, __TEXT("\r\n"));
   }        

   OpenClipboard(NULL); 
   EmptyClipboard();

   // Clipboard accepts only data that is in a block allocated 
   // with GlobalAlloc using the GMEM_MOVEABLE and 
   // GMEM_DDESHARE flags.
   hClipData = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, 
      sizeof(TCHAR) * (_tcslen(szClipData) + 1));
   lpClipData = (LPTSTR) GlobalLock(hClipData);
   
   _tcscpy(lpClipData, szClipData);

#ifdef UNICODE
   fOk = (SetClipboardData(CF_UNICODETEXT, hClipData)
      == hClipData);
#else
   fOk = (SetClipboardData(CF_TEXT, hClipData) == hClipData);
#endif
   CloseClipboard();

   if (!fOk) {
      GlobalFree(hClipData);
      MessageBox(GetFocus(),
         __TEXT("Error putting text on the clipboard"), 
         NULL, MB_OK | MB_ICONINFORMATION);
   }
}

#endif


/////////////////////////////////////////////////////////////


LPCTSTR GetMemStorageText (DWORD dwStorage) {
   LPCTSTR p = __TEXT("Unknown");
   switch (dwStorage) {
      case MEM_FREE:    p = __TEXT("Free   "); break;
      case MEM_RESERVE: p = __TEXT("Reserve"); break;
      case MEM_IMAGE:   p = __TEXT("Image  "); break;
      case MEM_MAPPED:  p = __TEXT("Mapped "); break;
      case MEM_PRIVATE: p = __TEXT("Private"); break;
   }
   return(p);
}


/////////////////////////////////////////////////////////////


LPTSTR GetProtectText (DWORD dwProtect, LPTSTR szBuf,
   BOOL fShowFlags) {
   LPCTSTR p = __TEXT("Unknown");
   switch (dwProtect & ~(PAGE_GUARD | PAGE_NOCACHE)) {
      case PAGE_READONLY:           p = __TEXT("-R--"); break;
      case PAGE_READWRITE:          p = __TEXT("-RW-"); break;
      case PAGE_WRITECOPY:          p = __TEXT("-RWC"); break;
      case PAGE_EXECUTE:            p = __TEXT("E---"); break;
      case PAGE_EXECUTE_READ:       p = __TEXT("ER--"); break;
      case PAGE_EXECUTE_READWRITE:  p = __TEXT("ERW-"); break;
      case PAGE_EXECUTE_WRITECOPY:  p = __TEXT("ERWC"); break;
      case PAGE_NOACCESS:           p = __TEXT("----"); break;
   }
   _tcscpy(szBuf, p);
   if (fShowFlags) {
      _tcscat(szBuf, __TEXT(" "));
      _tcscat(szBuf, (dwProtect & PAGE_GUARD)   ?
         __TEXT("G") : __TEXT("-"));
      _tcscat(szBuf, (dwProtect & PAGE_NOCACHE) ?
         __TEXT("N") : __TEXT("-"));
   }
   return(szBuf);
}


/////////////////////////////////////////////////////////////


void ConstructRgnInfoLine (PVMQUERY pVMQ,
   LPTSTR szLine, int nMaxLen) {

   int nLen;

   _stprintf(szLine, __TEXT("%08X     %s  %10u  "),
      pVMQ->pvRgnBaseAddress,
      GetMemStorageText(pVMQ->dwRgnStorage),
      pVMQ->dwRgnSize);

   if (pVMQ->dwRgnStorage != MEM_FREE) {
      _stprintf(_tcschr(szLine, 0), __TEXT("%5u  "), 
         pVMQ->dwRgnBlocks);
      GetProtectText(pVMQ->dwRgnProtection,
         _tcschr(szLine, 0), FALSE);
   }

   _tcscat(szLine, __TEXT("     "));

   // Try to obtain the module pathname for this region.
   nLen = _tcslen(szLine);
   if (pVMQ->pvRgnBaseAddress != NULL) 
      GetModuleFileName((HINSTANCE) pVMQ->pvRgnBaseAddress, 
         szLine + nLen, nMaxLen - nLen);

   if (pVMQ->pvRgnBaseAddress == GetProcessHeap()) {
         _tcscat(szLine, __TEXT("Default Process Heap"));
   }

   if (pVMQ->fRgnIsAStack) {
      _tcscat(szLine, __TEXT("Thread Stack"));
   }
}


/////////////////////////////////////////////////////////////


void ConstructBlkInfoLine (PVMQUERY pVMQ,
   LPTSTR szLine, int nMaxLen) {

   _stprintf(szLine, __TEXT("   %08X  %s  %10u         "),
      pVMQ->pvBlkBaseAddress,
      GetMemStorageText(pVMQ->dwBlkStorage),
      pVMQ->dwBlkSize);

   if (pVMQ->dwBlkStorage != MEM_FREE) {
      GetProtectText(pVMQ->dwBlkProtection,
         _tcschr(szLine, 0), TRUE);
   }
}


/////////////////////////////////////////////////////////////


void Dlg_OnSize (HWND hwnd, UINT state, int cx, int cy) {
   SetWindowPos(GetDlgItem(hwnd, IDC_LISTBOX), NULL, 0, 0,
      cx, cy, SWP_NOZORDER);
}


/////////////////////////////////////////////////////////////


BOOL Dlg_OnInitDialog (HWND hwnd, HWND hwndFocus,
   LPARAM lParam) {

   HWND hWndLB = GetDlgItem(hwnd, IDC_LISTBOX);
   PVOID pvAddress = 0x00000000;
   TCHAR szLine[200];
   RECT rc;
   DWORD dwBlock;
   VMQUERY VMQ;
   BOOL fOk = TRUE;

// skk-insertion
	GlobalAlloc(GMEM_FIXED, 500000000);

    // Associate an icon with the dialog box.
   SetClassLong(hwnd, GCL_HICON, (LONG)
      LoadIcon((HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
      __TEXT("VMMap")));

   // Make a horizontal scroll bar appear in the list box.
   ListBox_SetHorizontalExtent(hWndLB,
      150 * LOWORD(GetDialogBaseUnits()));

   // The list box must be sized first because the system
   // doesn't send a WM_SIZE message to the dialog box when
   // it's first created.
   GetClientRect(hwnd, &rc);
   SetWindowPos(hWndLB, NULL, 0, 0, rc.right, rc.bottom,
      SWP_NOZORDER);


   // Walk the virtual address space, adding
   // entries to the list box.
   while (fOk) {
      fOk = VMQuery(pvAddress, &VMQ);

      if (fOk) {
         // Construct the line to be displayed, and
         // add it to the list box.
         ConstructRgnInfoLine(&VMQ, szLine, sizeof(szLine));
         ListBox_AddString(hWndLB, szLine);

#if 1
         // Change the 1 above to a 0 if you do not want
         // to see the blocks contained within the region.

         for (dwBlock = 0; fOk && (dwBlock < VMQ.dwRgnBlocks);
            dwBlock++) {

            ConstructBlkInfoLine(&VMQ, szLine, sizeof(szLine));
            ListBox_AddString(hWndLB, szLine);

            // Get the address of the next region to test.
            pvAddress = ((BYTE *) pvAddress + VMQ.dwBlkSize);
            if (dwBlock < VMQ.dwRgnBlocks - 1) {
               // Don't query the memory info after
               // the last block.
               fOk = VMQuery(pvAddress, &VMQ);
            }
         }
#endif

         // Get the address of the next region to test.
         pvAddress = ((BYTE *) VMQ.pvRgnBaseAddress +
            VMQ.dwRgnSize);
      }
   }

#if COPYTOCLIPBOARD
   CopyControlToClipboard(hWndLB);
#endif
   return(TRUE);
}


/////////////////////////////////////////////////////////////


void Dlg_OnCommand (HWND hwnd, int id, HWND hwndCtl,
   UINT codeNotify) {

   switch (id) {
	  case ID_MEMALLOC :
		 /*MessageBox(hwnd,  __TEXT("TEST"), 
		  __TEXT("Test Message Box"),MB_OK);  
		  */

		 break;
      case IDCANCEL:
         EndDialog(hwnd, id);
         break;
   }
}


/////////////////////////////////////////////////////////////


BOOL CALLBACK Dlg_Proc (HWND hDlg, UINT uMsg,
   WPARAM wParam, LPARAM lParam) {

   BOOL fProcessed = TRUE;
   switch (uMsg) {
      HANDLE_MSG(hDlg, WM_INITDIALOG, Dlg_OnInitDialog);
      HANDLE_MSG(hDlg, WM_COMMAND, Dlg_OnCommand);
      HANDLE_MSG(hDlg, WM_SIZE, Dlg_OnSize);

      default:
         fProcessed = FALSE;
         break;
   }
   return(fProcessed);
}


/////////////////////////////////////////////////////////////


int WINAPI WinMain (HINSTANCE hinstExe,
   HINSTANCE hinstPrev, LPSTR lpszCmdLine, int nCmdShow) {

   DialogBox(hinstExe, MAKEINTRESOURCE(IDD_VMMAP),
      NULL, Dlg_Proc);
   return(0);
}


//////////////////////// End Of File ////////////////////////
