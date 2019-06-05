package Server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class MirroringClientSocketCheckThread implements Runnable {
	BufferedReader  in;
	Socket s;
	MirroringClientInfo mci;
	String exit;
	
	public MirroringClientSocketCheckThread(Socket s, MirroringClientInfo mci) {
		this.s = s;
		this.mci = mci;
		
		try {
			in = new BufferedReader(new InputStreamReader(s.getInputStream(), StandardCharsets.UTF_8));
		} catch(Exception e) {}
	}
	
	public void run() {
		try {
			while (true) {
				exit = in.readLine();
				if (exit == null) {
					mci.setLiveCheck();
					return;
				}
			}
		} catch (Exception e) {}
	}
}
