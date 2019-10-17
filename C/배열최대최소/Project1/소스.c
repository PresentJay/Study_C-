#include <stdio.h>

void main() {

	int arr[10], max = 0, min=0;

	for (int i = 0; i < 10; i++) {
		printf("%d번째 정수 입력 : ", i);
		scanf("%d", &arr[i]);
		if (arr[max] < arr[i]) max = i;
		if (arr[min] > arr[i]) min = i;
	}
	printf("가장 큰 수는 arr[%d]번째에 있는 %d입니다.\n가장 작은 수는 arr[%d]번째에 있는 %d입니다.\n",max,arr[max],min,arr[min]);
}