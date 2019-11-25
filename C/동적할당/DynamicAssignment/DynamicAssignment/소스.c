#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void input(int size, int* arr);
void output(int size, int* arr);

int main() {
	int size;
	int* arr;
	printf("write your size of array down : "); scanf("%d", &size);
	if (size > 0) {
		arr = malloc(sizeof(int)*size);
		input(size, arr);
		output(size, arr);
	}
	else
		return 0;
}

void input(int size, int* arr) {
	for (int i = 0; i < size; i++) {
		printf("what is Value of arr[%d]? : ", i);
		scanf("%d", &arr[i]);
	}
}

void output(int size, int* arr) {
	for (int i = 0; i < size; i++) {
		if ((i + 1) % 8 == 0)
			printf("\n");
		printf("%d\t", arr[i]);
	}
	printf("\n\n\t");
	system("pause");
	free(arr);
}