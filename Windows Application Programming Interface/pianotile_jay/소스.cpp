#include <windows.h>
#include "resource.h"

// 20143174 ������, 2018�⵵ 2�б� Windows Application Programming Interface,
// Win32 API�� ���� ������Ʈ, KeyBoard Game with Thread, Subclassing �Դϴ�.

// ���� �� ���� & ��Ȯ�� ������ �� ���� ����
#define		PROJECT_NAME		TEXT("20143174 - ������ - ȭ���� - ����������Ʈ")
#define		MENU_STATUS			NULL
#define		KEY_WIDTH				300																					// ���� ȭ���� �ʺ�
#define		KEY_HEIGHT			600																						// ���� ȭ���� ����
#define		KEY_NOTE_WID		KEY_WIDTH / max_col														// ��Ʈ�� ��� �ʺ�
#define		KEY_NOTE_HEIGHT	KEY_HEIGHT / (max_row-2)												// ��Ʈ�� ��� ����
#define		ENDING_Y(i)				KEY_HEIGHT - KEY_NOTE_HEIGHT * i								// ����ȭ�� �ϴ����κ����� ������ ���̰��
#define		KEY_BASECOLOR		RGB(200, 200, 200)										// ����ȭ�� ������
#define		KEY_HITBARCOLOR	RGB(220, 150, 40)											// ������ ��
#define		KEY_HITCOLOR		RGB(220, 150, 150)										// �������� ��
#define		KEY_NOTECOLOR	RGB(100, 100, 150)											// ��Ʈ ��
//

// ����ü �����
struct NoteData { int top, bottom, pos; };							// �����̰��� col��ġ���� ������ ��Ʈ ����ü
typedef struct _Parameter { int x, y, order; TCHAR NAME[6]; } PARAMETER;
//

// �������� �����
int					scoreArray[10000],
					count_data = 0;
HINSTANCE	g_hInst;
HWND			hWndDlg;
LPCTSTR		lpszClass = PROJECT_NAME;
WNDPROC	OldProc;			// ����Ŭ����
HANDLE		hMutex;			// ���ؽ� ����ȭ
HANDLE		hEvent;				// �̺�Ʈ ����ȭ
HWND			BT_KeyGame;	// KeyGame�� ������ ��ư
NoteData		*m_note;
PARAMETER Param[3] = { { 240, 280, 3, TEXT("Good") },{ 240, 310, 2, TEXT("Bad") },{ 240, 340, 1, TEXT("Miss") } };	// ���� �Ķ����
RECT			base_rt,				// ���� ȭ�� rect
					hitbar_rt;			// hit_bar rect
RECT			rt;						// Dialog ��üȭ�� rect
int					max_col = 6,			// col ����
					max_row = 11,		// row ����
					move_step = 5,		// ���� �̵� ����
					game_fps = 30;		// ȭ�� ���� ���� (�������� ���� / 1000(1��) ���)
int				combo_current = 0,
				combo_max = 0;
TCHAR		using_key[6] = { 'S', 'D', 'F', 'J', 'K', 'L' };
bool			hit_checker[6] = { FALSE, };		// FALSE : non-hit , TRUE : hit
int				J_checker[6] = { 0, };					// 0 : non-judgement,  1: miss,  2: bad,  3: good
bool			isPaused = FALSE;
//

// �Լ������
LRESULT	CALLBACK	Message_Tracer_Proc(HWND, UINT, WPARAM, LPARAM);	// ����Ŭ���� �Լ�
DWORD	WINAPI		Score_control_Thread(LPVOID);
LRESULT	CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);						// �����Լ�
BOOL		CALLBACK	KeyGame_DlgProc(HWND, UINT, WPARAM, LPARAM);		// ���� Dialog �Լ�
void								PaintTheBase(HWND);															// ����ȭ�� ����Լ�
void								noteChanger(int);																	// col�� ��Ʈ�ʱ�ȭ�Լ�
//

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = MENU_STATUS;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	while (GetMessage(&Message, NULL, 0, 0)) { TranslateMessage(&Message); DispatchMessage(&Message); }
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	switch (iMessage) {
	case WM_CREATE:
		srand(GetTickCount());
		BT_KeyGame = CreateWindow(TEXT("button"), TEXT("KeyBoard Game"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 150, 200, 300, 75, hWnd, (HMENU)0, g_hInst, NULL);
		return 0;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case 0:	// ���� ��ư Ŭ�� ��
			EnableWindow(BT_KeyGame, FALSE);		// �������� �ʵ��� ��ư ��Ȱ��ȭ
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_KEYGAME), hWnd, (DLGPROC)KeyGame_DlgProc);
			break;
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

