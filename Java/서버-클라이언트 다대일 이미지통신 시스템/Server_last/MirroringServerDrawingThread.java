package Server;

import java.awt.Rectangle;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.io.BufferedOutputStream;
import java.net.Socket;

import javax.imageio.ImageIO;

public class MirroringServerDrawingThread implements Runnable {
	BufferedImage image;
	Robot r;
	BufferedOutputStream b_out;
	Socket s;
	
	public MirroringServerDrawingThread(Socket s) {
		this.s = s;
	}
	public void run() {
		try {
			r = new Robot();
			b_out = new BufferedOutputStream(s.getOutputStream());
			while (true) {
				image = r.createScreenCapture(new Rectangle(0, 0, Toolkit.getDefaultToolkit().getScreenSize().width, Toolkit.getDefaultToolkit().getScreenSize().height));
				ImageIO.write(image, "bmp", b_out);
				b_out.flush();
			}
		} catch(Exception e) {}
	}
}
