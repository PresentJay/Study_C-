#include <stdio.h>
#include <conio.h>
void main() {
	char input;
	int depth = 0;
	int mass_per_depth[20] = { 0, };
	int count_bracket = 0;
	int max_depth = 0;

	printf("�Է� >> ");
	do {
		input = getch();
		if (input != 40 && input != 41 && input != 58) { //�Ϲ� ���ڰ� �ԷµǾ��� ��
			printf("*");
			mass_per_depth[depth]++;
		}
		else if (input == 58)	// : �� �ԷµǾ��� ��
			printf("%c", input);
		else if (input == 40 || input == 41) {
			if (input == 40) {
				depth++;
				if (max_depth < depth) max_depth = depth;
			}
			else
				depth--;
			count_bracket++;
			printf("%c", input);
		}
	} while (input != 58);

	printf("\n\n��ȣ�� �� %d�� �Դϴ�\n",count_bracket);
	
	for (int i = 0; i < max_depth; i++)
		printf("%d��° ��ȣ �ۿ� �ִ� ���ڴ� %d�� �Դϴ�\n", i + 1, mass_per_depth[i]);

	!depth ? printf("��ȣ�� ¦�� �½��ϴ�\n\n") : printf("��ȣ�� ¦�� ���� �ʽ��ϴ�\n\n");
	return 0;
}