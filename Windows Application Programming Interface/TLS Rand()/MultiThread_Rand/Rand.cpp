#include <windows.h>
#include <stdio.h>
#include <time.h>

DWORD dwTlsR;

DWORD WINAPI MyThread(LPVOID arg)
{
	srand(GetCurrentTime());
	for (int i = 0; i < 5; i++)
		printf("TID: %d( %d )\n", GetCurrentThreadId(), rand() % 1000);
	return 0;
}


int main()
{
	// ù ��° ������ ����
	DWORD ThreadId1;
	HANDLE hThread1 = CreateThread(NULL, 0, MyThread,
		(LPVOID)1, 0, &ThreadId1);
	if (hThread1 == NULL) return -1;

	// �� ��° ������ ����
	DWORD ThreadId2;
	HANDLE hThread2 = CreateThread(NULL, 0, MyThread,
		(LPVOID)1, 0, &ThreadId2);
	if (hThread2 == NULL) return -1;

	HANDLE h[2];
	h[0] = hThread1;
	h[1] = hThread2;
	DWORD dw = WaitForMultipleObjects(2, h, TRUE, INFINITE);
	return 0;
}

unsigned int rand(unsigned long int g){
	unsigned long int next = (unsigned long int)TlsGetValue(dwTlsR);
	next = next * 1103515245 + 12345;
	TlsSetValue(dwTlsR, (LPVOID)next);
	return (unsigned int)(next / 65536) % RAND_MAX + 1;
}

void srand(unsigned int seed){
	//�޸� �Ҵ� �� ���� �ð� ȣ���Ͽ� 
	TlsSetValue(dwTlsR, (LPVOID)seed);
}
