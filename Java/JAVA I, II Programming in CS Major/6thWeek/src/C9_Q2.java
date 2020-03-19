
public class C9_Q2 {
	private int squ;

	public C9_Q2(){
		squ = 5;
	}
	public C9_Q2(int n){
		squ = n;
	}
	public int rollDice(){
		return (int)(Math.random()*squ + 1);
	}
	public int squValue(){
		return squ;
	}
	public int resqu(int n){
		squ = n;
		return squ;
	}
	
	public static void main(String[] args)
	{
		C9_Q2 Roll1 = new C9_Q2();
		C9_Q2 Roll2 = new C9_Q2(5);

		System.out.println("Roll1의 초기 면의 개수: "+Roll1.squValue());
		System.out.println("Roll1 주사위 굴린 결과: "+Roll1.rollDice());
		System.out.println("Roll1 주사위 면의 개수 수정 후: "+Roll1.resqu(16));
		System.out.println("Roll2의 초기 면의 개수: "+Roll2.squValue());
	}
	
}

