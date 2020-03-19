package exp1;
public class Diamond extends Shape
{
	public Diamond()
	{
		super();
	}
	public Diamond(int x,char ch)
	{
		super(x,ch);
	}
	public void draw(int x,int y)
	{
		int count=0;
		for(int i=1;i<=y;i++)
		{
			System.out.println();
		}
		for(int len=1;len<=rows;len++)
		{
			if(rows%2!=0)
			{
				if(len<=(rows/2)+1)
				{
					for(int i=0;i<=rows-len+x;i++)
					{
						System.out.print(" ");
					}
					for(int i=0;i<len;i++)
					{
						System.out.print(character+" ");
					}
					System.out.println();
				}
				else if(len>(rows/2)+1)
				{
					for(int i=0;i<=rows-(rows/2)+count+x;i++)
					{
						System.out.print(" ");
					}
					for(int i=0;i<(rows/2)-count;i++)
					{
						System.out.print(character+" ");
					}
					System.out.println();
					count++;
				}
			}
			else if(rows%2==0)
			{
				if(len<=(rows/2))
				{
					for(int i=0;i<=rows-len+x;i++)
					{
						System.out.print(" ");
					}
					for(int i=0;i<len;i++)
					{
						System.out.print(character+" ");
					}
					System.out.println();
				}
				else if(len>(rows/2))
				{

					for(int i=0;i<=rows-(rows/2)+count+x;i++)
					{
						System.out.print(" ");
					}
					for(int i=0;i<(rows/2)-count;i++)
					{
						System.out.print(character+" ");
					}
					System.out.println();
					count++;
				}
			}
		}
	}
}

