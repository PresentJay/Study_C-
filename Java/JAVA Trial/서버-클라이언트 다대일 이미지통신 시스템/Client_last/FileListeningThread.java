package Client;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class FileListeningThread implements Runnable {
	Socket s;
	BufferedReader  inMsg;
	PrintWriter outMsg;
	String msg;
	boolean start = true;

	public FileListeningThread(Socket s) {
		this.s = s;

		try {
			outMsg = new PrintWriter(new OutputStreamWriter(s.getOutputStream(), StandardCharsets.UTF_8));
			inMsg = new BufferedReader(new InputStreamReader(s.getInputStream(), StandardCharsets.UTF_8));
		} catch (Exception e) {}
	}
	
	public void run() {
			try {
				msg = inMsg.readLine();
				System.out.println(msg);
				FileReceiveThread FR = new FileReceiveThread(s, msg, this);
				Thread frt = new Thread(FR);
				frt.start();
			} catch (Exception e) { System.out.println(e.getMessage() + "??"); }
		}
	
	public void setStart() { start = true; }
}
