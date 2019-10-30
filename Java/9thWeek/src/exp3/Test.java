package exp3;
import java.util.*;

public class Test {
	public static Object Binarysearch(ArrayList<Employee> w,int id, int left,int right)//어레이리스트에서 이진탐색을 통해 찾고자 하는 id의 object를 반환
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
			System.out.println("1.매니저 2.임원 3.일반직원 4.입력 종료 선택해주세요.");
			check=input.nextInt();
			if(check==4)
			break;
				System.out.println("직원의 이름을 입력하세요.");
			    String n=input.next();
			    System.out.println("부서를 입력하세요.");
			    String dname=input.next();
				System.out.println("나이를 입력하세요.");
				int age=input.nextInt();
				System.out.println("급여를 입력하세요.");
				double salary=input.nextDouble();
				System.out.println("아이디번호를 입력하세요.");
				int id=input.nextInt();

				if(check==1)
				{
					Manager x=new Manager(n,"매니저",dname,id,age,salary);
					worker.add(x);
				}
				else if(check==2)
				{
					Executive x=new Executive(n,dname,id,age,salary);
					worker.add(x);
				}
				else if(check==3)
				{
					Employee x=new Employee(n,"직원",dname,id,age,salary);
					worker.add(x);
				}
		}
		last=worker.size()-1;
		while(true)
		{
			System.out.println("1.직원의 급여를 변경합니다. 2.임원의 상여금을 조절합니다 3.관리자의 직원을 추가 또는 삭제합니다. 4.직원의 데이터를 출력합니다. 5.관리자와 관리 명단을 표시합니다");
			menu=input.nextInt();
			switch(menu)
			{
				case 1: System.out.println("급여를 변경할 직원의 ID를 입력하세요.");
				checkid=input.nextInt();
				Employee e=((Employee)Binarysearch(worker,checkid,0,last));
				System.out.println("변경할 수치 1.정수 2.실수");
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
				case 2: System.out.println("상여금을 조절할 임원의 ID를 입력하세요.");
				checkid=input.nextInt();
				Employee e2=((Employee)Binarysearch(worker,checkid,0,last));
				while(false==(e2.title).equals("임원"))
				{
					System.out.println("오류 : 해당 ID의 직원은 임원이 아닙니다! ID를 다시입력하세요.");//오류 메세지
					checkid=input.nextInt();
					e2=((Employee)Binarysearch(worker,checkid,0,last));
				}
				System.out.println("변경할 수치를 입력하세요.");
				double cb=input.nextDouble();
				((Executive)e2).setBonus(cb);
				break;
				case 3: System.out.println("직원을 추가 혹은 삭제할 관리자의 ID를 입력하세요.");
				checkid=input.nextInt();
				Employee m=((Employee)Binarysearch(worker,checkid,0,last));//직원을 추가받을 관리자를 id로 검색
				while(true==m.title.equals("직원"))
				{
					System.out.println("오류 : 해당 ID는 관리자의 ID가 아닙니다! ID를 다시입력하세요.");
					checkid=input.nextInt();
					m=((Employee)Binarysearch(worker,checkid,0,last));
				}
				System.out.println("추가 혹은 삭제시킬 직원의 ID를 입력하세요.");
				checkid=input.nextInt();
				Employee e3=((Employee)Binarysearch(worker,checkid,0,last));
				System.out.println("해당 직원을 1.추가 2.삭제 합니다.");
				int chpr=input.nextInt();//추가 삭제 체크.
				if(chpr==1)
				{
					((Manager)m).plusarr(e3);//직원을 관리 목록에 추가
				}
				else if(chpr==2)
				{
					((Manager)m).removearr(e3);//직원을 관리 목록에서 삭제
				}
				break;
				case 4:for(int i=0;i<worker.size();i++)
				System.out.println("이름 : "+((Employee)worker.get(i)).name+"\n직함 : "+((Employee)worker.get(i)).title+"\n부서 : "+((Employee)worker.get(i)).department+"\nid : "+((Employee)worker.get(i)).id+"\n나이 : "+((Employee)worker.get(i)).age+"\n급여 : "+((Employee)worker.get(i)).getSalary());
				break;
				case 5:System.out.println("관리목록을 알고싶은 관리자의 ID를 입력하세요");
				checkid=input.nextInt();
				Employee e4=((Employee)Binarysearch(worker,checkid,0,last));
				((Manager)e4).printmanager();
				break;

			}
			input.close();
		}
	}
}
