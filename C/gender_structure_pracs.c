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
		if(strcmp(user[i].gender,"��")==0)
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
		printf("�̸� : %s ���� : %s ���� : %d",user[i].name,user[i].gender,user[i].age);
		printf("\n");
	}
	printf("������ �� : %d\n������ �� : %d\n������ �� : %d\n",male,female,sum/10);
}
void main()
{
	struct person user[10] = {{"������","��",20},{"������","��",29},{"������","��",25},{"���ǿ�","��",22},{"������","��",25},{"������","��",29},{"�嵵��","��",32},{"�����","��",29},{"�̳���","��",31},{"���ؼ�","��",35}};	
	int male = 0, female = 0, sum = 0;
	prn(user,male,female,sum);
}
