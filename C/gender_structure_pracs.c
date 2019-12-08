#include <stdio.h>
#include <string.h>

struct person
{
	char name[10];
	char gender[5];
	int age;
};
void prn(struct person user[],int male,int female,int sum)
{
	int i;
	for(i=0; i<10;i++)
	{
		if(strcmp(user[i].gender,"남")==0)
		{
			male++;
		}
		else
		{
			female++;
		}
		sum+=user[i].age;
	}
	for(i=0;i<10;i++)
	{
		printf("이름 : %s 성별 : %s 나이 : %d",user[i].name,user[i].gender,user[i].age);
		printf("\n");
	}
	printf("남자의 수 : %d\n여자의 수 : %d\n나이의 합 : %d\n",male,female,sum/10);
}
void main()
{
	struct person user[10] = {{"나태희","여",20},{"유현빈","남",29},{"나원빈","남",25},{"문건영","여",22},{"소지법","남",25},{"나보배","여",29},{"장도건","남",32},{"고수영","여",29},{"이나라","여",31},{"김해수","여",35}};	
	int male = 0, female = 0, sum = 0;
	prn(user,male,female,sum);
}