// KeyBoard Game Procedure
BOOL CALLBACK KeyGame_DlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT		ps;
	HDC						hdc;
	DWORD				ThreadID;

	switch (iMessage) {
	case WM_INITDIALOG:
		hMutex = CreateMutex(NULL, FALSE, NULL);												// ���ؽ� ����ȭ ����
		hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);													// �̺�Ʈ ����
		SetRect(&hitbar_rt, 0, ENDING_Y(1.5), KEY_WIDTH, ENDING_Y(1.5) + 3);		// ���� RECT ����
		SetRect(&base_rt, 0, 0, KEY_WIDTH, KEY_HEIGHT);										// ���� ȭ�� RECT ����
		GetClientRect(hDlg, &rt);																				// ���� Dialog RECT ����
		SetTimer(hDlg, 1, game_fps, NULL);					// Ÿ�̸� ����
		hWndDlg = hDlg;

		m_note = new NoteData[max_row];				// row ����ŭ (��Ʈ ũ�� �� �پ��ϰ� �ٲ�) NoteData �����Ҵ�
		// ���� ��Ʈ�� ����
		m_note[0] = { KEY_NOTE_HEIGHT*(-1), 0, rand() % max_col };
		for (int i = 1; i < max_row; i++)
			m_note[i] = { m_note[i - 1].top - KEY_NOTE_HEIGHT, m_note[i - 1].bottom - KEY_NOTE_HEIGHT, rand() % max_col };
		//

		// ������ ����
		for (int i = 0; i < 3; i++)
			CloseHandle(CreateThread(NULL, 0, Score_control_Thread, &Param[i], 0, &ThreadID));
		

		OldProc = (WNDPROC)SetWindowLongPtr(hDlg, GWLP_WNDPROC, (LONG_PTR)Message_Tracer_Proc);		// ����Ŭ����
		
		
		return TRUE;

	case WM_TIMER:		// ��Ʈ �������� ���־����� �κ��� ���
