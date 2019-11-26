#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <tchar.h>
#define VER 2

// Windows procedure의 반환형 : LRESULT (long 변수의 다른 이름.)
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);   
HINSTANCE g_hInst;	//객체 핸들값이라는 의미~
LPCTSTR lpszClass = TEXT("API Practice From Jay Present .v01");
int Lx_arr[200], Ly_arr[200], Rx_arr[200], Ry_arr[200];
int Lcount = 0, Rcount = 0;

									//프로그램의 객체핸들	   이전프로그램의 객체핸들    실행직후 열 파일경로  프로그램 형태
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;	// Windows의 핸들값
	MSG Message; // 메세지~!~!
	WNDCLASS WndClass; // 윈도우 클래스~!~!~!
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 0, 255));  // 배경!
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // 커서모양!
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // 아이콘모양!
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,	NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	SYSTEMTIME st;
	WCHAR strCount[50];
	int x, y;

	HBRUSH hBrush, oldBrush;

	switch (iMessage) {
	case WM_CREATE:
		srand((unsigned)time(NULL));
		SetTimer(hWnd, 1, 3000, NULL);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;

	case WM_TIMER:
		
		return 0;

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		Lx_arr[Lcount] = x;
		Ly_arr[Lcount] = y;
		Lcount++;
		wsprintf(strCount, TEXT("현재 빨간 점 개수 = %d    현재 파란 점 개수 = %d"), Lcount,Rcount);
		hdc = GetDC(hWnd);
		TextOut(hdc, 5, 5, TEXT("Red Color "), 10);
		TextOut(hdc, 5, 30, strCount, lstrlen(strCount));
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		switch ((int)VER)
		{
			case 1: Ellipse(hdc, x - 8, y - 8, x + 8, y + 8); break;
			case 2: Rectangle(hdc, x - 8, y - 8, x + 8, y + 8); break;
		}
		
		ReleaseDC(hWnd, hdc);
		return 0;

	case WM_RBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		Rx_arr[Rcount] = x;
		Ry_arr[Rcount] = y;
		Rcount++;
		wsprintf(strCount, TEXT("현재 빨간 점 개수 = %d    현재 파란 점 개수 = %d"), Lcount, Rcount);
		hdc = GetDC(hWnd);
		TextOut(hdc, 5, 5, TEXT("Blue Color"), 10);
		TextOut(hdc, 5, 30, strCount, lstrlen(strCount));
		hBrush = CreateSolidBrush(RGB(0, 0, 255));
		oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		switch ((int)VER)
		{
		case 1: Ellipse(hdc, x - 8, y - 8, x + 8, y + 8); break;
		case 2: Rectangle(hdc, x - 8, y - 8, x + 8, y + 8); break;
		}

		ReleaseDC(hWnd, hdc);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		wsprintf(strCount, TEXT("현재 빨간 점 개수 = %d    현재 파란 점 개수 = %d"), Lcount, Rcount);
		TextOut(hdc, 5, 30, strCount, lstrlen(strCount));
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		for (int i=0; i<Lcount; i++)
			switch ((int)VER) {
			case 1: Ellipse(hdc, Lx_arr[i] - 8, Ly_arr[i] - 8, Lx_arr[i] + 8, Ly_arr[i] + 8); break;
			case 2: Rectangle(hdc, Lx_arr[i] - 8, Ly_arr[i] - 8, Lx_arr[i] + 8, Ly_arr[i] + 8); break;
			}
		hBrush = CreateSolidBrush(RGB(0, 0, 255));
		oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		for (int i = 0; i<Rcount; i++)
			switch ((int)VER) {
			case 1: Ellipse(hdc, Rx_arr[i] - 8, Ry_arr[i] - 8, Rx_arr[i] + 8, Ry_arr[i] + 8); break;
			case 2: Rectangle(hdc, Rx_arr[i] - 8, Ry_arr[i] - 8, Rx_arr[i] + 8, Ry_arr[i] + 8); break;
			}
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
