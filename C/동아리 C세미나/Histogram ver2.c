#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

int main() {
	char str[101];
	char answer[10];
	int version;
	// �޴����� �˰��� + ���ڿ� �˰��� + for��
	do {
		//answer[0] = NULL;	// ���ڿ� ���� ��, �������� �����ϱ� ���� �ʱ�ȭ��� (�迭 ù���� null����('\0')�� �ִ´�)
		memset(str, NULL, 100);
		memset(answer, NULL, 10);
		version = 0;
		do {	// ���ѷ��� �޴����� (do�� ���� ����, while (�ùٸ� �޴� �����Ҷ�����)
			system("cls");		// console ���� �ʱ�ȭ �Լ� (Windows.h ��� �ʿ�)
			printf("������׷� ver2\n*\t*\t*\n\n\n\t���� �ҹ��ڷ� �� ����(100�� �̳�)�� �ۼ��ϰ� [Enter]");
			printf("\n\t[GOOD] : ���� ���̿� ����(space)�� ���� ��� ���� ���");
			printf("\n\t[BEST] : ���� ���̿� ����(space)�� �־ ���� ���\n\n");
			printf("\n\t� ������ ������׷�ver2�� �����ұ��?\n\t(��ҹ��� ������� good or best)\n\n\t�Է�>> ");
			scanf("%s", &answer);
			fflush(stdin); 		// ���ڿ� ���ۿ� ������ �ִ� space, tab, enter�� ������ �Է� �� ������ �����ϱ� ����, "���� ���� �Լ�"

			if (strcmp(_strupr(answer), "GOOD") == 0)		// ���ڿ� �� �Լ��� strcmp(��1, ��2 ; ������ 0), ���ڿ� �빮��ȭ �Լ��� strupr(���ڿ�)
				version = 1;												// ���ڿ� ���� �Լ��� string.h ��� �ʿ�
			else if (strcmp(_strupr(answer), "BEST") == 0)
				version = 2;
			else if (strcmp(_strupr(answer), "EXIT") == 0)		// ���ѷ��� �޴����ÿ��� �����ɾ �־��ָ� ����!
				return 0;
		} while (version != 1 && version != 2);

		//str[0] = NULL;
		printf("%s\n", str);
		scanf("%*c");    // ���ڸ� �б��ϵ� ������������. \n�о �����ڴٴ°�

		printf("\t���� �Է�(100�� �̳�) >> ");
		version == 1 ? scanf("%s", &str) : fgets(str, 100, stdin); // ���ϴܼ� ���ǹ�(if~else�ε� ���� �ڵ��� 1�پ��ϰ��)
														//scanf("%[^\n]", &str);  // ���� ���
														//fflush(stdin);  // scanf����  fflush!

														//gets(str);  // ���� ���
		_strlwr(str);		// ���ڿ� ���Է��� �����ϱ� ����, �����ϰ� �ҹ��ڷ� �ٲٴ� �Լ� �ο�
		system("cls");	// ȭ�� �ʱ�ȭ ��, ������׷� ���
		printf("\n\n\t�Է��� ���� >> %s\n\n", str);

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

		rewind(stdin);	// �Է� ���� �ʱ�ȭ (��õ)
		do {
			printf("\n\n\tQ> ���α׷��� �ٽ� �����ұ��? (yes or no)\n\t�Է� >> ");
			scanf("%s", &answer);
			_strlwr(answer);
		} while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0);
	} while (strcmp(answer, "no") != 0);
	printf("\n\n\n");
	return 0;
}