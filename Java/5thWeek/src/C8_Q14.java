import java.io.*;
import java.util.*;

public class C8_Q14 {
	public static void main(String[] args)throws IOException
	{
		
		File InFile=new File("D:\\JAVA\\5thWeek\\src\\name.txt");

		if(!InFile.exists())
		{
			System.out.println("파일을 찾을 수 없습니다.");
			System.exit(0);
		}
		
		String temp;
		String name[]=new String[30];
		Scanner input =new Scanner(InFile);
		int a=0;
		int val[]=new int[30];
		
		
		while(input.hasNext())
		{
			name[a]=input.next();
			val[a]=name[a].charAt(0);
			a++;
		}
		for(int i=0; i<5; i++)
		{
			for(int j=1; j<5; j++)
			{
				if(val[i]>val[j])//스왑을 이용 위치를 바꿔준다.
				{
					temp=name[i];
					name[i]=name[j];
					name[j]=temp;
				}
			}
		}
		File outfile=new File("D:\\JAVA\\5thWeek\\src\\out.txt");
		PrintWriter out=new PrintWriter(outfile);
		
		for(int i=0; i<5; i++)
		{
			out.println(name[i]);
		}
		
		input.close();
		out.close();
	}
}
