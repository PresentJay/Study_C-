package Server;

import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;

public class FileSendServer implements Runnable {
	Server server;
	ServerSocket s_socketFile;
	Vector v;
	
	public FileSendServer(Server server, Vector v) {
		this.server = server;
		this.v = v;
		
		try {
			s_socketFile = new ServerSocket(5557);
		} catch(Exception e) {}
	}
	
	public void run() {
		try {
			FileSendServerThread FSS = new FileSendServerThread(v, server);
			Thread fsst = new Thread(FSS);
			fsst.start();
			while (true) {
				Socket socketFile = s_socketFile.accept();
				
				FileClientInfo fc = new FileClientInfo(socketFile);
				v.add(fc);
			}
		} catch(Exception e) {}
	}
}
