package exp9;
import java.io.*;

public class binaryfile_output_2 {
	void readbinaryfile(String file)
	{
		int count = 0;
		double avg = 0.0;
		DataInputStream filein = null;
		try
		{
			filein = new DataInputStream(new FileInputStream(file));
			while(true)
			{
				double num = filein.readDouble();
				avg+=num;
				count++;
			}
		}
		catch(EOFException e)
		{
			System.out.println("데이터는 " + count + "개, " +"평균은 " + avg/count);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}

	public static void main(String[] args)
	{
		binaryfile_output_2 binaryfile = new binaryfile_output_2();
		binaryfile.readbinaryfile("Pro9.dat");

	}
}
