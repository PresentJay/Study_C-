import java.util.*;

public class C10_Q2_Executive extends C10_Q2_Manager {
	private double bonus;

	public C10_Q2_Executive(double b) {
		super();
		bonus = b;
	}

	public void changebonus()// �ӿ��� �󿩱� ���� ���� �޼ҵ�
	{
		Scanner input = new Scanner(System.in);
		System.out.println("�󿩱� ������ �����մϴ� ������ ��ġ�� �Է��ϼ���.");
		bonus = input.nextDouble();
		input.close();
	}

	public double getSalary() {
		double newsalary = super.getSalary() * bonus;
		return newsalary;
	}
	
}
