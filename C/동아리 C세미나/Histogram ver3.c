#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define STRLEN 400

char* ReplayQ();
int getArrMaxNext(int* src, int srcScale, int exception);

int main() {
	char str[STRLEN];
	char currentCh;
	char answer[10];
	int alphaCount[26];
	int version;
	int tmpMax;
	// 메뉴선택 알고리즘 + 문자열 알고리즘 + for문 + 배열
	do {
		//answer[0] = NULL;	// 문자열 재사용 시, 오동작을 방지하기 위한 초기화방법 (배열 첫값에 null문자('\0')를 넣는다)
		memset(str, '\0', sizeof(str));		// 1번째 인자의 문자열에, 2번째 인자 값을, 3번째 인자 크기만큼 할당
		memset(answer, '\0', sizeof(answer));
		memset(alphaCount, 0, sizeof(alphaCount));
		version = 0;
		
		do {	// 무한루프 메뉴선택 (do로 먼저 선택, while (올바른 메뉴 선택할때까지)
			system("cls");		// console 내용 초기화 함수 (Windows.h 헤더 필요)
			printf("히스토그램 ver3\n*\t*\t*\n\n\n\t영어(대,소문자 상관없이) 입력하고, 종료할 때 [Enter]\n");
			printf("\n\t알파벳별 개수를 나타내는 배열(크기 26)과,\n\t#include <Windows.h>를 하면 사용할 수 있는 system(\"cls\") : 콘솔창 초기화함수를 가지고 완성!\n");
			printf("\n\t[NORMAL] : 알파벳을 누를 때마다, 지금까지 입력한 문자열과 함께 히스토그램(가로)을 출력");
			printf("\n\t[HARD] : 알파벳을 누를 때마다, 지금까지 입력한 문자열과 함께 문자열 길이를 출력하고,\n\t히스토그램(가로)을 카운트 많은 순서로 출력\n\n");
			printf("\n\t어떤 버전의 히스토그램ver3을 시작할까요?\n\t(대소문자 상관없이 normal or hard)\n\n\t입력(exit 입력 시 종료)>> ");
			scanf("%s", &answer);
			fflush(stdin); 		// 문자열 버퍼에 영향을 주는 space, tab, enter를 포함한 입력 시 오류를 방지하기 위한, "버퍼 비우기 함수"

			if (strcmp(_strupr(answer), "NORMAL") == 0)		// 문자열 비교 함수는 strcmp(비교1, 비교2 ; 같으면 0), 문자열 대문자화 함수는 strupr(문자열)
				version = 1;												// 문자열 관련 함수는 string.h 헤더 필요
			else if (strcmp(_strupr(answer), "HARD") == 0)
				version = 2;
			else if (strcmp(_strupr(answer), "EXIT") == 0)		// 무한루프 메뉴선택에는 종료기능어를 넣어주면 좋다!
				return 0;
		} while (version != 1 && version != 2);
		rewind(stdin);

		do {
			system("cls");	// 화면 초기화 후, 입력시작
			tmpMax = STRLEN;
			printf("\n\n\t입력한 문장 >>\t");
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] == '\0')
					break;
				printf("%c", str[i]);
				if (i % 80 == 0 && i != 0)	printf("\n\t\t\t");
			}
			printf(":\n\t*\t*\t*\t*\t*\n\t");
			if (version == 1) {
				for (int i = 'a'; i <= 'z'; i++) {
					if (alphaCount[i - 'a'] > 0) {
						printf("[%c] : ", i);
						for (int j = 0; j < alphaCount[i - 'a']; j++)
							printf("*");
						printf("\n\t");
					}
				}
			}
			else if (version == 2) {
				printf("입력한 문장 길이 = %d\n\n\t", strlen(str));
				while (tmpMax > 0) {
					
					tmpMax = getArrMaxNext(alphaCount, 26, tmpMax);
					if (tmpMax == 0) continue;
					for (int i = 'a'; i <= 'z'; i++){
						if (alphaCount[i-'a'] == tmpMax) {
							printf("[%c] : ", i);
							for (int j = 0; j < alphaCount[i - 'a']; j++)
								printf("*");
							printf("(%d)\n\t", alphaCount[i-'a']);
						}
					}
				}
			}
			printf("\n*\t*\t*\t*\t*\n\t입력 (Enter키 = 종료) >>");
			currentCh = _getch();		// 즉시 입력 함수 (one character 단위는 표준 입출력(stdio)이 아님! : conio.h 헤더 사용)
			rewind(stdin);
			if (currentCh >= 'A' && currentCh <= 'z') {
				if (currentCh < 'a') // 대문자 입력시 치환
					alphaCount[tolower(currentCh) - 'a']++;
				else
					alphaCount[currentCh - 'a']++;
				str[strlen(str)] = currentCh;
				
			}
			else if (currentCh == '\r') {
				printf("[Enter]키를 입력하셨습니다.\n\t");
				break;
			}
			else if (currentCh == ' ' || currentCh == '.' || currentCh == ',' || currentCh == '\'' || currentCh == '\"' || (currentCh >= '0' && currentCh <= '9'))  // 부가적인 기능이므로 따로 뺌
				str[strlen(str)] = currentCh;
			else
				continue;
			printf("%c", currentCh);

			printf("\n\n\t");
		} while (strlen(str) < 400);
		if (strlen(str) > 399) printf("입력 문장의 길이가 400자를 초과하여 종료되었습니다.\n\t%s", str);

		rewind(stdin);	// 입력 버퍼 초기화 (추천)
		strcpy(answer, ReplayQ());  // 함수 방법으로도 메뉴를 받을 수 있다~!
	} while (strcmp(answer, "no") != 0);
	printf("\n\n\n");
	return 0;
}

char* ReplayQ() {
	char answer[10];
	do {
		printf("\n\n\tQ> 프로그램을 다시 실행할까요? (yes or no)\n\t입력 >> ");
		scanf("%s", &answer);
		_strlwr(answer);
	} while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0);
	return answer;
}

int getArrMaxNext(int* src, int srcScale, int exception) {
	int tmpMax = 0;
	for (int i = 0; i <= srcScale; i++)
		if (src[i] < exception)
			tmpMax = MAX(tmpMax, src[i]);

	return tmpMax;
}