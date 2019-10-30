package exp1;
public class LeftTriangle extends Shape
{
	public LeftTriangle()
	{
		super();
	}
	public LeftTriangle(int x, char ch)
	{
		super(x,ch);
	}

	public void draw(int x, int y)
	{
		int count=0;
		for(int i=1;i<=y;i++)
		{
			System.out.println();
		}
		for(int len=1;len<=rows; len++)
		{
			for(int i=1;i<rows-count;i++)
			{
				System.out.print(' ');
			}
			for(int j=0;j<=count;j++)
			{
				System.out.print(character);
			}
			System.out.println();
			count++;
		}
	}
}

