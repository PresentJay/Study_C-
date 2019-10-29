
public class C10_Q5 implements Comparable {

	public int length;
	public int width;
	public int depth;
	public int s;
	public int vol;

	public C10_Q5(int l, int w, int d) //생성자
	{
		length = l;
		width = w;
		depth = d;
	}

	public void surfaceArea() //s : 넓이
	{
		s =  (2*length*width) + (2*length*depth) + (2*width*depth);
	}
	public void volume() // v : 부피
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
			System.out.println("a의 표면적이 b의 표면적보다 크다.");
		else if(a.compareTo(b) < 0)
			System.out.println("a의 표면적이 b의 표면적보다 작다.");
		else
			System.out.println("a의 표면적과 b의 표면적은 같다.");
		System.out.print("\n");
	}
}

