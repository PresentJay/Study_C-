public class TestSort
{
	public int length;
	public int width;
	public int depth;

	public int s; // 넓
	public int v; // 부피

	public static int e;
	public TestSort(int l, int w, int d) //생성자
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
				temp.sets(0); // 임시공간을 초기화해주어야 한다.
				//System.out.println(temp.getsur());
			}
			for(int i=0;i<5;i++)
			{
				System.out.println(b[i].gets()); // 표면적 정렬 결과를 출력
			}
			e++;
		}

		else
		{
			for(int i=0;i<5;i++) // 시행횟수
			{
				for(int j=0;j<4;j++) // 비교 위치 이동
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
				System.out.println(b[i].getv()); // 부피 정렬 결과를 출력
			}
			e--;
		}
	}
	public static void setE()
	{
		e = 0;
	}

	public int compareTo(Object o) // TestSort에서 compareTo를 재정의
	{
		if(v < ((TestSort)o).v)
			return -1;
		if(v > ((TestSort)o).v)
			return 1;
		return 0;
	}

	public static void main(String[] args)
	{
		C10_Q5[] arr = new C10_Q5[5]; // Box 클래스 담을 배열 선언
		setE();

		arr[0] = new C10_Q5(1,2,3); // 개별 Box 생성
		arr[1] = new C10_Q5(2,1,1);
		arr[2] = new C10_Q5(4,2,3);
		arr[3] = new C10_Q5(5,3,1);
		arr[4] = new C10_Q5(1,3,2);

		arr[0].surfaceArea(); // 표면적을 구하고 저장
		arr[1].surfaceArea();
		arr[2].surfaceArea();
		arr[3].surfaceArea();
		arr[4].surfaceArea();

		arr[0].volume(); // 부피를 구하고 저장
		arr[1].volume();
		arr[2].volume();
		arr[3].volume();
		arr[4].volume();

		sorting(arr); // 표면적 크기에 따른 정렬
		System.out.println();
		sorting(arr); // 부피의 크기에 따른 정렬
	}
}


