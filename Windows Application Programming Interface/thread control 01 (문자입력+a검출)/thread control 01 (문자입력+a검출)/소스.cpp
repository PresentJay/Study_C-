#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Keydown + Thread to check 'A' word");
HWND MainWnd;
int counter = 0;
TCHAR str[128];
RECT rt;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	if (!hPrevInstance) {
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
	}
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	MainWnd = hWnd;
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

DWORD WINAPI A_wordChecker(LPVOID temp) {
	HDC hdc;
	int len;
	TCHAR tmp[130];
	TCHAR ch = *(TCHAR*)temp;
	len = lstrlen(str);
	if (len < 125) {
		str[len] = ch;
		str[len + 1] = 0;
		if (ch == 'a' || ch == 'A')
			counter++;
	}
	wsprintf(tmp, TEXT("A(a) : %d개"), counter);
	hdc = GetDC(MainWnd);
	TextOut(hdc, 100, 100, str, lstrlen(str));
	TextOut(hdc, 100, 150, tmp, lstrlen(tmp));
	ReleaseDC(MainWnd, hdc);
	return 0;
}


// 프로그램 실행과 동시에 스레드를 하나 만든다.
long FAR PASCAL WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	DWORD ThreadID;
	HANDLE tThread;
	HDC hdc;
	TCHAR ch;

	switch (iMessage) {
	case WM_CREATE:
		GetClientRect(hWnd, &rt);
		MainWnd = hWnd;
		return 0;

	case WM_CHAR:
		tThread = CreateThread(NULL, 0, A_wordChecker, &wParam, 0, &ThreadID);
		CloseHandle(tThread);
		return 0;

	case WM_DESTROY:
		
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}
