#include <windows.h>
#include <stdio.h>
#include <time.h>

int irand(void);
void isrand(unsigned int);
VOID ErrorExit(LPTSTR);

DWORD dwTlsIndex;

DWORD WINAPI MyThread(LPVOID arg)
{
	//LPVOID lpvData;

	// �õ� ����
	//isrand((unsigned int)time(NULL));
	isrand((unsigned int)time(NULL)); 

	// ������ 5�� ����
	for(int i=0; i<5; i++)
	{
		printf("TID: %d( %d )\n", GetCurrentThreadId(), irand()%1000);
	}

	// �Ҵ��� ���� ����
	/*lpvData = TlsGetValue(dwTlsIndex);
	if (lpvData != 0)
		LocalFree((HLOCAL)lpvData);*/

    return 0;
}


int main()
{
	if ((dwTlsIndex = TlsAlloc()) == -1)
		ErrorExit("TlsAlloc failed");
    // ù ��° ������ ����
    DWORD ThreadId1;
    HANDLE hThread1 = CreateThread(NULL, 0, MyThread, 
        NULL, 0, &ThreadId1);
    if(hThread1 == NULL) return -1;

	Sleep(1000);

    // �� ��° ������ ����
    DWORD ThreadId2;
    HANDLE hThread2 = CreateThread(NULL, 0, MyThread, 
		NULL, 0, &ThreadId2);
    if(hThread2 == NULL) return -1;

	HANDLE h[2];
	h[0] = hThread1;
	h[1] = hThread2;
	DWORD dw = WaitForMultipleObjects(2,h,TRUE,INFINITE);
    return 0;
}

int irand()
{
	int* seed;		// �õ带 �ڽŸ��� �������� ����.

	// ���� �������� TLS�ȿ� �ִ� �����Ҵ��� ������ �ּҸ� �޾ƿ´�.
	seed = (int*)TlsGetValue(dwTlsIndex);
	if ((seed == 0) && (GetLastError() != 0))
		ErrorExit("TlsGetValue error");

	*seed = *seed * 1103515245 + 12345;
	return (unsigned int)(*seed / 65536) % RAND_MAX + 1;
}

void isrand(unsigned int seed)
{
	LPVOID lpvData;
	
	// 4����Ʈ ũ���� ������ �Ҵ��Ͽ� TLS�� �ִ´�.
	lpvData = (LPVOID)LocalAlloc(LPTR, 4);
	if (!TlsSetValue(dwTlsIndex, lpvData))
		ErrorExit("TlsSetValue error");

	*(int*)lpvData = seed;
}

VOID ErrorExit(LPTSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);
	ExitProcess(0);
}