package Client;

import java.io.BufferedInputStream;
import java.net.Socket;

import javax.imageio.ImageIO;

public class MirroringClientPrintThread implements Runnable {
	Socket c_socket;
	MirroringClient mc;
	
	public MirroringClientPrintThread(Socket c_socket, MirroringClient mc) {
		this.mc = mc;
		this.c_socket = c_socket;
	}
	
	public void run() {
		try {
			BufferedInputStream b_in = new BufferedInputStream(c_socket.getInputStream());
			while (true) {
				mc.getGraphics().drawImage(ImageIO.read(ImageIO.createImageInputStream(b_in)), 0, 0, 1600, 900, mc);
			}
		} catch (Exception e) { System.out.println(e.getMessage()); }
	}
}
