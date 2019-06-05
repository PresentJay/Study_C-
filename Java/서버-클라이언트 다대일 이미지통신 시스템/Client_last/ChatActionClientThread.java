package Client;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class ChatActionClientThread implements Runnable {
	Socket s;
	String msg;
	ChatClient cc;
	BufferedReader  in;
	PrintWriter out;
	
	public ChatActionClientThread(Socket s, ChatClient cc) {
		this.s = s;
		this.cc = cc;
		
		try {
			out = new PrintWriter(new OutputStreamWriter(s.getOutputStream(), StandardCharsets.UTF_8));
			in = new BufferedReader(new InputStreamReader(s.getInputStream(), StandardCharsets.UTF_8));
		} catch(Exception e) {}
	}
	public void run() {
		try {
			while (true) {
				msg = in.readLine();
				cc.setOutputArea(msg);
			}
		} catch (Exception e) {}
	}
}