sjlkdf		for (int i = 0; i < max_row; i++) {
			if (m_note[i].top < KEY_HEIGHT) {					// ��Ʈ�� Ű���� ȭ�� ���� ���� �������� �̵� 
				if (m_note[i].bottom >= hitbar_rt.top + 3 && hit_checker[m_note[i].pos] == TRUE) {	// ��Ʈ�� ���� ���� ���� ( 3�� ���� �߰�, �������� �� ) �̸鼭, Ű�� �������� �ִ� ���
					// ��Ʈ �ϰ� ó�� Ÿ�� : HitBar�� ������ ���
					if (m_note[i].top + move_step < hitbar_rt.top) {
						m_note[i].top += move_step;
						m_note[i].bottom = hitbar_rt.top;
					}
					else { //�ϰ��Ϸ��, �ش� col ��Ʈ �ʱ�ȭ
						noteChanger(i);
						J_checker[m_note[i].pos] = 0;
					}
				}
				else {			//  ��Ʈ�� ���� ���� �ٱ����̰�, ����ؼ� ȭ�� ������ �����Ϸ��� ��
					if (m_note[i].bottom > hitbar_rt.bottom + 20 && hit_checker[m_note[i].pos] == FALSE) {
						// miss���� ó��
						combo_current = 0;
						scoreArray[count_data] = 1;
						count_data++;
						J_checker[m_note[i].pos] = 1;
						SetEvent(hEvent);
						//
					}
					// ��Ʈ �ϰ� ó�� Ÿ�� : �Ϲ� (�ٴڿ� ������ ���)
					if (m_note[i].top + move_step < KEY_HEIGHT) {
						m_note[i].top += move_step;
						if (m_note[i].bottom < KEY_HEIGHT)
							m_note[i].bottom += move_step;
					}
					else {
						J_checker[m_note[i].pos] = 0;
						noteChanger(i);
					}
				}
			}
			else {
				J_checker[m_note[i].pos] = 0;
				noteChanger(i);
			}
			// ȭ�� ��ȭ �׽� ����

			InvalidateRect(hDlg, &base_rt, FALSE);
			UpdateWindow(hDlg);
			//
		}
		return TRUE;

	case WM_KEYDOWN:
		for (int j = 0; j < max_col; j++) {
			if ((TCHAR)wParam == using_key[j]) {
				hit_checker[j] = TRUE;
				for (int i = 0; i < max_row; i++) {
					if (m_note[i].pos == j) {
						if (m_note[i].bottom >= ENDING_Y(2.5)) {		// ���� �ȿ��� üũ �õ� ��
							// �ּ� ������ ������ ������ ���
							if (m_note[i].bottom < hitbar_rt.bottom + 20) {
								// ���� ���� ���� ���� ������ ���
								if (J_checker[m_note[i].pos] == 0) {
									// Good ���� ������ ó�� bottom�� ������ ��
									if (m_note[i].bottom < hitbar_rt.top - 20) {
										// bad ���� ó��
										scoreArray[count_data] = 2;
										count_data++;
										J_checker[m_note[i].pos] = 2;
										SetEvent(hEvent);
										//
									}
									// Good ���� �ȿ��� ó�� bottom�� ������ ��
									else {
										// good ���� ó��
										combo_current++;
										if (combo_current > combo_max)
											combo_max = combo_current;
										scoreArray[count_data] = 3;
										count_data++;
										J_checker[m_note[i].pos] = 3;
										SetEvent(hEvent);
										//
									}
								}
								// ���� ���°� miss ���� ���
								else if (J_checker[m_note[i].pos] == 1) {
									// bad ���� ó��
									scoreArray[count_data] = 2;
									count_data++;
									J_checker[m_note[i].pos] = 2;
									SetEvent(hEvent);
									//
								}
								// ���� ���°� bad ���� ���
								else if (J_checker[m_note[i].pos] == 2) {
									// bad ���� ó��
									scoreArray[count_data] = 2;
									count_data++;
									J_checker[m_note[i].pos] = 2;
									SetEvent(hEvent);
									//
								}
								else if (J_checker[m_note[i].pos] == 3 && m_note[i].pos == i) {	// ���� ���°� good �̾��� ���
																								// good ���� ó��
									combo_current++;
									if (combo_current > combo_max)
										combo_max = combo_current;
									scoreArray[count_data] = 3;
									count_data++;
									J_checker[m_note[i].pos] = 3;
									SetEvent(hEvent);
									//
								}
							}
							// �ּ� ������ �Ʒ����� üũ �õ� ��
							else if (m_note[i].top > hitbar_rt.bottom + 20) {
								// miss���� ó��
								scoreArray[count_data] = 1;
								count_data++;
								combo_current = 0;
								J_checker[m_note[i].pos] = 1;
								SetEvent(hEvent);
								//
							}
						}
					}
				}
			}
		}
		return TRUE;

	case WM_KEYUP:
		for (int i = 0; i < max_col; i++) {
			if ((TCHAR)wParam == using_key[i]) {
				//�ֱ� ���� Ű �ʱ�ȭ
				hit_checker[i] = FALSE;
				J_checker[i] = 0;
				//
			}
		}
		return TRUE;

	case WM_CTLCOLORDLG:		// Dialog ���� �Ͼ��! 
		SetEvent(hEvent);		// �ش� �޼����� Dialog�� Create�� �� Stack���� �����Ƿ�, Create�� �����带 ���� ��������, �ǹ̰� ����
		return (INT_PTR)GetStockObject(WHITE_BRUSH);

	case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);
		PaintTheBase(hDlg);
		EndPaint(hDlg, &ps);
		return TRUE;

	case WM_CLOSE:
		if (MessageBox(hDlg, TEXT("������ �����ұ��?"), TEXT("Ȯ��"), MB_YESNO) == IDYES) {
			EnableWindow(BT_KeyGame, TRUE);
			CloseHandle(hMutex);
			EndDialog(hDlg, FALSE);
			break;
		}
		else
			return TRUE;
	}
	return FALSE;
}
//

