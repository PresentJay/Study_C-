#include <stdio.h>

void main() {

	int arr[10], max = 0, min=0;

	for (int i = 0; i < 10; i++) {
		printf("%d��° ���� �Է� : ", i);
		scanf("%d", &arr[i]);
		if (arr[max] < arr[i]) max = i;
		if (arr[min] > arr[i]) min = i;
	}
	printf("���� ū ���� arr[%d]��°�� �ִ� %d�Դϴ�.\n���� ���� ���� arr[%d]��°�� �ִ� %d�Դϴ�.\n",max,arr[max],min,arr[min]);
}