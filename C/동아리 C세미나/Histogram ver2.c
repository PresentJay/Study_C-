#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

int main() {
	char str[101];
	char answer[10];
	int version;
	// 메뉴선택 알고리즘 + 문자열 알고리즘 + for문
	do {
		//answer[0] = NULL;	// 문자열 재사용 시, 오동작을 방지하기 위한 초기화방법 (배열 첫값에 null문자('\0')를 넣는다)
		memset(str, NULL, 100);
		memset(answer, NULL, 10);
		version = 0;
		do {	// 무한루프 메뉴선택 (do로 먼저 선택, while (올바른 메뉴 선택할때까지)
			system("cls");		// console 내용 초기화 함수 (Windows.h 헤더 필요)
			printf("히스토그램 ver2\n*\t*\t*\n\n\n\t영어 소문자로 된 문장(100자 이내)을 작성하고 [Enter]");
			printf("\n\t[GOOD] : 문장 사이에 공백(space)이 없을 경우 정상 출력");
			printf("\n\t[BEST] : 문장 사이에 공백(space)이 있어도 정상 출력\n\n");
			printf("\n\t어떤 버전의 히스토그램ver2을 시작할까요?\n\t(대소문자 상관없이 good or best)\n\n\t입력>> ");
			scanf("%s", &answer);
			fflush(stdin); 		// 문자열 버퍼에 영향을 주는 space, tab, enter를 포함한 입력 시 오류를 방지하기 위한, "버퍼 비우기 함수"

			if (strcmp(_strupr(answer), "GOOD") == 0)		// 문자열 비교 함수는 strcmp(비교1, 비교2 ; 같으면 0), 문자열 대문자화 함수는 strupr(문자열)
				version = 1;												// 문자열 관련 함수는 string.h 헤더 필요
			else if (strcmp(_strupr(answer), "BEST") == 0)
				version = 2;
			else if (strcmp(_strupr(answer), "EXIT") == 0)		// 무한루프 메뉴선택에는 종료기능어를 넣어주면 좋다!
				return 0;
		} while (version != 1 && version != 2);

		//str[0] = NULL;
		printf("%s\n", str);
		scanf("%*c");    // 문자를 읽긴하되 저장하진않음. \n읽어서 버리겠다는거

		printf("\t문장 입력(100자 이내) >> ");
		version == 1 ? scanf("%s", &str) : fgets(str, 100, stdin); // 단일단순 조건문(if~else인데 내부 코드이 1줄씩일경우)
														//scanf("%[^\n]", &str);  // 같은 기능
														//fflush(stdin);  // scanf쓰면  fflush!

														//gets(str);  // 같은 기능
		_strlwr(str);		// 문자열 오입력을 방지하기 위해, 간단하게 소문자로 바꾸는 함수 부여
		system("cls");	// 화면 초기화 후, 히스토그램 출력
		printf("\n\n\t입력한 문장 >> %s\n\n", str);

		// Histogram Algorithm (ver 2)-------
		for (int i = 'a'; i <= 'z'; i++) {
			int count = 0;
			for (int j = 0; j < 100; j++)
				if (str[j] == i) count++;
			if (count > 0) {
				printf("\t[%c] : ", i);
				for (int k = 0; k < count; k++)
					printf("*");
				printf("\n");
			}
		}
		// -------------------------------------

		rewind(stdin);	// 입력 버퍼 초기화 (추천)
		do {
			printf("\n\n\tQ> 프로그램을 다시 실행할까요? (yes or no)\n\t입력 >> ");
			scanf("%s", &answer);
			_strlwr(answer);
		} while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0);
	} while (strcmp(answer, "no") != 0);
	printf("\n\n\n");
	return 0;
}