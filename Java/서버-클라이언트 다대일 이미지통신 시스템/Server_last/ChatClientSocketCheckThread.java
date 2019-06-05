package Server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class ChatClientSocketCheckThread implements Runnable {
	BufferedReader  in;
	Socket s;
	String exit = "";
	String[] filterMsg;
	String space = "";
	ChatClientInfo cci;
	Server server;
	String nickName;
	public ChatClientSocketCheckThread(Socket s, ChatClientInfo cci,Server server,String Nickname) {
		this.s = s;
		this.cci = cci;
		this.server = server;
		this.nickName = Nickname;
		try {
			in = new BufferedReader(new InputStreamReader(s.getInputStream(), StandardCharsets.UTF_8));
		} catch(Exception e) {}
	}
	
	public void run() {
		try {
			while (true) {
				exit = in.readLine();
				server.globalChat.append(nickName+": "+exit+"\n");
				server.globalChat.setCaretPosition(server.globalChat.getText().length());
				server.globalChat.requestFocus();

				Thread.sleep(10);
				if (exit == null) {
					cci.setLive();
					return;
				} else {
					cci.setMsg();
					cci.setString(cci.getNickName() + " : " + exit);
				}
			}
		} catch (Exception e) {}
	}
}
