package exp6;
import java.util.*;
public class Express_Integer {
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		String address;
		String temp="";

		System.out.print("당신의 주소는?:");
		address=input.nextLine();

        for(int i=0;i<address.length();i++)
			if(address.charAt(i)>='0' && address.charAt(i)<='9') temp+=address.charAt(i);
		System.out.println("당신의 상금은: "+Integer.parseInt(temp)+"$ 입니다.");
		input.close();
	}
}