// ������ ������
DWORD WINAPI Score_control_Thread(LPVOID Param) {
	HDC hdc;
	HFONT hFont, OldFont;
	RECT r;
	
	while (true) {
		PARAMETER *temp = (PARAMETER*)Param;
		TCHAR buf[30];
		TCHAR buf2[30];
		TCHAR buf3[30];
		WaitForSingleObject(hEvent, INFINITE);			// Event üũ
		WaitForSingleObject(hMutex, INFINITE);			// non-signaled
		int count = 0;
		for (int i = 0; i < count_data; i++) {
			if (scoreArray[i] == temp->order)
				count++;
		}
		ReleaseMutex(hMutex);						//�ٽ� signaled	

		// �޺��κ��� �ʱ�ȭ �� ��, �ڸ��� �κп� ������ ������ �ܻ��� �����Ƿ�
		// �޺��κ� ��ü �ٽ� �׸���
		SetRect(&r, rt.right - temp->x, rt.top + 150, rt.right, rt.top + 200);
		InvalidateRect(hWndDlg, &r, TRUE);
		UpdateWindow(hWndDlg);
		//

		hdc = GetDC(hWndDlg);
		wsprintf(buf, TEXT("COMBO : %d"), combo_current, lstrlen(buf));
		TextOut(hdc, rt.right - temp->x, rt.top + 150, buf, lstrlen(buf));
		wsprintf(buf2, TEXT("MAX COMBO : %d"), combo_max, lstrlen(buf2));
		TextOut(hdc, rt.right - temp->x, rt.top + 180, buf2, lstrlen(buf2));
		if (temp->order == 1) count /= 10;
		wsprintf(buf3, TEXT("%s : %d"), temp->NAME, count, lstrlen(buf3));
		TextOut(hdc, rt.right - temp->x, rt.top + temp->y, buf3, lstrlen(buf3));

		ReleaseDC(hWndDlg, hdc);
		ResetEvent(hEvent);
	}
	return 0;
}
//

// ����Ŭ����	(�޼��� ����ä��)
LRESULT CALLBACK Message_Tracer_Proc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	switch (iMessage) {
	case WM_KEYDOWN:
		switch (wParam) {
			// �����̽� Ű�� ������ �� PAUSE�ǵ���
		case VK_SPACE:
			if (!isPaused) {
				// Ÿ�̸� ����
				KillTimer(hWnd, 1);
				TCHAR buf[10];
				hdc = GetDC(hWnd);
				PaintTheBase(hWnd);
				SetBkMode(hdc, TRANSPARENT);
				wsprintf(buf, TEXT("[ Pause ]"));
				TextOut(hdc, KEY_WIDTH / 2 - lstrlen(buf) * 3, KEY_HEIGHT / (2.5), buf, lstrlen(buf));
				ReleaseDC(hWnd, hdc);
				isPaused = TRUE;
				//
			}
			else {
				// Ÿ�̸� ����
				SetTimer(hWnd, 1, game_fps, NULL);
				isPaused = FALSE;
				//
			}
			break;
		}
		break;
		//
	}
	return CallWindowProc(OldProc, hWnd, iMessage, wParam, lParam);
}
//

