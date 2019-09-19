#include <windows.h>
#include "resource.h"

// 20143174 정현재, 2018년도 2학기 Windows Application Programming Interface,
// Win32 API의 설계 프로젝트, KeyBoard Game with Thread, Subclassing 입니다.

// 자주 쓸 정보 & 명확히 보여야 할 정보 정의
#define		PROJECT_NAME		TEXT("20143174 - 정현재 - 화요일 - 개인프로젝트")
#define		MENU_STATUS			NULL
#define		KEY_WIDTH				300																					// 게임 화면의 너비
#define		KEY_HEIGHT			600																						// 게임 화면의 높이
#define		KEY_NOTE_WID		KEY_WIDTH / max_col														// 노트의 평균 너비
#define		KEY_NOTE_HEIGHT	KEY_HEIGHT / (max_row-2)												// 노트의 평균 높이
#define		ENDING_Y(i)				KEY_HEIGHT - KEY_NOTE_HEIGHT * i								// 게임화면 하단으로부터의 일정한 높이계산
#define		KEY_BASECOLOR		RGB(200, 200, 200)										// 게임화면 바탕색
#define		KEY_HITBARCOLOR	RGB(220, 150, 40)											// 판정선 색
#define		KEY_HITCOLOR		RGB(220, 150, 150)										// 판정범위 색
#define		KEY_NOTECOLOR	RGB(100, 100, 150)											// 노트 색
//

// 구조체 선언부
struct NoteData { int top, bottom, pos; };							// 높낮이값과 col위치값을 가지는 노트 구조체
typedef struct _Parameter { int x, y, order; TCHAR NAME[6]; } PARAMETER;
//

// 전역변수 선언부
int					scoreArray[10000],
					count_data = 0;
HINSTANCE	g_hInst;
HWND			hWndDlg;
LPCTSTR		lpszClass = PROJECT_NAME;
WNDPROC	OldProc;			// 서브클래싱
HANDLE		hMutex;			// 뮤텍스 동기화
HANDLE		hEvent;				// 이벤트 동기화
HWND			BT_KeyGame;	// KeyGame을 실행할 버튼
NoteData		*m_note;
PARAMETER Param[3] = { { 240, 280, 3, TEXT("Good") },{ 240, 310, 2, TEXT("Bad") },{ 240, 340, 1, TEXT("Miss") } };	// 판정 파라미터
RECT			base_rt,				// 게임 화면 rect
					hitbar_rt;			// hit_bar rect
RECT			rt;						// Dialog 전체화면 rect
int					max_col = 6,			// col 갯수
					max_row = 11,		// row 갯수
					move_step = 5,		// 높이 이동 단위
					game_fps = 30;		// 화면 갱신 단위 (작을수록 빠름 / 1000(1초) 계산)
int				combo_current = 0,
				combo_max = 0;
TCHAR		using_key[6] = { 'S', 'D', 'F', 'J', 'K', 'L' };
bool			hit_checker[6] = { FALSE, };		// FALSE : non-hit , TRUE : hit
int				J_checker[6] = { 0, };					// 0 : non-judgement,  1: miss,  2: bad,  3: good
bool			isPaused = FALSE;
//

