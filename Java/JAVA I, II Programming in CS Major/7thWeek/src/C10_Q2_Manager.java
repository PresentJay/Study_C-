public class C10_Q2_Manager extends C10_Q2_Employee {
	protected C10_Q2_Employee[] x;

	public C10_Q2_Manager()
	{
		super("������","�Ŵ���","�Ƿ�����",1,24,200);
		x=new C10_Q2_Employee[2];
		x[0]=new C10_Q2_Employee("������","������","�Ƿ�����",2,24,100);
		x[1]=new C10_Q2_Employee("���ؽ�","������","�Ƿ�����",3,20,100);
	}
}
