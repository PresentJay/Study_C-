public class C10_Q2_Manager extends C10_Q2_Employee {
	protected C10_Q2_Employee[] x;

	public C10_Q2_Manager()
	{
		super("정현재","매니저","의류관리",1,24,200);
		x=new C10_Q2_Employee[2];
		x[0]=new C10_Q2_Employee("정현모","종업원","의류관리",2,24,100);
		x[1]=new C10_Q2_Employee("최준식","종업원","의류관리",3,20,100);
	}
}
