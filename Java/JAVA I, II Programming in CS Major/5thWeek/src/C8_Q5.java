import java.util.*;

public class C8_Q5 {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		String str=input.next();
		char c;
		int shift;
		
		for(int i=0; i<str.length(); i++)
		{
			shift=str.charAt(i)-'a';
			c=(char)(shift+'a');
			for(int j=0; j<26; j++)
			{
				if(c>'z')
					shift=-i;
				c=(char)(shift+'a'+j);
				if(c>='a' && c<='z')
					System.out.print(c);
				else
					j--;
			}
			System.out.println();


		}
		input.close();
	}
}
