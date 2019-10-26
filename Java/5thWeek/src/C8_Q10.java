import java.util.*;
import java.io.*;

public class C8_Q10 {
	public static void main(String[] args) throws IOException {
		File Infile = new File("D:\\JAVA\\5thWeek\\src\\football.txt");
		Scanner input = new Scanner(Infile);

		String team[] = new String[50];
		String teamname[] = new String[3];
		int win[] = new int[3];
		int lose[] = new int[3];
		int A[] = new int[5];
		int B[] = new int[5];

		if (!Infile.exists()) {
			System.out.print("파일을 찾을 수 없습니다.");
			System.exit(0);
		}
		int i = 0;
		while (input.hasNext()) {
			team[i] = input.next();
			i++;
		}
		i = 0;
		for (int k = 0; k <= 4; k += 2) {
			teamname[i] = team[k];
			i++;
		}
		for (int k = 0; k < 5; k++)
		{
			switch (k) {
			case 0:
				A[k] = team[1].charAt(0) - '0';
				B[k] = team[3].charAt(0) - '0';
				break;
			case 1:
				A[k] = team[5].charAt(0) - '0';
				B[k] = team[7].charAt(0) - '0';
				break;
			case 2:
				A[k] = team[9].charAt(0) - '0';
				B[k] = team[11].charAt(0) - '0';
				break;
			case 3:
				A[k] = team[13].charAt(0) - '0';
				B[k] = team[15].charAt(0) - '0';
				break;
			case 4:
				A[k] = team[17].charAt(0) - '0';
				B[k] = team[19].charAt(0) - '0';
				break;
			}
		}

		for (int j = 1; j < 20; j++)
		{
			switch(j) {
			case 1:
				if (A[0] > B[0]) {
					win[0] += 1;
					lose[1] += 1;
				}
				else {
					win[1] += 1;
					lose[0] += 1;
				}
			break;
			case 5:
				if (A[1] > B[1]) {
					win[2] += 1;
					lose[0] += 1;
				}
				if (A[1] < B[1]) {
					win[0] += 1;
					lose[2] += 1;
				}
			break;
			case 9:
				if (A[2] > B[2]) {
					win[1] += 1;
					lose[2] += 1;
				}
				if (A[2] < B[2]) {
					win[2] += 1;
					lose[1] += 1;

				}
			break;
			case 14:
				if (A[3] > B[3]) {
					win[2] += 1;
					lose[0] += 1;
				}
				if (A[3] < B[3]) {
					win[0] += 1;
					lose[2] += 1;
				}
			break;
			case 19:
				if (A[4] > B[4]) {
					win[1] += 1;
					lose[2] += 1;
				}
				if (A[4] < B[4]) {
					win[2] += 1;
					lose[1] += 1;
				}
			break;
			}
		}

		for (int j = 0; j <= 2; j++) {
			if (teamname[j].length() > 5)
				System.out.println(teamname[j] + "  \t" + win[j] + '\t' + lose[j]);
			else
				System.out.println(teamname[j] + "\t\t" + win[j] + '\t' + lose[j]);
		}
		input.close();
	}
}
