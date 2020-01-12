#define UNICODE
#define _UNICODE

#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("Class");

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PTSTR lpszCmdParam, int nCmdShow)
{
    HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    g_hInst = hInstance;

    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = hInstance;
    WndClass.lpfnWndProc = (WNDPROC)WndProc;
    WndClass.lpszClassName = lpszClass;
    WndClass.lpszMenuName = NULL;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&WndClass);

    hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                        NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    hWndMain = hWnd;

    while (GetMessage(&Message, 0, 0, 0))
    {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    PROCESS_INFORMATION pi;
    DWORD dwExitCode;
    STARTUPINFO si = {sizeof(si)};
    TCHAR szCommandLine[] = TEXT("child 15");
    TCHAR str[100];
    //	TCHAR *szCommandLine=TEXT("NotePad");
    TCHAR *tmp;
    switch (iMessage)
    {
    case WM_CREATE:
        return 0;

    case WM_LBUTTONDOWN:
        // spawn the child process.
        if (CreateProcess(NULL, szCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        {
            // close the thread handle as soon as it is no longer needed!
            CloseHandle(pi.hThread);

            // suspend our execution until the child has terminated.
            WaitForSingleObject(pi.hProcess, INFINITE);

            // the child process terminated; get its exit code.
            GetExitCodeProcess(pi.hProcess, &dwExitCode);

            //close the process handle as soon as it is no longer needed.
            CloseHandle(pi.hProcess);
            wsprintf(str, TEXT("%d"), dwExitCode);
            MessageBox(hWnd, str, TEXT("answer"), 0);
        }
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}