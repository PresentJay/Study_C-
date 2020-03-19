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
		System.out.print("시험점수 : ");
		inputgrade=input.next();
		grade=Integer.parseInt(inputgrade);
	    }
	    catch(NumberFormatException a)
	    {
			System.out.println("문자는 입력이 불가합니다.");
			System.exit(0);
		}

        try
        {
			if(grade>100 || grade<0)
			{
				Exception e=new Exception("0~100사이 숫자를 넣어주십시오");
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
