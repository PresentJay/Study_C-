package exp7;
import java.util.*;
public class Form_Exception {
	public static void main(String[] argv)
	{
		Scanner input=new Scanner(System.in);
		int grade=0;
		String inputgrade;

        try
        {
		System.out.print("�������� : ");
		inputgrade=input.next();
		grade=Integer.parseInt(inputgrade);
	    }
	    catch(NumberFormatException a)
	    {
			System.out.println("���ڴ� �Է��� �Ұ��մϴ�.");
			System.exit(0);
		}

        try
        {
			if(grade>100 || grade<0)
			{
				Exception e=new Exception("0~100���� ���ڸ� �־��ֽʽÿ�");
			    throw e;
			}
			else if(grade>=90)
				System.out.println("A");
			else if(grade>=80)
				System.out.println("B");
			else if(grade>=70)
							System.out.println("C");
			else if(grade>=60)
							System.out.println("D");
			else if(grade>=0)
							System.out.println("F");
		}
		catch(Exception e)
		{
           System.out.println(e.getMessage());
		}
	}
}
