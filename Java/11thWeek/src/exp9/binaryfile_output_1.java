package exp9;
import java.util.*;
import java.io.*;
public class binaryfile_output_1 {
	void writebinaryfile(String fileName)
	{
		try
		{
			Scanner input = new Scanner(System.in);
			File file = new File(fileName);
			FileOutputStream fout = new FileOutputStream(file);
			DataOutputStream out = new DataOutputStream(fout);
			double dInput=0.0;
			System.out.println("0을 입력시 종료합니다");
			System.out.print("이진 파일 값을 입력하세요: ");
			while(true)
			{
				dInput=input.nextDouble();
				if(dInput==0)
					break;
				out.writeDouble(dInput);
				System.out.print("추가 입력 : ");
			}
			out.close();
			input.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
	}

	public static void main(String[] args)
	{
		binaryfile_output_1 binaryfile = new binaryfile_output_1();
		binaryfile .writebinaryfile("Pro9.dat");
	}
}
