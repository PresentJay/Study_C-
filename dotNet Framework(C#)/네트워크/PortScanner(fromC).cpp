#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFSIZE 512


int main(int argc, char* argv[])
{
	if (argc != 4) {
		printf("Usage : %s <IP> <min int> <max int>\n", argv[0]);
		exit(1);
	}

	printf("포트번호 %s부터 %s에 대한 탐색을 시작합니다\n%t: 탐색IP>%s", argv[2],argv[3], argv[1]);

	// 윈속 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return -1;

	// connect()
	for (int i = atoi(argv[2]); i <= atoi(argv[3]); i++) {
		SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
		SOCKADDR_IN serveraddr;
		ZeroMemory(&serveraddr, sizeof(serveraddr));
		serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
		serveraddr.sin_family = AF_INET;
		serveraddr.sin_port = htons(i);
		
		unsigned long iMode = 1;
		int iResult = ioctlsocket(sock, FIONBIO, &iMode);
		if (connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr)) == false) {
			printf("\n%d : Closed Port", i);
		}

		iMode = 0;
		iResult = ioctlsocket(sock, FIONBIO, &iMode);

		fd_set Write, Err;
		FD_ZERO(&Write);
		FD_ZERO(&Err);
		FD_SET(sock, &Write);
		FD_SET(sock, &Err);
		TIMEVAL timeout;
		timeout.tv_sec = 0.5;
		timeout.tv_usec = 0;
		select(0, NULL, &Write, &Err, &timeout);

		if (FD_ISSET(sock, &Write))
			printf("\n%d : Listening TCP Port", i);
		else
			printf("\n%d : Timeout!", i);
		
		closesocket(sock);
	}
	printf("\n탐색이 종료되었습니다\n");
	// 윈속 종료
	WSACleanup();
	return 0;
}