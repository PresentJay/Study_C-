#include <stdio.h>
#include <Windows.h>
void main() {
	int value1 = 0;
	int* addr1 = &value1;
	printf("%d (%d)\n", addr1, &addr1);
	
	int* secondpointer = &addr1;
	printf("%d (%d)\n",secondpointer, &secondpointer);

	int* thirdpointer = &secondpointer;
	printf("%d (%d)\n",thirdpointer, &thirdpointer);
	//-------------------------------------------------------------
	*addr1 = 5;
	printf("addr %d (%d) vs value %d (%d)\n", addr1, *addr1, value1, &value1);
	printf("double addr %d (%d)\n", *secondpointer, *&thirdpointer);

	int* nextPointer= 5000;
	//printf("address reversing success : %d(%d)\n", nextPointer, *nextPointer);
	printf("address reversing failed : %d\n", nextPointer);
	//------------------------------------------------------------------
	nextPointer = malloc(sizeof(int));
	printf("address reversing success : %d(%d)\n", nextPointer, *nextPointer);
	
	*nextPointer = 5000;
	printf("address envalued : %d(%d)\n", nextPointer, *nextPointer);
	free(nextPointer);
	printf("address initialized : %d(%d)\n", nextPointer, *nextPointer);
	
	system("pause");
}