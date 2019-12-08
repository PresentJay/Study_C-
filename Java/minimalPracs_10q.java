import java.util.*;

public class practice{
	public static void main(String args[]){
		int a,b,c;
		Scanner input = new Scanner(System.in);

		System.out.println("\n---------------------------------------------------------------------------------------");
		System.out.println("문제 1번. 학번과 학년을 입력받아, 그대로 출력하는 문제입니다.");
		System.out.println("---------------------------------------------------------------------------------------\n");

		System.out.print("학번을 입력하세요 >> ");
 		a = input.nextInt();
		System.out.print("학년을 입력하세요 >> ");
		b = input.nextInt();
		System.out.println("\n결과 >> 나는 " + a + "학번이고, " + b + "학년입니다.");

		System.out.println("\n---------------------------------------------------------------------------------------");
		System.out.println("문제 2번. 두 개의 정수를 입력받아, 사칙연산과 나머지연산 결과를 출력하는 문제입니다.");
		System.out.println("---------------------------------------------------------------------------------------\n");

		System.out.print("첫 번째 정수를 입력하세요 >> ");
 		a = input.nextInt();
		System.out.print("두 번째 정수를 입력하세요 >> ");
		b = input.nextInt();
		System.out.println("\n결과출력\n" + a + " + " + b + " = " + (a+b));
		System.out.println(a + " - " + b + " = " + (a-b));
		System.out.println(a + " * " + b + " = " + (a*b));
		System.out.println(a + " / " + b + " = " + (a/b));
		System.out.println(a + " % " + b + " = " + (a%b));


		System.out.println("\n---------------------------------------------------------------------------------------");
		System.out.println("문제 3번. 하나의 정수를 입력받아, 자신을 더한 결과를 출력하는 문제입니다.");
		System.out.println("---------------------------------------------------------------------------------------\n");

		System.out.print("정수를 입력하세요 >> ");
		a = input.nextInt();
		System.out.println("\n결과 >> " + a + " + " + a + " = " + (a+a));

		System.out.println("\n---------------------------------------------------------------------------------------");
		System.out.println("문제 4번. 세 개의 정수를 입력받아, 모든 합과 평균을 출력하는 문제입니다.");
		System.out.println("---------------------------------------------------------------------------------------\n");

		System.out.print("첫 번째 정수를 입력하세요 >> ");
		a = input.nextInt();
		System.out.print("두 번째 정수를 입력하세요 >> ");
		b = input.nextInt();
		System.out.print("세 번째 정수를 입력하세요 >> ");
		c = input.nextInt();
		System.out.println("\n결과출력\n" + a + ", " + b + ", " + c + "의 합 >> " + (a+b+c));
		System.out.println(a + ", " + b + ", " + c + "의 평균 >> " + (double)((double)a+(double)b+(double)c)/(double)3);

		System.out.println("\n---------------------------------------------------------------------------------------");
		System.out.println("문제 5번. 온도(정수)를 입력 받아, 화씨->섭씨와 섭씨->화씨를 출력하는 문제입니다.");
		System.out.println("---------------------------------------------------------------------------------------\n");

		System.out.print("온도(정수)를 입력하세요 >> ");
 		a = input.nextInt();
		System.out.println("\n결과출력\n" + a + "가 화씨온도라면, 섭씨온도로 변환했을 때 >> " + ((a-32)/2) + "도");
		System.out.println(a + "가 섭씨온도라면, 화씨온도로 변환했을 때 >> " + (a*2+32) + "도");

		System.out.println("\n---------------------------------------------------------------------------------------");
		System.out.println("문제 6번. 월급과 재직년수를 입력 받아, 재직기간 급여 합계를 출력하는 문제입니다.");
		System.out.println("---------------------------------------------------------------------------------------\n");

		System.out.print("월급을 입력하세요 >> ");
 		a = input.nextInt();
		System.out.print("재직년수를 입력하세요 >> ");
		b = input.nextInt();
		System.out.println("\n결과 >> " + a*12*b + "원");
		System.out.println("퇴직금 >> " + a + "원");
		System.out.println("재직기간 이후 퇴직한다고 했을 때의 급여 >> " + (a*12*b+a) + "원");

		System.out.println("\n---------------------------------------------------------------------------------------");
		System.out.println("문제 7번. 하나의 정수를 입력 받아, 해당 정수가 3의배수인지 판별하는 문제입니다.");
		System.out.println("---------------------------------------------------------------------------------------\n");

		System.out.print("정수를 입력하세요 >> ");
		a = input.nextInt();
		System.out.println("결과 >> " + (a%3==0));

		System.out.println("\n---------------------------------------------------------------------------------------");
		System.out.println("문제 8번. 두 자리 수의 정수를 입력 받아, 자릿수를 바꿔 출력하는 문제입니다.");
		System.out.println("---------------------------------------------------------------------------------------\n");
		
		do{
			System.out.print("두 자리 수의 정수를 입력하세요 >> ");
			a = input.nextInt();
		}
		while (a<10 || a>100);
		System.out.println("결과 >> " + a%10 + "" + a/10);


		System.out.println("\n---------------------------------------------------------------------------------------");
		System.out.println("문제 9번. 세 자리 수의 정수를 입력 받아, 100의 자리와 1의 자리를 바꿔 출력하는 문제입니다.");
		System.out.println("---------------------------------------------------------------------------------------\n");

		do{
			System.out.print("세 자리 수의 정수를 입력하세요 >> ");
			a = input.nextInt();
		}
		while (a<100 || a>1000);
		System.out.println("결과 >> " + a%10 + "" + (a%100)/10 + "" + a/100);


		System.out.println("\n---------------------------------------------------------------------------------------");
		System.out.println("Extra 문제. 네 자리 수의 정수를 입력 받아, 각각 자리를 바꿔 출력하는 문제입니다.");
		System.out.println("---------------------------------------------------------------------------------------\n");

		do{
			System.out.print("네 자리 수의 정수를 입력하세요 >> ");
			a = input.nextInt();
		}
		while (a<1000 || a>10000);
		System.out.println("결과 >> " + a%10 + "" + a%1000/100 + "" + a%100/10 + "" + a/1000);
	}
}