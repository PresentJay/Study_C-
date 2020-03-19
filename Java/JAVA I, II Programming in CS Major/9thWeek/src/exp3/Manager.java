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
	public void printmanager()//관리자의 관리 직원 목록 호출
	{
		System.out.println("이름 : "+name+"\n직함 : "+title+"\n부서 : "+department+"\nid : "+id+"\n나이 : "+age+"\n급여 : "+salary);
		System.out.println(name+"의 관리 직원 목록을 출력합니다");
		for(int i=0;i<arr.size();i++)
		{
			System.out.println("이름 : "+((Employee)arr.get(i)).name+"\n직함 : "+((Employee)arr.get(i)).title+"\n부서 : "+((Employee)arr.get(i)).department+"\nid : "+((Employee)arr.get(i)).id+"\n나이 : "+((Employee)arr.get(i)).age+"\n급여 : "+((Employee)arr.get(i)).getSalary());
		}
	}
}
