public class C10_Q2_main {
	public static void main(String[] args) {
		C10_Q2_Executive ex = new C10_Q2_Executive(1.5);// ȸ�� ���ͷ� 1.5 �Ŵ����̸鼭 �ӿ��� ��Գ��� ó�� �޿��� 200*1.5�� 300�� �޴´�.
		System.out.println("�Ŵ����� �̸� : " + ex.name + "\n���� : " + ex.age + "\n�޿� : " + ex.getSalary() + "\n���� : "
				+ ex.title + "\n�μ� : " + ex.dname);
		for (int i = 0; i < 2; i++) {
			ex.x[i].outprint();
		}
		System.out.println(" �ӿ��� �������� �޿��� => " + ex.getSalary());
		ex.changebonus();
		System.out.println("�Ŵ����� �̸� : " + ex.name + "\n���� : " + ex.age + "\n�޿� : " + ex.getSalary() + "\n���� : "
				+ ex.title + "\n�μ� : " + ex.dname);
	}
}
