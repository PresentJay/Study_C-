#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define DATASIZE 100

/*	2018/11/09 (금) 데이터구조 과제 3, 20143174 정현재
		Sorting Program 작성	: 학번 끝자리가 홀수인 경우, selection sort
											: 학번 끝자리가 짝수인 경우, insertion sort
											: 학번 끝자리가 1,5,9인 경우, quick sort
											: 학번 끝자리가 2,6,0인 경우, heap sort
											: 학번 끝자리가 3,7인 경우, merge sort
											: 학번 끝자리가 4,8인 경우, radix sort
		- 100개의 4자리 수 data를 이용
		- 20개 단위로 출력 (quick은 첫 단계, radix, merge는 모든 단계)
		- 각 프로그램의 비교 횟수를 출력
*/

void show_data(int*);
void show_counter(int);
void get_SID(int*);
void refresh_data(int*);
void Sort_selection(int*);
void Sort_insertion(int*);
void Sort_quick(int*, int, int);
void Sort_heap(int*, int);
void Sort_merge(int*);
void Sort_radix(int*, int, int);

void main() {
	int data_group[DATASIZE];
	int student_ID;
	system("mode con: cols=165 lines=50");
	srand((unsigned)time(NULL));

	printf("\n\t>> 20143174 정현재의 2018-2학기 데이터구조 3차과제입니다.\n\n");

	get_SID(&student_ID);
	refresh_data(data_group);

	switch (student_ID % 2) {
	case 0:		// insertion sort
		printf("\n\n\t※학번의 끝자리가 짝수입니다 >> insertion sort 진행\n\n");
		Sort_insertion(data_group);
		break;

	default:		// selection sort
		printf("\n\n\t※학번의 끝자리가 홀수입니다 >> selection sort 진행\n\n");
		Sort_selection(data_group);
		break;
	}

	switch (student_ID % 10) {
	case 1:
	case 5:
	case 9:		// quick sort
		printf("\n\n\t※학번의 끝자리가 1,5,9 입니다 >> quick sort 진행\n\n");
		Sort_quick(data_group, 0, DATASIZE - 1);
		break;

	case 0:
	case 2:
	case 6:		// heap sort
		printf("\n\n\t※학번의 끝자리가 0,2,6 입니다 >> heap sort 진행\n\n");
		Sort_heap(data_group, DATASIZE);
		break;

	case 3:
	case 7:		// merge sort
		printf("\n\n\t※학번의 끝자리가 3,7 입니다 >> merge sort 진행\n\n");
		Sort_merge(data_group);
		break;

	case 4:
	case 8:		// radix sort
		printf("\n\n\t※학번의 끝자리가 4,8 입니다 >> radix sort 진행\n\n");
		Sort_radix(data_group, 4, 10);
		break;
	}
}

void show_data(int* data) {
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < DATASIZE; i++) {
		printf("%d\t", data[i]);
		if ((i + 1) % 20 == 0)		// 20개 단위로 출력 제어
			printf("\n");
	}
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

void show_counter(int counter) { printf("\t연산 횟수 : %d\n\n\n", counter); }

void get_SID(int *var) {
	do {
		printf("\t학번 입력(8자리) >> ");
		scanf("%d", var);
	} while (*var < 10000000 || *var > 99999999);	// 학번 8자리로 간단한 유효성검사
}

void refresh_data(int* data) {
	for (int i = 0; i < DATASIZE; i++)
		data[i] = rand() % 9999 + 1;
	show_data(data);
}

void Sort_selection(int* data) {		// 선택정렬 알고리즘
	int min, temp, counter = 0;
	int ordered_data[DATASIZE];		// 복사본 배열 선언
	for (int i = 0; i < DATASIZE; i++)	// 원본 배열 -> 복사본 배열 : 데이터 복사 작업
		ordered_data[i] = data[i];

	for (int i = 0; i < DATASIZE - 1; i++) {
		min = i;
		for (int j = i + 1; j < DATASIZE; j++) {
			if (ordered_data[j] < ordered_data[min])
				min = j;
		}
		if (min != i) {
			temp = ordered_data[i];
			ordered_data[i] = ordered_data[min];
			ordered_data[min] = temp;
			counter++;
		}
	}
	show_data(ordered_data);
	show_counter(counter);
}

void Sort_insertion(int* data) {
	int temp, counter = 0;
	int ordered_data[DATASIZE];
	for (int i = 0; i < DATASIZE; i++)
		ordered_data[i] = data[i];
	for (int i = 1, j; i < DATASIZE; i++) {
		temp = ordered_data[(j = i)];
		while (--j >= 0 && temp < ordered_data[j]) {
			ordered_data[j + 1] = ordered_data[j];
			ordered_data[j] = temp;
			counter++;
		}
	}
	show_data(ordered_data);
	show_counter(counter);
}

