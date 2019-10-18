#include <stdio.h>
#include <conio.h>

void main()
{
	char ch;
	int num;
	int sum = 0;


	while (sum<=100)
	{
		ch = getch();
		printf("%c", ch);
		if (ch == ':') {
			printf("\t%d\n", sum);
			break;
		}
		num = ch - 96;
		sum = sum + num;
	}
	if (sum > 100)
		printf("\t%d, 단어가 100보다 큽니다.\n",sum);
}