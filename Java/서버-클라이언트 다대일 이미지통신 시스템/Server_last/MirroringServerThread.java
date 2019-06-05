package Server;

import java.awt.Rectangle;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.io.BufferedOutputStream;
import java.util.Vector;

import javax.imageio.ImageIO;

public class MirroringServerThread implements Runnable {
	Vector v;
	Server server;
	String chatMirroringCnt = "";
	String chatMirroringList = "";
	int currentVectorSize = 0;
	int preVectorSize = 0;
	
	public MirroringServerThread(Vector v, Server server) {
		this.v= v;
		this.server = server;
	}
	
	public void run() {
		while (true) {
			try {
				currentVectorSize = v.size();
				for (int i=0; i<v.size(); i++) {
					MirroringClientInfo ci = (MirroringClientInfo)v.get(i);
					if (!ci.getWriteRun()) {
						ci.write();
						ci.setWriteRun();
					}
					if (!ci.getLiveCheck()) {
						v.remove(i);
						i--;
						currentVectorSize--;
					}
					chatMirroringList = chatMirroringList + ci.getIp() + "\n";
				}
			} catch(Exception e) {}
			//if (v.size() == 0) chatMirroringList = "";
			chatMirroringCnt = "미러링 접속 IP 목록 (" + v.size() + "명)\n";
			/*if (currentVectorSize != preVectorSize)*/ server.setMirroringUserStr(chatMirroringCnt, chatMirroringList);
			chatMirroringCnt = "";
			chatMirroringList = "";
			preVectorSize = currentVectorSize;
		}
	}
}
