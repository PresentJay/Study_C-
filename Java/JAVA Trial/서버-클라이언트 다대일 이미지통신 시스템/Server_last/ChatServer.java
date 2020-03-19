package Server;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.Map;
import java.util.Vector;

public class ChatServer implements Runnable {
	ServerSocket s_socketChat;
	BufferedReader  in;
	PrintWriter out;
	Vector v;
	Server server;
	String nickName;
	
	public ChatServer(Server server) {
		this.server = server;
		
		try {
			s_socketChat = new ServerSocket(5556);
			v = new Vector();
			
		} catch(Exception e) {}
	}
	
	public void run() {
		try {
			ChatServerThread CST = new ChatServerThread(v, server);
			Thread ct = new Thread(CST);
			ct.start();
			while (true) {
				Socket socketChat = s_socketChat.accept();
				
				out = new PrintWriter(new OutputStreamWriter(socketChat.getOutputStream(), StandardCharsets.UTF_8));
				in = new BufferedReader(new InputStreamReader(socketChat.getInputStream(), StandardCharsets.UTF_8));
				
				nickName = in.readLine();
				System.out.println(nickName);
				
				ChatClientInfo ci = new ChatClientInfo(socketChat, nickName, server);
				v.add(ci);
			}
		} catch(Exception e) {}
	}
}
