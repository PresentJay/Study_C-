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
	// �޴����� �˰��� + ���ڿ� �˰��� + for�� + �迭
	do {
		//answer[0] = NULL;	// ���ڿ� ���� ��, �������� �����ϱ� ���� �ʱ�ȭ��� (�迭 ù���� null����('\0')�� �ִ´�)
		memset(str, '\0', sizeof(str));		// 1��° ������ ���ڿ���, 2��° ���� ����, 3��° ���� ũ�⸸ŭ �Ҵ�
		memset(answer, '\0', sizeof(answer));
		memset(alphaCount, 0, sizeof(alphaCount));
		version = 0;
		
		do {	// ���ѷ��� �޴����� (do�� ���� ����, while (�ùٸ� �޴� �����Ҷ�����)
			system("cls");		// console ���� �ʱ�ȭ �Լ� (Windows.h ��� �ʿ�)
			printf("������׷� ver3\n*\t*\t*\n\n\n\t����(��,�ҹ��� �������) �Է��ϰ�, ������ �� [Enter]\n");
			printf("\n\t���ĺ��� ������ ��Ÿ���� �迭(ũ�� 26)��,\n\t#include <Windows.h>�� �ϸ� ����� �� �ִ� system(\"cls\") : �ܼ�â �ʱ�ȭ�Լ��� ������ �ϼ�!\n");
			printf("\n\t[NORMAL] : ���ĺ��� ���� ������, ���ݱ��� �Է��� ���ڿ��� �Բ� ������׷�(����)�� ���");
			printf("\n\t[HARD] : ���ĺ��� ���� ������, ���ݱ��� �Է��� ���ڿ��� �Բ� ���ڿ� ���̸� ����ϰ�,\n\t������׷�(����)�� ī��Ʈ ���� ������ ���\n\n");
			printf("\n\t� ������ ������׷�ver3�� �����ұ��?\n\t(��ҹ��� ������� normal or hard)\n\n\t�Է�(exit �Է� �� ����)>> ");
			scanf("%s", &answer);
			fflush(stdin); 		// ���ڿ� ���ۿ� ������ �ִ� space, tab, enter�� ������ �Է� �� ������ �����ϱ� ����, "���� ���� �Լ�"

			if (strcmp(_strupr(answer), "NORMAL") == 0)		// ���ڿ� �� �Լ��� strcmp(��1, ��2 ; ������ 0), ���ڿ� �빮��ȭ �Լ��� strupr(���ڿ�)
				version = 1;												// ���ڿ� ���� �Լ��� string.h ��� �ʿ�
			else if (strcmp(_strupr(answer), "HARD") == 0)
				version = 2;
			else if (strcmp(_strupr(answer), "EXIT") == 0)		// ���ѷ��� �޴����ÿ��� �����ɾ �־��ָ� ����!
				return 0;
		} while (version != 1 && version != 2);
		rewind(stdin);

		do {
			system("cls");	// ȭ�� �ʱ�ȭ ��, �Է½���
			tmpMax = STRLEN;
			printf("\n\n\t�Է��� ���� >>\t");
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
				printf("�Է��� ���� ���� = %d\n\n\t", strlen(str));
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
			printf("\n*\t*\t*\t*\t*\n\t�Է� (EnterŰ = ����) >>");
			currentCh = _getch();		// ��� �Է� �Լ� (one character ������ ǥ�� �����(stdio)�� �ƴ�! : conio.h ��� ���)
			rewind(stdin);
			if (currentCh >= 'A' && currentCh <= 'z') {
				if (currentCh < 'a') // �빮�� �Է½� ġȯ
					alphaCount[tolower(currentCh) - 'a']++;
				else
					alphaCount[currentCh - 'a']++;
				str[strlen(str)] = currentCh;
				
			}
			else if (currentCh == '\r') {
				printf("[Enter]Ű�� �Է��ϼ̽��ϴ�.\n\t");
				break;
			}
			else if (currentCh == ' ' || currentCh == '.' || currentCh == ',' || currentCh == '\'' || currentCh == '\"' || (currentCh >= '0' && currentCh <= '9'))  // �ΰ����� ����̹Ƿ� ���� ��
				str[strlen(str)] = currentCh;
			else
				continue;
			printf("%c", currentCh);

			printf("\n\n\t");
		} while (strlen(str) < 400);
		if (strlen(str) > 399) printf("�Է� ������ ���̰� 400�ڸ� �ʰ��Ͽ� ����Ǿ����ϴ�.\n\t%s", str);

		rewind(stdin);	// �Է� ���� �ʱ�ȭ (��õ)
		strcpy(answer, ReplayQ());  // �Լ� ������ε� �޴��� ���� �� �ִ�~!
	} while (strcmp(answer, "no") != 0);
	printf("\n\n\n");
	return 0;
}

char* ReplayQ() {
	char answer[10];
	do {
		printf("\n\n\tQ> ���α׷��� �ٽ� �����ұ��? (yes or no)\n\t�Է� >> ");
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