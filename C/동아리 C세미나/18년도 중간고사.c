#include <stdio.h>
#include <conio.h>

void first() {
	int cnt = 0, arr[10], num_arr[10], num, num_cnt = 0;

	printf("1. 10���� ���� ������ �Է��Ͽ� �迭�� �ʱ�ȭ�� ��,\n�Էµ� �� �ٸ� ������ �ڷ� num�� �Է��Ͽ� num���� ū �ڷ��� ����\n����� ����ϴ� ���α׷��� �ۼ��غ���.\n");
	do {
		printf("%d��° ���� : ", cnt + 1);
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
	printf("%d���� ū ������ %d���̸�, �ش� �ڷ�� ����� ", num, num_cnt);
	do {
		if (cnt + 1 != num_cnt)
			printf("%d, ", num_arr[cnt]);
		else
			printf("%d", num_arr[cnt]);
		cnt++;
	} while (cnt != num_cnt);
	printf("�Դϴ�.\n\n");
	return 0;
}

void second() {
	int input;
	do {
		printf("3�̻� Ȧ���� �Է� >> ");
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
	
	// �ǽð� �Է� ����
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
	printf("(%d�ܾ�)\n\n", parCnt);
	

	/* �Ѳ����� �Է� ���� 
	char input, result[200];
	int isUpper = 0, parCnt = 1, index_result = 0;
	printf("�Է� : ");
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
	printf("��� : %s(%d�ܾ�)\n\n", result, parCnt);*/
	return 0;
}

void fourth() {
	char result[21];	//�ڷ� �Է°����� 20����� �ߴµ�, ���ڿ��� NULL���� �������� �ο��Ǿ�� �ϹǷ�, NULL���� ������ 21�� ����
	char input;
	int index_result = 0;
	do {
		input = getch();
		if ((input > 96 && input < 123) || input == 46) {
			if (input == 46) {
				result[index_result] = NULL;
				printf("%c\t<����>\n\n", 46);
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
