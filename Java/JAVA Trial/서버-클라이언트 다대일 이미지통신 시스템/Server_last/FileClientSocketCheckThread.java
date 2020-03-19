package Server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class FileClientSocketCheckThread implements Runnable {
	BufferedReader  in;
	Socket s;
	String exit = "";
	FileClientInfo fci;
	
	public FileClientSocketCheckThread(Socket s, FileClientInfo fci) {
		this.s = s;
		this.fci = fci;
		
		try {
			in = new BufferedReader(new InputStreamReader(s.getInputStream(), StandardCharsets.UTF_8));
		} catch(Exception e) {}
	}
	
	public void run() {
		try {
			while (true) {
				exit = in.readLine();
				if (exit == null) {
					fci.setLive();
					return;
				} else {
					fci.setMsgCheck();
					fci.setMsg(exit);
				}
			}
		} catch (Exception e) {}
	}
}
