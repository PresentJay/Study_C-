
public class C10_Q5 implements Comparable {

	public int length;
	public int width;
	public int depth;
	public int s;
	public int vol;

	public C10_Q5(int l, int w, int d) //������
	{
		length = l;
		width = w;
		depth = d;
	}

	public void surfaceArea() //s : ����
	{
		s =  (2*length*width) + (2*length*depth) + (2*width*depth);
	}
	public void volume() // v : ����
	{
		vol =  length * width * depth;
	}

	public int compareTo(Object b)
	{
		if(s < ((C10_Q5)b).s)
			return -1;
		if(s > ((C10_Q5)b).s)
			return 1;
		return 0;
	}

	public void sets(int a)
	{
		s = a;
	}
	public int gets()
	{
		return s;
	}

	public void setv(int a)
	{
		vol = a;
	}
	public int getv()
	{
		return vol;
	}

	public static void main(String[] args)
	{
		C10_Q5 a = new C10_Q5(2,2,3);
		C10_Q5 b = new C10_Q5(3,2,3);

		a.surfaceArea();
		b.surfaceArea();

		if(a.compareTo(b) > 0)
			System.out.println("a�� ǥ������ b�� ǥ�������� ũ��.");
		else if(a.compareTo(b) < 0)
			System.out.println("a�� ǥ������ b�� ǥ�������� �۴�.");
		else
			System.out.println("a�� ǥ������ b�� ǥ������ ����.");
		System.out.print("\n");
	}
}

