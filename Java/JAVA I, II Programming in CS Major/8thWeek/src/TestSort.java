public class TestSort
{
	public int length;
	public int width;
	public int depth;

	public int s; // ��
	public int v; // ����

	public static int e;
	public TestSort(int l, int w, int d) //������
	{
		length = l;
		width = w;
		depth = d;
	}
	public static void sorting(C10_Q5 [] b)
	{
		C10_Q5 temp = new C10_Q5(0,0,0);

		if(e == 0)
		{
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<4;j++)
				{
					if(b[j].compareTo(b[j+1]) > 0)
					{
						temp.sets(b[j].gets());
						b[j].sets(b[j+1].gets());
						b[j+1].sets(temp.gets());
					}
				}
				temp.sets(0); // �ӽð����� �ʱ�ȭ���־�� �Ѵ�.
				//System.out.println(temp.getsur());
			}
			for(int i=0;i<5;i++)
			{
				System.out.println(b[i].gets()); // ǥ���� ���� ����� ���
			}
			e++;
		}

		else
		{
			for(int i=0;i<5;i++) // ����Ƚ��
			{
				for(int j=0;j<4;j++) // �� ��ġ �̵�
				{
					if(b[j].compareTo(b[j+1]) > 0)
					{
						temp.setv(b[j].getv());
						b[j].setv(b[j+1].getv());
						b[j+1].setv(temp.getv());
					}
				}
				temp.setv(0);
				//System.out.println(temp.getsur());
			}
			for(int i=0;i<5;i++)
			{
				System.out.println(b[i].getv()); // ���� ���� ����� ���
			}
			e--;
		}
	}
	public static void setE()
	{
		e = 0;
	}

	public int compareTo(Object o) // TestSort���� compareTo�� ������
	{
		if(v < ((TestSort)o).v)
			return -1;
		if(v > ((TestSort)o).v)
			return 1;
		return 0;
	}

	public static void main(String[] args)
	{
		C10_Q5[] arr = new C10_Q5[5]; // Box Ŭ���� ���� �迭 ����
		setE();

		arr[0] = new C10_Q5(1,2,3); // ���� Box ����
		arr[1] = new C10_Q5(2,1,1);
		arr[2] = new C10_Q5(4,2,3);
		arr[3] = new C10_Q5(5,3,1);
		arr[4] = new C10_Q5(1,3,2);

		arr[0].surfaceArea(); // ǥ������ ���ϰ� ����
		arr[1].surfaceArea();
		arr[2].surfaceArea();
		arr[3].surfaceArea();
		arr[4].surfaceArea();

		arr[0].volume(); // ���Ǹ� ���ϰ� ����
		arr[1].volume();
		arr[2].volume();
		arr[3].volume();
		arr[4].volume();

		sorting(arr); // ǥ���� ũ�⿡ ���� ����
		System.out.println();
		sorting(arr); // ������ ũ�⿡ ���� ����
	}
}


