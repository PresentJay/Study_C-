#include <stdio.h>
#include <conio.h>
void main() {
	int A, B, selection_int;
	char selection_char, tmpchar[2];
	printf("1. ���� �� ���� �Է��ϼ���(space�� ����)\n >> ");
	scanf("%d %d", &A, &B);
	do {
		printf("2. �� ���� ������ �Ͻðڽ��ϱ�? (0~4���� �Է�) >> ");
		scanf("%d", &selection_int);
	} while (selection_int > 5 || selection_int<0);

	for (int i = 0; i < selection_int; i++) {
		switch (i) {
		case 0:
			do {
				printf("���� �Ͻðڽ��ϱ�? (y/n) >> ");
				scanf(" %c", &selection_char);
			} while (selection_char != 'y' && selection_char != 'n');
			if (selection_char == 'y')
				printf("���� ����� %d�Դϴ�.\n", A + B);
			break;

		case 1:
			do {
				printf("���� �Ͻðڽ��ϱ�? (y/n) >> ");
				scanf(" %c", &selection_char);
			} while (selection_char != 'y' && selection_char != 'n');
			if (selection_char == 'y')
				printf("���� ����� %d�Դϴ�.\n", A - B);
			break;

		case 2:
			do {
				printf("���� �Ͻðڽ��ϱ�? (y/n) >> ");
				scanf(" %c", &selection_char);
			} while (selection_char != 'y' && selection_char != 'n');
			if (selection_char == 'y')
				printf("���� ����� %d�Դϴ�.\n", A * B);
			break;

		case 3:
			do {
				printf("������ �Ͻðڽ��ϱ�? (y/n) >> ");
				scanf(" %c", &selection_char);
			} while (selection_char != 'y' && selection_char != 'n');
			if (selection_char == 'y')
				printf("������ ����� %d�Դϴ�.\n", A / B);
			break;
		}
	}

	printf("\n\n");
}