// 함수선언부
LRESULT	CALLBACK	Message_Tracer_Proc(HWND, UINT, WPARAM, LPARAM);	// 서브클래싱 함수
DWORD	WINAPI		Score_control_Thread(LPVOID);
LRESULT	CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);						// 메인함수
BOOL		CALLBACK	KeyGame_DlgProc(HWND, UINT, WPARAM, LPARAM);		// 게임 Dialog 함수
void								PaintTheBase(HWND);															// 게임화면 출력함수
void								noteChanger(int);																	// col별 노트초기화함수
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
		case 0:	// 게임 버튼 클릭 시
			EnableWindow(BT_KeyGame, FALSE);		// 재실행되지 않도록 버튼 비활성화
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
		hMutex = CreateMutex(NULL, FALSE, NULL);												// 뮤텍스 동기화 생성
		hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);													// 이벤트 생성
		SetRect(&hitbar_rt, 0, ENDING_Y(1.5), KEY_WIDTH, ENDING_Y(1.5) + 3);		// 힛바 RECT 설정
		SetRect(&base_rt, 0, 0, KEY_WIDTH, KEY_HEIGHT);										// 게임 화면 RECT 설정
		GetClientRect(hDlg, &rt);																				// 게임 Dialog RECT 설정
		SetTimer(hDlg, 1, game_fps, NULL);					// 타이머 설정
		hWndDlg = hDlg;

		m_note = new NoteData[max_row];				// row 수만큼 (노트 크기 등 다양하게 바뀜) NoteData 동적할당
		// 시작 노트값 생성
		m_note[0] = { KEY_NOTE_HEIGHT*(-1), 0, rand() % max_col };
		for (int i = 1; i < max_row; i++)
			m_note[i] = { m_note[i - 1].top - KEY_NOTE_HEIGHT, m_note[i - 1].bottom - KEY_NOTE_HEIGHT, rand() % max_col };
		//

		// 스레드 생성
		for (int i = 0; i < 3; i++)
			CloseHandle(CreateThread(NULL, 0, Score_control_Thread, &Param[i], 0, &ThreadID));
		

		OldProc = (WNDPROC)SetWindowLongPtr(hDlg, GWLP_WNDPROC, (LONG_PTR)Message_Tracer_Proc);		// 서브클래싱
		
		
		return TRUE;

	case WM_TIMER:		// 노트 움직임의 비주얼적인 부분을 담당
