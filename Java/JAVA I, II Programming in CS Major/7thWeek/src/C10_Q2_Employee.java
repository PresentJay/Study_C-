import java.util.*;
public class C10_Q2_Employee {
	protected String name,title,dname;
	protected int id,age;
	private double salary;
	public C10_Q2_Employee(String n,String t,String d,int i,int a,int s)
	{
		name=n;
		title=t;
		dname=d;
		id=i;
		age=a;
		salary=s;
	}

	public void outprint()
	{
		System.out.println("�������� �̸� : "+name+"\n���� : "+age+"\n�޿� : "+salary+"\n���� : "+title+"\n�μ��̸� : "+dname);
	}
	public void changesalary()//�޿�����޼ҵ�
	{
		Scanner input = new Scanner(System.in);
		int check=0;
		int plus=0;
		double plus1=0;
		System.out.println("�޿��� �����մϴ�.  1.����  2.�Ǽ�. �����ϼ���.");
		check=input.nextInt();
		if(check==1)
		{
			System.out.println("������ų �ݾ��� �Է��ϼ���.");
			plus=input.nextInt();
			salary=salary+plus;
		}
		else if(check==2)
		{
			System.out.println("�����ų ������ �Է��ϼ���. 1���� �۰ԵǸ� �����ϰ� ũ�� �����ϰԵ˴ϴ�.");
			plus1=input.nextDouble();
			salary=salary*plus1;
		}
		
		input.close();
	}
	public double getSalary()
	{
		return salary;
	}
}
