package exp1;
import java.util.*;
public class TestDraw
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		Shape shape = null;
		int shapeNumber;
		System.out.print("Enter 1: LeftTriangle, 2: 7rows Diamond, 3: 8rows Diamond\n>>");
		shapeNumber = input.nextInt();

		switch(shapeNumber)
		{
			case 1 : shape = new LeftTriangle(6, '*');
					break;
			case 2 : shape = new Diamond(7, '*');
					break;
			case 3 : shape = new Diamond(8, '*');
					break;
			default:
					System.out.println("Invalid entry");
					System.exit(0);
		}
		
		shape.draw(1,1);
		input.close();
	}
}