void PaintTheBase(HWND hWnd) {
	HDC				hdc,
						MemDC;
	RECT			r;
	HBITMAP		MyBitMap,
						OldBitMap;
	HBRUSH		MyBrush;
	TCHAR			buf[4];

	if (!isPaused) {
		hdc = GetDC(hWnd);
		MemDC = CreateCompatibleDC(hdc);
		MyBitMap = CreateCompatibleBitmap(hdc, KEY_WIDTH, KEY_HEIGHT);
		OldBitMap = (HBITMAP)SelectObject(MemDC, MyBitMap);
		// bitmap�� �׷���, �� ���� �ű�� ��� ���!!

		MyBrush = CreateSolidBrush(KEY_BASECOLOR);		// ���� ��ĥ
		FillRect(MemDC, &base_rt, MyBrush);						
		DeleteObject(SelectObject(MemDC, MyBrush));

		// Hit ���̸�, Hit Zone ���
		for (int i = 0; i < max_col; i++) {
			if (hit_checker[i] == TRUE) {
				SetRect(&r, i*KEY_NOTE_WID, ENDING_Y(2.5), (i + 1)*KEY_NOTE_WID, ENDING_Y(1.5) + 3);
				MyBrush = CreateSolidBrush(KEY_HITCOLOR);
				FillRect(MemDC, &r, MyBrush);
				DeleteObject(SelectObject(MemDC, MyBrush));
			}
		}
		//

		// ��Ʈ ���
		for (int i = 0; i < max_row; i++) {
			if (m_note[i].pos == max_col)
				continue;
			SetRect(&r, m_note[i].pos * KEY_NOTE_WID + 3, m_note[i].top, (m_note[i].pos + 1)*KEY_NOTE_WID - 3, m_note[i].bottom);
			MyBrush = CreateSolidBrush(KEY_NOTECOLOR);
			SetBkMode(hdc, TRANSPARENT);
			FillRect(MemDC, &r, MyBrush);
			DeleteObject(SelectObject(MemDC, MyBrush));
		}
		//

		// Hit Bar ���
		MyBrush = CreateSolidBrush(KEY_HITBARCOLOR);
		FillRect(MemDC, &hitbar_rt, MyBrush);
		DeleteObject(SelectObject(MemDC, MyBrush));
		//

		SetTextColor(MemDC, RGB(255, 255, 255));
		SetBkMode(MemDC, TRANSPARENT);	//������ ����(�߰����)

		// Ű �ȳ�
		for (int i = 0; i < max_col; i++) {
			wsprintf(buf, TEXT("%c"), using_key[i]);
			TextOut(MemDC, (i + 1)*KEY_NOTE_WID - (KEY_NOTE_WID / 2) - 5, ENDING_Y(1), buf, 1);
		}
		//

		// ������ �ȳ�
		for (int i = 0; i < max_col; i++) {
			if (J_checker[i] == 1) {
				SetTextColor(MemDC, RGB(250, 80, 80));
				TextOut(MemDC, (i + 1)*KEY_NOTE_WID - (KEY_NOTE_WID / 2) - 17, ENDING_Y(1.7), TEXT("Miss"), 4);
			}
			else if (J_checker[i] == 2) {
				SetTextColor(MemDC, RGB(250, 80, 250));
				TextOut(MemDC, (i + 1)*KEY_NOTE_WID - (KEY_NOTE_WID / 2) - 17, ENDING_Y(1.7), TEXT("Bad"), 3);
			}
			else if (J_checker[i] == 3) {
				SetTextColor(MemDC, RGB(220, 220, 255));
				TextOut(MemDC, (i + 1)*KEY_NOTE_WID - (KEY_NOTE_WID / 2) - 17, ENDING_Y(1.7), TEXT("Good"), 4);
			}
		}
		//

		BitBlt(hdc, 0, 0, KEY_WIDTH, KEY_HEIGHT, MemDC, 0, 0, SRCCOPY);	// ������ ��Ʈ�� ���

		SelectObject(MemDC, OldBitMap);
		DeleteObject(MyBitMap);
		DeleteDC(MemDC);
		ReleaseDC(hWnd, hdc);
	}
}

void noteChanger(int order) {
	m_note[order].top = KEY_NOTE_HEIGHT * (-1) - move_step;	// �ƴ� ���, ��Ʈ �ʱ�ȭ
	m_note[order].bottom = move_step;
	m_note[order].pos = rand() % max_col;
}