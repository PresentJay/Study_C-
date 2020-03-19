package Server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class ChatClientInfo {
	BufferedReader  in;
	PrintWriter out;
	String ip;
	String nickName;
	Socket s;
	Server Sv;
	private boolean liveCheck = true;
	private boolean msgCheck = false;
	private String msg;
	
	public ChatClientInfo(Socket s, String nickName,Server server) {
		this.s = s;
		this.nickName = nickName;
		this.Sv = server;
		ip = s.getInetAddress().getHostAddress();
		try {
			out = new PrintWriter(new OutputStreamWriter(s.getOutputStream(), StandardCharsets.UTF_8));
			in = new BufferedReader(new InputStreamReader(s.getInputStream(), StandardCharsets.UTF_8));
			
			ChatClientSocketCheckThread CCSC = new ChatClientSocketCheckThread(s, this,Sv,nickName);
			Thread ccsct = new Thread(CCSC);
			ccsct.start();
			
		} catch(Exception e) {}
	}
	
	public boolean write(String msg) {
		try {
			out.println(msg);
			out.flush();
		} catch(Exception e) {}
		return true;
	}
	
	public void setLive() { liveCheck = false; }	// ¼ÒÄÏ ´ÝÈú °æ¿ì
	
	public boolean getLive() { return liveCheck; }
	
	public void setString(String str) { msg = str; }
	
	public String getString() { return msg; }
	
	public void setMsg() { msgCheck = !msgCheck; }
	
	public boolean getMsgCheck() { return msgCheck; }
	
	public String getIp() { return ip; }
	
	public String getNickName() { return nickName; }
}
