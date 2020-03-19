package exp6;
import java.util.*;
import java.io.*;

public class textfile_IO {
	public static void main(String [] args) throws IOException
	{
		File inputFile = new File("D:\\JAVA\\11thWeek\\src\\exp6\\data.txt");
		File outputFile = new File("D:\\JAVA\\11thWeek\\src\\exp6\\change.txt");
		PrintWriter output = new PrintWriter(outputFile);
		Scanner input = new Scanner(inputFile);
		while(input.hasNext())
		{
			String line=input.next();
			char arr[] = new char[line.length()];
			for(int i=0; i<line.length(); i++)
			{
				arr[i]=line.charAt(i);
			}
			for(int i=0; i<arr.length; i++)
			{
				for(int j=i+1; j<arr.length; j++)
				{
					if(arr[i]>arr[j])
					{
						char temp=arr[i];
						arr[i]=arr[j];
						arr[j]=temp;
					}
				}
			}
			System.out.println("정렬 전" + line);
			System.out.print("정렬 후 ");
			for(int i=0; i<arr.length; i++)
			{
				System.out.print(arr[i]);
			}
			System.out.println();
			output.print(arr);
			output.println();
		}
		System.out.println("정렬 후 저장 완료.");
		output.close();
		input.close();
	}
}
