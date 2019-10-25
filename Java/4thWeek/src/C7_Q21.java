import java.util.*;

public class C7_Q21 {
	public static int[][] readArray(int n) {
		int x[][] = new int[5][n];

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < n; j++) {
				int num = (int) (99 * Math.random() + 1);// 랜덤으로 배열에 수를 입력받음
				x[i][j] = num;
				System.out.print(x[i][j] + "\t");
			}
			System.out.println();
		}

		return x;
	}

	public static void columnsort(int[][] x, int size) {
		int temp = 0;

		for (int j = 0; j < size; j++) {

			for (int i = 0; i < 5; i++) {

				for (int z = i + 1; z < 5; z++) {
					if (x[z][j] < x[i][j]) {
						temp = x[z][j];
						x[z][j] = x[i][j];
						x[i][j] = temp;// 스왑을 이용 큰수가 행 제일 밑으로 가게 만들엇다

					}
				}
			}
		}
		System.out.println("재배치");
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < size; j++) {
				System.out.print(x[i][j] + "\t");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int x[][] = readArray(n);
		columnsort(x, n);
		
		input.close();
	}
}
