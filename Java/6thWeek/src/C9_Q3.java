public class C9_Q3{
	C9_Q2[] SDice = new C9_Q2[20];
	private int num=0;
	public C9_Q3(){
		C9_Q2 roll1 = new C9_Q2(6);
		SDice[0] = roll1;
		num = 1;
	}
	public C9_Q3(int n, int m){
		for(int i=0;i<m;i++){
			C9_Q2[] roll = new C9_Q2[m];
			roll[i] = new C9_Q2(n);
			SDice[i] = roll[i];
		}
		num = m;
	}
	public void reFace(int n,int m){
		SDice[n].resqu(m);
	}
	public void faceValue(int n){
		SDice[n].squValue();
	}
	public int rollDice(){
		int rollSum = 0;
		for(int i=0;i<num;i++){
		rollSum += SDice[i].rollDice();
		}
		return rollSum;
	}
	
	public static void main(String[] args)
	{
		C9_Q3 Roll1 = new C9_Q3();
		C9_Q3 Roll2 = new C9_Q3(2,3);
		C9_Q3 Roll3= new C9_Q3(10,3);

		int i,sum=0;
		for(i=0;i<100;i++)
		{
			sum += Roll1.rollDice();
		}
		System.out.println(sum/100);
		sum = 0;
		for(i=0;i<100;i++)
		{
			sum += Roll2.rollDice();
		}
		System.out.println(sum/100);
		sum = 0;
		for(i=0;i<100;i++)
		{
			sum += Roll3.rollDice();
		}
		System.out.println(sum/100);
		sum = 0;
	}
}


