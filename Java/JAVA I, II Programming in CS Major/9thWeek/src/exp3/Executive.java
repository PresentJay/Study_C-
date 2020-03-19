package exp3;

public class Executive extends Manager
{
	private double bonus=0.1;

	public Executive(String name, String department,int id,int age,double salary)
	{
		super(name,"юс©Ь",department,id,age,salary);
	}
	
	public double getSalary()
	{
		double newsalary=salary+salary*bonus;
		return newsalary;
	}
	
	public void setBonus(double b)
	{
		bonus=b;
	}
}

