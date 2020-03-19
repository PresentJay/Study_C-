
public class C7_Q22 {
	public static boolean r(int[][] x)// row의 법칙
	{
		int c = 0;
		int a = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				if (x[i][c] == x[i][j]) {

					System.out.println(a);
					c++;
					return true;
				}
			}
			c = 0;
		}
		return false;
	}

	public static boolean c(int[][] y)// cell의 법칙
	{
		int c = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				if (y[c][i] == y[j][i]) {

					System.out.print("c");
					c++;
					return true;
				}
			}
			c = 0;
		}
		return false;
	}

	public static boolean box(int[][] z)// box의 법칙
	{
		int coun = 0;
		int c = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				if (i >= 0 || i <= 2 && j >= 0 || j <= 2) {
					if (z[i][c] == z[i][j]) {
						c++;
						coun++;
						return true;
					}
				}
				if (i >= 3 || i <= 5 && j >= 3 || j <= 5) {
					if (z[i][c] == z[i][j]) {
						c++;
						coun++;
						return true;
					}
				}
				if (i >= 3 || i <= 5 && j >= 3 || j <= 5) {
					if (z[i][c] == z[i][j]) {
						c++;
						coun++;
						return true;
					}
				}
			}
			c = 0;
		}

		if (coun > 27) {
			return true;
		}
		return false;
	}

	public static void main(String[] args) {
		int[][] x = { { 4, 2, 9, 8, 1, 3, 5, 6, 7 }, { 5, 1, 6, 4, 7, 2, 9, 3, 8 }, { 7, 8, 3, 6, 5, 9, 2, 4, 1 },
				{ 6, 7, 2, 1, 3, 4, 8, 5, 9 }, { 3, 9, 5, 2, 8, 6, 1, 7, 4 }, { 8, 4, 1, 7, 9, 5, 6, 2, 3 },
				{ 1, 5, 8, 3, 6, 7, 4, 9, 2 }, { 1, 5, 8, 3, 6, 7, 4, 9, 2 }, { 9, 3, 4, 5, 2, 8, 7, 1, 6 },
				{ 2, 6, 7, 9, 4, 1, 3, 8, 5 } };

		if (r(x) == true || c(x) == true || box(x) == true) {
			System.out.println("잘못되었습니다");
		} else {
			System.out.println("정상입니다");
		}

	}
}
