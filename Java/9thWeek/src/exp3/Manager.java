package exp3;
import java.util.*;

public class Manager extends Employee
{
	protected ArrayList<Employee> arr;
	Scanner input=new Scanner(System.in);

	public Manager(String n,String t,String d,int id,int age,double sal)
	{
		super(n,t,d,id,age,sal);
		arr=new ArrayList<Employee>();
	}
	public void plusarr(Employee b)
	{
		arr.add(b);
	}
	public void removearr(Employee b)
	{
		for(int i=0;i<arr.size();i++)
		{
			if(((Employee)arr.get(i)).getId()==b.id)
			{
				arr.remove(i);
			}
		}
	}
	public void printmanager()//�������� ���� ���� ��� ȣ��
	{
		System.out.println("�̸� : "+name+"\n���� : "+title+"\n�μ� : "+department+"\nid : "+id+"\n���� : "+age+"\n�޿� : "+salary);
		System.out.println(name+"�� ���� ���� ����� ����մϴ�");
		for(int i=0;i<arr.size();i++)
		{
			System.out.println("�̸� : "+((Employee)arr.get(i)).name+"\n���� : "+((Employee)arr.get(i)).title+"\n�μ� : "+((Employee)arr.get(i)).department+"\nid : "+((Employee)arr.get(i)).id+"\n���� : "+((Employee)arr.get(i)).age+"\n�޿� : "+((Employee)arr.get(i)).getSalary());
		}
	}
}
