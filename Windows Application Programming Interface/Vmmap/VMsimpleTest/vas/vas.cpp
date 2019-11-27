#include <stdio.h>
void main()
{
	char a='a';
	for(long i=0; i<100000; i++)
	{
		a='a'+i%26;
		printf("%c : %p\n", a, &a);
	}
}