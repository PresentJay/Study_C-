import java.util.*;

public class C10_Q2_Executive extends C10_Q2_Manager {
	private double bonus;

	public C10_Q2_Executive(double b) {
		super();
		bonus = b;
	}

	public void changebonus()// 임원의 상여금 비율 변경 메소드
	{
		Scanner input = new Scanner(System.in);
		System.out.println("상여금 비율을 변경합니다 변경할 수치를 입력하세요.");
		bonus = input.nextDouble();
		input.close();
	}

	public double getSalary() {
		double newsalary = super.getSalary() * bonus;
		return newsalary;
	}
	
}
