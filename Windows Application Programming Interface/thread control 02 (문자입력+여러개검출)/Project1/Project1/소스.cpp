#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Key");
HWND MainWnd;

typedef struct _Parameter{
	int x, y;
	TCHAR ch;
}PARAMETER;

PARAMETER param[3] = { { 100, 125, 'a' },
{ 100, 150, 'b' },
{ 100, 175, 'c' } };

TCHAR str[256];

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
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
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	MainWnd = hWnd;
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

HANDLE hEvent;
DWORD WINAPI ThreadFunc(LPVOID temp)
{
	HDC hdc;
	int len;
	
	PARAMETER *p = (PARAMETER*)temp;
	TCHAR buf[256];
	while (true){
		WaitForSingleObject(hEvent, INFINITE);
		len = lstrlen(str);
		int count = 0;
		for (int i = 0; i < len; i++)
		{
			if (str[i] == p->ch)
				count++;
		}
		hdc = GetDC(MainWnd);
		wsprintf(buf, TEXT("%cÀÇ °¹¼ö: %d"), p->ch, count);
		TextOut(hdc, p->x, p->y, buf, lstrlen(buf));
		ReleaseDC(MainWnd, hdc);
		ResetEvent(hEvent);
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HANDLE hThread[3];
	DWORD ThreadID;
	int len;

	switch (iMessage) {
	case WM_CREATE:
		for (int i = 0; i < 3; i++)	
			hThread[i] = CreateThread(NULL, 0, ThreadFunc, &param[i], 0, &ThreadID);
		return 0;
	case WM_CHAR:
		//*
		SetEvent(hEvent);

		len = lstrlen(str);
		str[len] = (TCHAR)wParam;
		str[len + 1] = 0;
		InvalidateRect(hWnd, NULL, FALSE);
		//*/
		/*
		if ((TCHAR)wParam == ' ') {
		str[0]=0;
		} else {
		len=lstrlen(str);
		str[len]=(TCHAR)wParam;
		str[len+1]=0;
		}
		InvalidateRect(hWnd,NULL,TRUE);
		//*/
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 100, 100, str, lstrlen(str));
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		for (int i = 0; i < 3; i++)
			CloseHandle(hThread[i]);
		CloseHandle(hEvent);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
