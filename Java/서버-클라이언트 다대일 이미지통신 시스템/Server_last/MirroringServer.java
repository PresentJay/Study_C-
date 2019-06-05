package Server;

import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;

public class MirroringServer implements Runnable {
	ServerSocket s_socketMirroring;
	private int mirroringUserCnt = 0;
	Vector v;
	Server server;
	
	public MirroringServer(Server server) {
		this.server = server;
		try {
			s_socketMirroring = new ServerSocket(5555);
			v = new Vector();
		} catch (Exception e) {}
	}
	public void run() {
		try {
			MirroringServerThread CST = new MirroringServerThread(v, server);
			Thread ct = new Thread(CST);
			ct.start();
			while (true) {
				Socket socketMirroring = s_socketMirroring.accept();
				
				MirroringClientInfo ci = new MirroringClientInfo(socketMirroring);
				v.add(ci);
				System.out.println(socketMirroring);
			}
		} catch(Exception e) {}
	}
}
