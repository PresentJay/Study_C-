#include <stdio.h>
#include <conio.h>

void first() {
	int cnt = 0, arr[10], num_arr[10], num, num_cnt = 0;

	printf("1. 10개의 양의 정수를 입력하여 배열을 초기화한 후,\n입력된 또 다른 정수형 자료 num을 입력하여 num보다 큰 자료의 수와\n목록을 출력하는 프로그램을 작성해보자.\n");
	do {
		printf("%d번째 정수 : ", cnt + 1);
		scanf("%d", &arr[cnt]);
		cnt++;
	} while (cnt != 10);
	printf("num : ");
	scanf("%d", &num);
	do {
		cnt--;
		if (arr[cnt] > num) {
			num_arr[num_cnt] = arr[cnt];
			num_cnt++;
		}
	} while (cnt != 0);
	printf("%d보다 큰 정수는 %d개이며, 해당 자료들 목록은 ", num, num_cnt);
	do {
		if (cnt + 1 != num_cnt)
			printf("%d, ", num_arr[cnt]);
		else
			printf("%d", num_arr[cnt]);
		cnt++;
	} while (cnt != num_cnt);
	printf("입니다.\n\n");
	return 0;
}

void second() {
	int input;
	do {
		printf("3이상 홀수값 입력 >> ");
		scanf("%d", &input);
	} while (input % 2 == 0 && input < 3);

	printf("\n n=%d\n\n", input);

	for (int i = 0; i < input; i++) {
		if (i == 0 || i == input - 1) {
			for (int j = 0; j < input; j++)
				printf("*");
		}
		else {
			for (int j = 0; j < input; j++) {
				if (j == input - i - 1 || j == 0 || j == input - 1)
					printf("*");
				else if (i == j)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n\n");
	return 0;
}

void third() {
	
	// 실시간 입력 버전
	char input;
	int isUpper = 0, parCnt = 1;
	do {
		input = getch();
		if (input == ' ' || (input >= 97 && input <= 122) || input == '.') {
			if (input == ' ') {
				isUpper = 0;
				parCnt++;
				printf(" ");
			}
			else if (input == '.') {
				break;
			}
			else if (isUpper == 0) {
				printf("%c", input - 32);
				isUpper = 1;
			}
			else
				printf("%c", input);
		}
	} while (input != ".");
	printf("(%d단어)\n\n", parCnt);
	

	/* 한꺼번에 입력 버전 
	char input, result[200];
	int isUpper = 0, parCnt = 1, index_result = 0;
	printf("입력 : ");
	do {
		input = getch();
		if (input == 32 || (input >= 97 && input <= 122) || input == 46) {
			if (input == 32) {
				isUpper = 0;
				parCnt++;
				result[index_result] = 32;
				index_result++;
				printf("%c", input);
			}
			else if (input == 46) {
				result[index_result] = 46;
				result[index_result + 1] = NULL;
				index_result += 2;
				printf("%c\n", input);
				break;
			}
			else if (isUpper == 0) {
				result[index_result] = input - 32;
				index_result++;
				isUpper = 1;
				printf("%c", input);
			}
			else {
				result[index_result] = input;
				printf("%c", input);
				index_result++;
			}
		}
	} while (index_result < 199);
	printf("출력 : %s(%d단어)\n\n", result, parCnt);*/
	return 0;
}

void fourth() {
	char result[21];	//자료 입력개수는 20개라고 했는데, 문자열은 NULL값이 마지막에 부여되어야 하므로, NULL값을 제외한 21을 선언
	char input;
	int index_result = 0;
	do {
		input = getch();
		if ((input > 96 && input < 123) || input == 46) {
			if (input == 46) {
				result[index_result] = NULL;
				printf("%c\t<종료>\n\n", 46);
				break;
			}
			else {
				if (result[index_result - 1] + 33 == input)
					result[index_result] = input - 32;
				else {
					for (int i = 0; i < index_result; i++)
						if (result[i] < 91 && result[i] > 63)
							result[i] += 32;
					result[index_result] = input - 32;
				}
				index_result++;
				result[index_result] = NULL;
				printf("%c\t%s\n", input, result);
			}
		}
	} while (index_result < 20);
	return 0;
}

void main() {
//	first();
//	system("pause");
//	system("cls");
//	second();
//	system("pause");
//	system("cls");
//	third();
//	system("pause");
//	system("cls");
	fourth();
	return 0;
}
