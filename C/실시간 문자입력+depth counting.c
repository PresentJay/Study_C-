#include <stdio.h>
#include <conio.h>
void main() {
	char input;
	int depth = 0;
	int mass_per_depth[20] = { 0, };
	int count_bracket = 0;
	int max_depth = 0;

	printf("입력 >> ");
	do {
		input = getch();
		if (input != 40 && input != 41 && input != 58) { //일반 문자가 입력되었을 때
			printf("*");
			mass_per_depth[depth]++;
		}
		else if (input == 58)	// : 이 입력되었을 때
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

	printf("\n\n괄호는 총 %d개 입니다\n",count_bracket);
	
	for (int i = 0; i < max_depth; i++)
		printf("%d번째 괄호 밖에 있는 문자는 %d개 입니다\n", i + 1, mass_per_depth[i]);

	!depth ? printf("괄호가 짝이 맞습니다\n\n") : printf("괄호가 짝이 맞지 않습니다\n\n");
	return 0;
}