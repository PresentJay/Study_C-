package exp3;
import java.util.*;

public class Test {
	public static Object Binarysearch(ArrayList<Employee> w,int id, int left,int right)//��̸���Ʈ���� ����Ž���� ���� ã���� �ϴ� id�� object�� ��ȯ
	{
		int middle=(left+right)/2;
		if(id==((Employee)w.get(middle)).getId())
		return w.get(middle);
		else if(id<((Employee)w.get(middle)).getId()&&left<middle)
		return Binarysearch(w,id,left,middle-1);
		else
		return Binarysearch(w,id,middle+1,right);
	}
	public static void main(String[] args)
	{
		int check;
		int menu;
		int checkid;
		int increase;
		double increase2;
		int last;

		Scanner input=new Scanner(System.in);
		ArrayList<Employee> worker=new ArrayList<Employee>();
		while(true)
		{
			System.out.println("1.�Ŵ��� 2.�ӿ� 3.�Ϲ����� 4.�Է� ���� �������ּ���.");
			check=input.nextInt();
			if(check==4)
			break;
				System.out.println("������ �̸��� �Է��ϼ���.");
			    String n=input.next();
			    System.out.println("�μ��� �Է��ϼ���.");
			    String dname=input.next();
				System.out.println("���̸� �Է��ϼ���.");
				int age=input.nextInt();
				System.out.println("�޿��� �Է��ϼ���.");
				double salary=input.nextDouble();
				System.out.println("���̵��ȣ�� �Է��ϼ���.");
				int id=input.nextInt();

				if(check==1)
				{
					Manager x=new Manager(n,"�Ŵ���",dname,id,age,salary);
					worker.add(x);
				}
				else if(check==2)
				{
					Executive x=new Executive(n,dname,id,age,salary);
					worker.add(x);
				}
				else if(check==3)
				{
					Employee x=new Employee(n,"����",dname,id,age,salary);
					worker.add(x);
				}
		}
		last=worker.size()-1;
		while(true)
		{
			System.out.println("1.������ �޿��� �����մϴ�. 2.�ӿ��� �󿩱��� �����մϴ� 3.�������� ������ �߰� �Ǵ� �����մϴ�. 4.������ �����͸� ����մϴ�. 5.�����ڿ� ���� ����� ǥ���մϴ�");
			menu=input.nextInt();
			switch(menu)
			{
				case 1: System.out.println("�޿��� ������ ������ ID�� �Է��ϼ���.");
				checkid=input.nextInt();
				Employee e=((Employee)Binarysearch(worker,checkid,0,last));
				System.out.println("������ ��ġ 1.���� 2.�Ǽ�");
				int checksuchi=input.nextInt();
				if(checksuchi==1)
				{
					increase=input.nextInt();
					e.changesalary(increase);
				}
				else if(checksuchi==2)
				{
					increase2=input.nextDouble();
					e.changesalary(increase2);
				}
				break;
				case 2: System.out.println("�󿩱��� ������ �ӿ��� ID�� �Է��ϼ���.");
				checkid=input.nextInt();
				Employee e2=((Employee)Binarysearch(worker,checkid,0,last));
				while(false==(e2.title).equals("�ӿ�"))
				{
					System.out.println("���� : �ش� ID�� ������ �ӿ��� �ƴմϴ�! ID�� �ٽ��Է��ϼ���.");//���� �޼���
					checkid=input.nextInt();
					e2=((Employee)Binarysearch(worker,checkid,0,last));
				}
				System.out.println("������ ��ġ�� �Է��ϼ���.");
				double cb=input.nextDouble();
				((Executive)e2).setBonus(cb);
				break;
				case 3: System.out.println("������ �߰� Ȥ�� ������ �������� ID�� �Է��ϼ���.");
				checkid=input.nextInt();
				Employee m=((Employee)Binarysearch(worker,checkid,0,last));//������ �߰����� �����ڸ� id�� �˻�
				while(true==m.title.equals("����"))
				{
					System.out.println("���� : �ش� ID�� �������� ID�� �ƴմϴ�! ID�� �ٽ��Է��ϼ���.");
					checkid=input.nextInt();
					m=((Employee)Binarysearch(worker,checkid,0,last));
				}
				System.out.println("�߰� Ȥ�� ������ų ������ ID�� �Է��ϼ���.");
				checkid=input.nextInt();
				Employee e3=((Employee)Binarysearch(worker,checkid,0,last));
				System.out.println("�ش� ������ 1.�߰� 2.���� �մϴ�.");
				int chpr=input.nextInt();//�߰� ���� üũ.
				if(chpr==1)
				{
					((Manager)m).plusarr(e3);//������ ���� ��Ͽ� �߰�
				}
				else if(chpr==2)
				{
					((Manager)m).removearr(e3);//������ ���� ��Ͽ��� ����
				}
				break;
				case 4:for(int i=0;i<worker.size();i++)
				System.out.println("�̸� : "+((Employee)worker.get(i)).name+"\n���� : "+((Employee)worker.get(i)).title+"\n�μ� : "+((Employee)worker.get(i)).department+"\nid : "+((Employee)worker.get(i)).id+"\n���� : "+((Employee)worker.get(i)).age+"\n�޿� : "+((Employee)worker.get(i)).getSalary());
				break;
				case 5:System.out.println("��������� �˰���� �������� ID�� �Է��ϼ���");
				checkid=input.nextInt();
				Employee e4=((Employee)Binarysearch(worker,checkid,0,last));
				((Manager)e4).printmanager();
				break;

			}
			input.close();
		}
	}
}
