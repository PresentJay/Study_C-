package Server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.Vector;

public class ChatServerThread implements Runnable {
	String msg;
	Vector v;
	Server server;
	String chatUserCnt = "";
	String chatUserList = "";
	int currentVectorSize = 0;
	int preVectorSize = 0;
	
	public ChatServerThread(Vector v, Server server) {
		this.v = v;
		this.server = server;
	}
	
	public void run() {
		while (true) {
			try {
				while (true) {
					currentVectorSize = v.size();
					for (int i=0; i<v.size(); i++) {
						ChatClientInfo ci = (ChatClientInfo)v.get(i);
						if (!ci.getLive()) {
							v.remove(i);
							i--;
							currentVectorSize--;
						}
						chatUserList = chatUserList + ci.getIp() + "\n";
						if (ci.getMsgCheck()) {
							msg = ci.getString();
							ci.setMsg();
							for (i=0; i<v.size(); i++) {
								ChatClientInfo ci2 = (ChatClientInfo)v.get(i);
								ci2.write(msg);
								//System.out.println("ChatServerThread ->" + msg);
							}
						}
					}
					//if (v.size() == 0) chatUserList = "";
					chatUserCnt = "채팅 접속 IP 목록 (" + v.size() + "명)\n";
					/*if (currentVectorSize != preVectorSize)*/ server.setChatUserStr(chatUserCnt, chatUserList);
					chatUserCnt = "";
					chatUserList = "";
					preVectorSize = currentVectorSize;
				}
			} catch(Exception e) {}
		}
	}
}
