public class C9_Q1 {
	private boolean isOn;
	private int Volume;
	private int Channel;

	C9_Q1() {
		isOn = false;
		Volume = 10;
		Channel = 2;
	}

	C9_Q1(boolean S, int V, int C) {
		isOn = S;
		Volume = V;
		Channel = C;
	}

	public void Volume_Up() {
		if (Volume != 20)
			Volume++;
		else
			System.out.println("볼륨이 최대치입니다.");
		System.out.println("Volume >> " + Volume);
	}

	public void Volume_Down() {
		if (Volume != 0)
			Volume--;
		else
			System.out.println("볼륨이 최저치입니다.");
		System.out.println("Volume >> " + Volume);
	}

	public void Channel_Up() {
		if(Channel < 99) Channel++; else Channel = 1;
		System.out.println("Channel >> " + Channel);
	}
	
	public void Channel_Down() {
		if(Channel > 1) Channel--; else Channel = 99;
		System.out.println("Channel >> " + Channel);
	}
	
	public void Status_Channel() {
		System.out.println("Channel >> " + Channel);
	}

	public void Status_Volume() {
		System.out.println("Volume >> " + Volume);
	}

	public void Status_Show() {
		System.out.println("is it turned on? >> " + isOn);
		Status_Volume();
		Status_Channel();
	}

	public static void main(String[] args) {
		C9_Q1 TV1 = new C9_Q1();
		TV1.Status_Show();
		C9_Q1 TV2 = new C9_Q1(true,20,99);
		TV2.Channel_Up();
		TV2.Volume_Up();
		TV2.Status_Show();
	}

}