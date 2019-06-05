package Server;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

//import Client.FileListeningThread;

public class FileClientInfo {
	Socket s;
	String ip;
	String text;
	String msg;
	private boolean liveCheck = true;
	private boolean msgCheck = false;
	
	BufferedReader  inMsg;
	PrintWriter outMsg;
	
	public FileClientInfo(Socket s) {
		this.s = s;
		
		ip = s.getInetAddress().getHostAddress();
		
		FileClientSocketCheckThread FCSC = new FileClientSocketCheckThread(s, this);
		Thread fcsct = new Thread(FCSC);
		fcsct.start();
		
	}
	
	public void sendFile(String fileName) {
		File file = new File(fileName);
		FileInputStream fis = null;
		OutputStream os = null;
	    
	    try {
			outMsg = new PrintWriter(new OutputStreamWriter(s.getOutputStream(), StandardCharsets.UTF_8));
			inMsg = new BufferedReader(new InputStreamReader(s.getInputStream(), StandardCharsets.UTF_8));

	        fis = new FileInputStream(file);
	        os = s.getOutputStream();


		    int readBytes = 0;
		    byte[] buf = new byte[4096];

			String[] onlyFileName = fileName.split("\\\\");
			outMsg.println(onlyFileName[onlyFileName.length-1]);
			outMsg.flush();
			
			while (!msgCheck) { System.out.println(""); }
			if (msg.equals("FILEOK")) {
	            while ((readBytes = fis.read(buf)) != -1) {
	                os.write(buf, 0, readBytes);
	                Thread.sleep(200);
	            }
	            os.flush();
			}
	    } catch(Exception e) { System.out.println(e.getMessage()); }
	}
	
	public void setLive() { liveCheck = false; }	// ¼ÒÄÏ ´ÝÈú °æ¿ì
	
	public boolean getLive() { return liveCheck; }
	
	public boolean getMsgCheck() { return msgCheck; }
	
	public void setMsgCheck() { msgCheck = true; }
	
	public void setMsg(String msg) { this.msg = msg; } 
	
	public String getIp() { return ip; }
}
