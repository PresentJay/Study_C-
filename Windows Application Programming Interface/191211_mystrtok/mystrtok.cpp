#include <windows.h>
#include <stdio.h>

DWORD dwTlsIndex;

char* strtok(char* string) {
	char* data = (char*)TlsGetValue(dwTlsIndex); // TLS의 char 주소값 불러옴
	if (!data) {
		data = (char*)LocalAlloc(LPTR, sizeof(string));
		if (!TlsSetValue(dwTlsIndex, data) || GetLastError()) {
			MessageBox(NULL, "TlsSetValue error", "error", MB_OK);
			ExitProcess(0);
		}
	}

	if (string != NULL) {
		strcpy(data, string);
		return data;
	}
	else
		return NULL;
}

DWORD WINAPI MyThread(LPVOID arg)
{
	char *string = (char *)arg;
	printf("First Thread ID( %d ): %s\n\nTokens:\n", GetCurrentThreadId(), string);
	char *token = strtok(string);
	while (token != NULL)
	{
		printf("Thread ID( %d ): %s\n", GetCurrentThreadId(), token);
		token = strtok(NULL);
	}
	return 0;
}


int main()
{
	char string1[] = "aaabbbcccddd";
	char string2[] = "fffggghhhiii";

	// Initialize the TLS index for this thread. 
	if ((dwTlsIndex = TlsAlloc()) == -1)
		MessageBox(NULL, "TlsAlloc failed", "error", MB_OK);

	// 첫 번째 스레드 생성
	DWORD ThreadId1;
	HANDLE hThread1 = CreateThread(NULL, 0, MyThread,
		(LPVOID)string1, 0, &ThreadId1);
	if (hThread1 == NULL) return -1;

	// 두 번째 스레드 생성
	DWORD ThreadId2;
	HANDLE hThread2 = CreateThread(NULL, 0, MyThread,
		(LPVOID)string2, 0, &ThreadId2);
	if (hThread2 == NULL) return -1;

	HANDLE h[2];
	h[0] = hThread1;
	h[1] = hThread2;
	DWORD dw = WaitForMultipleObjects(2, h, TRUE, INFINITE);
	return 0;
}