sjlkdf		for (int i = 0; i < max_row; i++) {
			if (m_note[i].top < KEY_HEIGHT) {					// 노트가 키게임 화면 보다 높이 있을때만 이동 
				if (m_note[i].bottom >= hitbar_rt.top + 3 && hit_checker[m_note[i].pos] == TRUE) {	// 노트가 힛바 범위 안쪽 ( 3의 여유 추가, 판정범위 안 ) 이면서, 키가 눌러지고 있는 경우
					// 노트 하강 처리 타입 : HitBar에 스며드는 모양
					if (m_note[i].top + move_step < hitbar_rt.top) {
						m_note[i].top += move_step;
						m_note[i].bottom = hitbar_rt.top;
					}
					else { //하강완료시, 해당 col 노트 초기화
						noteChanger(i);
						J_checker[m_note[i].pos] = 0;
					}
				}
				else {			//  노트가 힛바 범위 바깥쪽이고, 계속해서 화면 끝까지 도달하려할 때
					if (m_note[i].bottom > hitbar_rt.bottom + 20 && hit_checker[m_note[i].pos] == FALSE) {
						// miss관련 처리
						combo_current = 0;
						scoreArray[count_data] = 1;
						count_data++;
						J_checker[m_note[i].pos] = 1;
						SetEvent(hEvent);
						//
					}
					// 노트 하강 처리 타입 : 일반 (바닥에 스며드는 모양)
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
			// 화면 변화 죽시 적용

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
						if (m_note[i].bottom >= ENDING_Y(2.5)) {		// 범위 안에서 체크 시도 시
							// 최소 판정선 위에서 감지될 경우
							if (m_note[i].bottom < hitbar_rt.bottom + 20) {
								// 먼저 누른 것이 없는 상태의 경우
								if (J_checker[m_note[i].pos] == 0) {
									// Good 범위 위에서 처음 bottom이 진입할 때
									if (m_note[i].bottom < hitbar_rt.top - 20) {
										// bad 관련 처리
										scoreArray[count_data] = 2;
										count_data++;
										J_checker[m_note[i].pos] = 2;
										SetEvent(hEvent);
										//
									}
									// Good 범위 안에서 처음 bottom이 진입할 때
									else {
										// good 관련 처리
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
								// 이전 상태가 miss 였을 경우
								else if (J_checker[m_note[i].pos] == 1) {
									// bad 관련 처리
									scoreArray[count_data] = 2;
									count_data++;
									J_checker[m_note[i].pos] = 2;
									SetEvent(hEvent);
									//
								}
								// 이전 상태가 bad 였을 경우
								else if (J_checker[m_note[i].pos] == 2) {
									// bad 관련 처리
									scoreArray[count_data] = 2;
									count_data++;
									J_checker[m_note[i].pos] = 2;
									SetEvent(hEvent);
									//
								}
								else if (J_checker[m_note[i].pos] == 3 && m_note[i].pos == i) {	// 이전 상태가 good 이었을 경우
																								// good 관련 처리
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
							// 최소 판정선 아래에서 체크 시도 시
							else if (m_note[i].top > hitbar_rt.bottom + 20) {
								// miss관련 처리
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
				//최근 누른 키 초기화
				hit_checker[i] = FALSE;
				J_checker[i] = 0;
				//
			}
		}
		return TRUE;

	case WM_CTLCOLORDLG:		// Dialog 배경색 하얗게! 
		SetEvent(hEvent);		// 해당 메세지는 Dialog가 Create된 후 Stack으로 들어오므로, Create에 스레드를 먼저 돌려봐야, 의미가 없음
		return (INT_PTR)GetStockObject(WHITE_BRUSH);

	case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);
		PaintTheBase(hDlg);
		EndPaint(hDlg, &ps);
		return TRUE;

	case WM_CLOSE:
		if (MessageBox(hDlg, TEXT("게임을 종료할까요?"), TEXT("확인"), MB_YESNO) == IDYES) {
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

// 스레드 구현부
DWORD WINAPI Score_control_Thread(LPVOID Param) {
	HDC hdc;
	HFONT hFont, OldFont;
	RECT r;
	
	while (true) {
		PARAMETER *temp = (PARAMETER*)Param;
		TCHAR buf[30];
		TCHAR buf2[30];
		TCHAR buf3[30];
		WaitForSingleObject(hEvent, INFINITE);			// Event 체크
		WaitForSingleObject(hMutex, INFINITE);			// non-signaled
		int count = 0;
		for (int i = 0; i < count_data; i++) {
			if (scoreArray[i] == temp->order)
				count++;
		}
		ReleaseMutex(hMutex);						//다시 signaled	

		// 콤보부분이 초기화 될 때, 자릿수 부분에 문제가 있으면 잔상이 남으므로
		// 콤보부분 전체 다시 그리기
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

// 서브클래싱	(메세지 가로채기)
LRESULT CALLBACK Message_Tracer_Proc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	switch (iMessage) {
	case WM_KEYDOWN:
		switch (wParam) {
			// 스페이스 키를 눌렀을 때 PAUSE되도록
		case VK_SPACE:
			if (!isPaused) {
				// 타이머 삭제
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
				// 타이머 설정
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
		// bitmap에 그려서, 한 번에 옮기는 방식 사용!!

		MyBrush = CreateSolidBrush(KEY_BASECOLOR);		// 배경색 색칠
		FillRect(MemDC, &base_rt, MyBrush);						
		DeleteObject(SelectObject(MemDC, MyBrush));

		// Hit 중이면, Hit Zone 출력
		for (int i = 0; i < max_col; i++) {
			if (hit_checker[i] == TRUE) {
				SetRect(&r, i*KEY_NOTE_WID, ENDING_Y(2.5), (i + 1)*KEY_NOTE_WID, ENDING_Y(1.5) + 3);
				MyBrush = CreateSolidBrush(KEY_HITCOLOR);
				FillRect(MemDC, &r, MyBrush);
				DeleteObject(SelectObject(MemDC, MyBrush));
			}
		}
		//

		// 노트 출력
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

		// Hit Bar 출력
		MyBrush = CreateSolidBrush(KEY_HITBARCOLOR);
		FillRect(MemDC, &hitbar_rt, MyBrush);
		DeleteObject(SelectObject(MemDC, MyBrush));
		//

		SetTextColor(MemDC, RGB(255, 255, 255));
		SetBkMode(MemDC, TRANSPARENT);	//투명배경 글자(중간고사)

		// 키 안내
		for (int i = 0; i < max_col; i++) {
			wsprintf(buf, TEXT("%c"), using_key[i]);
			TextOut(MemDC, (i + 1)*KEY_NOTE_WID - (KEY_NOTE_WID / 2) - 5, ENDING_Y(1), buf, 1);
		}
		//

		// 판정값 안내
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

		BitBlt(hdc, 0, 0, KEY_WIDTH, KEY_HEIGHT, MemDC, 0, 0, SRCCOPY);	// 저장한 비트맵 출력

		SelectObject(MemDC, OldBitMap);
		DeleteObject(MyBitMap);
		DeleteDC(MemDC);
		ReleaseDC(hWnd, hdc);
	}
}

void noteChanger(int order) {
	m_note[order].top = KEY_NOTE_HEIGHT * (-1) - move_step;	// 아닌 경우, 노트 초기화
	m_note[order].bottom = move_step;
	m_note[order].pos = rand() % max_col;
}