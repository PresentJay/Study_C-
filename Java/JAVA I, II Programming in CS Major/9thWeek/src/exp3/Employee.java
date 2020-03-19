package exp3;

public class Employee
{
	protected String name,title,department;
	protected int id,age;
	protected double salary;
	
	public Employee(String n,String t,String d,int i,int a,double s)
	{
		name=n;
		title=t;
		department=d;
		id=i;
		age=a;
		salary=s;
	}
	
	public void outprint()
	{
		System.out.println("�������� �̸� : "+name+"\n���� : "+age+"\n�޿� : "+salary+"\n���� : "+title+"\n�μ��̸� : "+department);
	}
	
	public void changesalary(int increase)
	{
		salary+=increase;
	}
	
	public void changesalary(double increase)
	{
		if(increase>=0.0 && increase<=1.0) salary+=salary*increase;
		else System.out.println("0~1������ ���� �Է��ϼ���");
	}

	public int getId() {
		return id;
	}

	public double getSalary() {
		return salary;
	}

}

