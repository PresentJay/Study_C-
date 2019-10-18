#include <stdio.h>
#include <conio.h>
void main() {
	int A, B, selection_int;
	char selection_char, tmpchar[2];
	printf("1. 정수 두 개를 입력하세요(space로 구분)\n >> ");
	scanf("%d %d", &A, &B);
	do {
		printf("2. 몇 개의 연산을 하시겠습니까? (0~4사이 입력) >> ");
		scanf("%d", &selection_int);
	} while (selection_int > 5 || selection_int<0);

	for (int i = 0; i < selection_int; i++) {
		switch (i) {
		case 0:
			do {
				printf("덧셈 하시겠습니까? (y/n) >> ");
				scanf(" %c", &selection_char);
			} while (selection_char != 'y' && selection_char != 'n');
			if (selection_char == 'y')
				printf("덧셈 결과는 %d입니다.\n", A + B);
			break;

		case 1:
			do {
				printf("뺄셈 하시겠습니까? (y/n) >> ");
				scanf(" %c", &selection_char);
			} while (selection_char != 'y' && selection_char != 'n');
			if (selection_char == 'y')
				printf("뺄셈 결과는 %d입니다.\n", A - B);
			break;

		case 2:
			do {
				printf("곱셈 하시겠습니까? (y/n) >> ");
				scanf(" %c", &selection_char);
			} while (selection_char != 'y' && selection_char != 'n');
			if (selection_char == 'y')
				printf("곱셈 결과는 %d입니다.\n", A * B);
			break;

		case 3:
			do {
				printf("나눗셈 하시겠습니까? (y/n) >> ");
				scanf(" %c", &selection_char);
			} while (selection_char != 'y' && selection_char != 'n');
			if (selection_char == 'y')
				printf("나눗셈 결과는 %d입니다.\n", A / B);
			break;
		}
	}

	printf("\n\n");
}