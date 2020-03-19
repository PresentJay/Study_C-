package Server;

import java.util.Vector;

public class FileSendServerThread implements Runnable {
	String msg;
	Vector v;
	Server server;
	String fileUserCnt = "";
	String fileUserList = "";
	int currentVectorSize = 0;
	int preVectorSize = 0;
	
	public FileSendServerThread(Vector v, Server server) {
		this.v = v;
		this.server = server;
	}
	
	public void run() {
		while (true) {
			try {
				while (true) {
					currentVectorSize = v.size();
					for (int i=0; i<v.size(); i++) {
						FileClientInfo fi = (FileClientInfo)v.get(i);
						if (!fi.getLive()) {
							v.remove(i);
							i--;
							currentVectorSize--;
						} else {
							fileUserList = fileUserList + fi.getIp() + "\n";
						}
					}
					if (v.size() == 0) fileUserList = "";
					fileUserCnt = "현재 모든 접속 IP 목록 (" + v.size() + "명)\n";
					if (currentVectorSize != preVectorSize)  server.setFileUserStr(fileUserCnt, fileUserList);
					fileUserCnt = "";
					fileUserList = "";
					preVectorSize = currentVectorSize;
				}
			} catch(Exception e) {}
		}
	}
}
