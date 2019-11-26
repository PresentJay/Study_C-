#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <tchar.h>
#define VER 2

// Windows procedure�� ��ȯ�� : LRESULT (long ������ �ٸ� �̸�.)
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);   
HINSTANCE g_hInst;	//��ü �ڵ鰪�̶�� �ǹ�~
LPCTSTR lpszClass = TEXT("API Practice From Jay Present .v01");
int Lx_arr[200], Ly_arr[200], Rx_arr[200], Ry_arr[200];
int Lcount = 0, Rcount = 0;

									//���α׷��� ��ü�ڵ�	   �������α׷��� ��ü�ڵ�    �������� �� ���ϰ��  ���α׷� ����
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;	// Windows�� �ڵ鰪
	MSG Message; // �޼���~!~!
	WNDCLASS WndClass; // ������ Ŭ����~!~!~!
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 0, 255));  // ���!
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // Ŀ�����!
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // �����ܸ��!
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
		wsprintf(strCount, TEXT("���� ���� �� ���� = %d    ���� �Ķ� �� ���� = %d"), Lcount,Rcount);
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
		wsprintf(strCount, TEXT("���� ���� �� ���� = %d    ���� �Ķ� �� ���� = %d"), Lcount, Rcount);
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
		wsprintf(strCount, TEXT("���� ���� �� ���� = %d    ���� �Ķ� �� ���� = %d"), Lcount, Rcount);
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
