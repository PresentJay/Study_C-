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
		System.out.println("종업원의 이름 : "+name+"\n나이 : "+age+"\n급여 : "+salary+"\n직함 : "+title+"\n부서이름 : "+dname);
	}
	public void changesalary()//급여변경메소드
	{
		Scanner input = new Scanner(System.in);
		int check=0;
		int plus=0;
		double plus1=0;
		System.out.println("급여를 변경합니다.  1.정수  2.실수. 선택하세요.");
		check=input.nextInt();
		if(check==1)
		{
			System.out.println("증가시킬 금액을 입력하세요.");
			plus=input.nextInt();
			salary=salary+plus;
		}
		else if(check==2)
		{
			System.out.println("변경시킬 비율을 입력하세요. 1보다 작게되면 감소하고 크면 증가하게됩니다.");
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
