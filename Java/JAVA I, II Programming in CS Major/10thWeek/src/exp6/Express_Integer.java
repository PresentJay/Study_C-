package exp6;
import java.util.*;
public class Express_Integer {
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		String address;
		String temp="";

		System.out.print("����� �ּҴ�?:");
		address=input.nextLine();

        for(int i=0;i<address.length();i++)
			if(address.charAt(i)>='0' && address.charAt(i)<='9') temp+=address.charAt(i);
		System.out.println("����� �����: "+Integer.parseInt(temp)+"$ �Դϴ�.");
		input.close();
	}
}
