#include <windows.h>

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
void PaintWindow (HWND hWnd, POINT pt, int iColor, int iPSize);
HWND hWndMain;

HINSTANCE g_hInst;
LPSTR lpszClass="ListBox Project For Test";


int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
		  ,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst=hInstance;
	
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)(COLOR_BTNFACE+1);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=(WNDPROC)WndProc;
	WndClass.lpszClassName=lpszClass;
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);
	
	while(GetMessage(&Message,0,0,0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

DWORD WINAPI ThreadFunc(LPVOID );
#define ID_RESULT 100
HWND hResult;

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	PAINTSTRUCT ps;
	int i;
	HANDLE hThread;
	static int ThreadId[3];
	HDC hDC;

	switch(iMessage) {
	case WM_CREATE:
		hWndMain = hWnd;
		hResult=CreateWindow("listbox", NULL,WS_CHILD | WS_VISIBLE | 
			WS_BORDER | WS_VSCROLL | LBS_NOTIFY | LBS_NOINTEGRALHEIGHT, //교재 p.303
			0,0,0,0,hWnd,(HMENU)ID_RESULT,g_hInst,NULL);
		return 0;
	
	case WM_SIZE:
		MoveWindow(hResult,LOWORD(lParam)/2,0, LOWORD(lParam)/2, HIWORD(lParam), TRUE);
		return 0;
	
	case WM_COMMAND:
		return 0;

	case WM_PAINT:
		hDC=BeginPaint (hWnd, &ps) ;
		TextOut(hDC, 10,10, "여기서 왼쪽버튼을 누르시오", strlen("여기서 왼쪽버튼을 누르시오"));
		EndPaint (hWnd, &ps) ;
		return 0;

	case WM_LBUTTONDOWN:
		// 세개의 스레드를 만든다.
		for (i=0;i<3;i++)
		{	
			ThreadId[i]=i;
			hThread=CreateThread(NULL,0,ThreadFunc,&ThreadId[i],0,NULL);
			CloseHandle(hThread);
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

int theerrno;

void SetThreadError(int ErrorNum)
{
	theerrno = ErrorNum;
}

int GetThisThreadError()
{
	return theerrno;

}
DWORD WINAPI ThreadFunc(LPVOID temp)
{
	char buf[256];
	int* myId=(int*)temp;
	int i;
	//Thread 에서 error 발생했다고 가정
	//Error Number는 thread ID 로 가정하고 설정
	SetThreadError(*myId);
	//Do Something... ..... 
	//나중에 필요해서 Thread 에서 발생한 error code를 가져온다...
	for (i = 0; i < 3; i++)
	{
		wsprintf(buf, "my id = %d  : error number = %d", *myId, GetThisThreadError());
		SendMessage(hResult, LB_ADDSTRING, 0, (LPARAM)buf);
	}
	return 0;
}

