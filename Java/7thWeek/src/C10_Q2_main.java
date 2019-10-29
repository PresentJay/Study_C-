public class C10_Q2_main {
	public static void main(String[] args) {
		C10_Q2_Executive ex = new C10_Q2_Executive(1.5);// 회사 이익률 1.5 매니저이면서 임원인 고규남의 처음 급여는 200*1.5로 300을 받는다.
		System.out.println("매니저의 이름 : " + ex.name + "\n나이 : " + ex.age + "\n급여 : " + ex.getSalary() + "\n직함 : "
				+ ex.title + "\n부서 : " + ex.dname);
		for (int i = 0; i < 2; i++) {
			ex.x[i].outprint();
		}
		System.out.println(" 임원인 정현재의 급여는 => " + ex.getSalary());
		ex.changebonus();
		System.out.println("매니저의 이름 : " + ex.name + "\n나이 : " + ex.age + "\n급여 : " + ex.getSalary() + "\n직함 : "
				+ ex.title + "\n부서 : " + ex.dname);
	}
}
