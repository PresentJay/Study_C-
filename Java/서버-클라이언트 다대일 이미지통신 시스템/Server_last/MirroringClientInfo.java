package Server;

import java.awt.Rectangle;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.io.BufferedOutputStream;
import java.net.Socket;

import javax.imageio.ImageIO;

public class MirroringClientInfo {
	Socket s;
	String ip;
	private boolean writeRun = false;
	private boolean liveCheck = true;
	
	public MirroringClientInfo(Socket s) {
		this.s = s;
		ip = s.getInetAddress().getHostAddress();
		
		MirroringClientSocketCheckThread MCSC = new MirroringClientSocketCheckThread(s, this);
		Thread mcsct = new Thread(MCSC);
		mcsct.start();
	}
	
	public void write() {
		MirroringServerDrawingThread MSD = new MirroringServerDrawingThread(s);
		Thread msdt = new Thread(MSD);
		msdt.start();
	}
	
	public void setWriteRun() { writeRun = true; }
	
	public boolean getWriteRun() { return writeRun; }
	
	public void setLiveCheck() { liveCheck = false; }
	
	public boolean getLiveCheck() { return liveCheck; }
	
	public String getIp() { return ip; }
}
