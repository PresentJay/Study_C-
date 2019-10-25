import java.util.*;

public class C7_Q11 {
	
	public static int A_input(int arr[], int size) {
		Scanner input = new Scanner(System.in);

		while (size < 100) {
			System.out.print("A [ " + size + " ] => ");
			arr[size] = input.nextInt();
			if (arr[size] == -999) {
				size--;
				break;
			}
			size++;
		}
		System.out.println("------------------");
		//input.close();
		return size;
	}

	public static int B_input(int arr[], int size) {
		Scanner input = new Scanner(System.in);

		while (size < 100) {
			System.out.print("B [ " + size + " ] => ");
			arr[size] = input.nextInt();
			if (arr[size] == -999) {
				size--;
				break;
			}
			size++;
		}
		System.out.println("------------------");
		//input.close();
		return size;		
	}

	public static void Ordering(int arr[], int size) {
		int temp = 0;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}

	public static void sumOrder(int arr1[], int arr2[], int arr3[], int size1, int size2, int size3) {
		int temp = 0;

		for (int i = 0; i < size3; i++)// 배열을 병합
		{
			if (i < size1)
				arr3[i] = arr1[i];
			else
				arr3[i] = arr2[i - size1];
		}
		for (int j = 0; j < size3; j++)// 병합된 배열을 정렬
		{
			for (j = 0; j < size3 - 1; j++) {
				if (arr3[j] > arr3[j + 1]) {
					temp = arr3[j];
					arr3[j] = arr3[j + 1];
					arr3[j + 1] = temp;
				}
			}
		}
	}

	public static void printSumOrder(int arr[], int size) {
		System.out.println("------------------");
		System.out.println("배열 C 값 출력");
		for (int i = 0; i < size; i++)// 정렬된 배열 출력
			System.out.println("C [ " + i + " ] => " + arr[i]);
	}

	public static void main(String[] args) {

		int[] A = new int[100];
		int[] B = new int[100];
		int[] C = new int[200];
		int i = 0;
		int j = 0;
		int k = 0;
		
		System.out.println("------------------");
		System.out.println("배열 A 값 입력");
		i = A_input(A, i);
		System.out.println("배열 B 값 입력");
		j = B_input(B, j);

		for (int q = 0; q <= i; q++) {
			System.out.println("A [ " + q + " ] => " + A[q]);
		}
		for (int q = 0; q <= j; q++) {
			System.out.println("B [ " + q + " ] => " + B[q]);
		}

		Ordering(A, i);// 배열 정렬
		Ordering(B, j);// 배열 정렬

		k = i + j;

		sumOrder(A, B, C, i, j, k);
		System.out.println("\n\n\n\n배열을 병합하고, 출력");
		printSumOrder(C, k);
	}
}