void Sort_quick(int* data, int left, int right) {
	int temp, counter = 0;
	int ordered_data[DATASIZE];
	int pivot = data[0];
	for (int i = 0; i < DATASIZE; i++)
		ordered_data[i] = data[i];
	if (left < right) {
		right++;
		do {
			do left++;
			while (ordered_data[left] < pivot);
			do right--;
			while (ordered_data[right] > pivot);
			if (left < right) {
				temp = ordered_data[left];
				ordered_data[left] = ordered_data[right];
				ordered_data[right] = temp;
				counter++;
			}
		} while (left < right);
		temp = ordered_data[0];
		ordered_data[0] = ordered_data[right];
		ordered_data[right] = temp;
		counter++;
	}
	printf("\tPivot data = %d\n\t(1단계만 진행)\n\n", pivot);
	show_data(ordered_data);
	show_counter(counter);
}

void heap_adjust(int* data, int size, int root, int* counter) {
	int parent = root;
	int largest = parent;
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	int temp;
	if (left < size && data[left] > data[largest])
		largest = left;

	if (right < size && data[right] > data[largest])
		largest = right;

	if (parent != largest) {
		temp = data[largest];
		data[largest] = data[parent];
		data[parent] = temp;
		(*counter)++;
		heap_adjust(data, size, largest, counter);
	}
}

void heap_buildMAX(int* data, int size, int* counter) {
	for (int mid = size / 2 - 1; mid >= 0; mid--)
		heap_adjust(data, size, mid, counter);
}

void Sort_heap(int* data, int size) {
	int temp, counter = 0;
	int ordered_data[DATASIZE];
	for (int i = 0; i < DATASIZE; i++)
		ordered_data[i] = data[i];
	heap_buildMAX(ordered_data, size, &counter);

	while (size > 1) {
		temp = ordered_data[0];
		ordered_data[0] = ordered_data[size - 1];
		ordered_data[size - 1] = temp;
		counter++;
		size--;
		heap_adjust(ordered_data, size, 0, &counter);
	}
	show_data(ordered_data);
	show_counter(counter);
}


void merge(int* dst, int* src, int low, int mid, int high, int* counter) {
	int i = low;
	int j = mid + 1;
	int k = low;

	while (i <= mid && j <= high) {
		if (src[i] < src[j]) {
			dst[k++] = src[i++];
			(*counter)++;
		}
		else if (src[i] >= src[j]) {
			dst[k++] = src[j++];
			(*counter)++;
		}
	}

	if (i >= mid) {
		while (j <= high) {
			dst[k++] = src[j++];
			(*counter)++;
		}
	}

	if (j >= high) {
		while (i <= mid) {
			dst[k++] = src[i++];
			(*counter)++;
		}
	}

	for (int i = low; i <= high; i++) {
		src[i] = dst[i];
		(*counter)++;
	}
}

void mergeSort(int* dst, int* src, int low, int high, int* counter){
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergeSort(dst, src, low, mid, counter);
		mergeSort(dst, src, mid + 1, high, counter);
		merge(dst, src, low, mid, high, counter);
	}
}

void Sort_merge(int* data) {
	int counter = 0;
	int ordered_data[DATASIZE];
	int raw_data[DATASIZE];
	for (int i = 0; i < DATASIZE; i++)
		raw_data[i] = data[i];
	mergeSort(ordered_data, raw_data, 0, DATASIZE - 1, &counter);
	show_data(ordered_data);
	show_counter(counter);
}

void Sort_radix(int* data, int exp, int digit) {	// LSD 방법 
	int *counts, *temp;	// 각 자리수의 숫자 개수를 담을 배열
	int index, Frequency_number, counter = 0;
	int ordered_data[DATASIZE];
	if ((counts = (int*)malloc(digit * sizeof(int))) == NULL) return;
	if ((temp = (int*)malloc(DATASIZE * sizeof(int))) == NULL) return;
	for (int i = 0; i < DATASIZE; i++)
		ordered_data[i] = data[i];

	for (int i = 0; i < exp; i++) {
		for (int j = 0; j < digit; j++)
			counts[j] = 0;
		Frequency_number = (int)pow((double)digit, (double)i);

		for (int j = 0; j < DATASIZE; j++) {
			index = (int)(ordered_data[j] / Frequency_number) % digit;
			counts[index]++;
		}

		for (int j = 1; j < digit; j++)
			counts[j] += counts[j - 1];

		for (int j = DATASIZE - 1; j >= 0; j--) {
			index = (int)(ordered_data[j] / Frequency_number) % digit;
			temp[counts[index] - 1] = ordered_data[j];
			counts[index]--;
			counter++;
		}
		for (int i = 0; i < DATASIZE; i++)
			ordered_data[i] = temp[i];
	}
	show_data(ordered_data);
	show_counter(counter);
}