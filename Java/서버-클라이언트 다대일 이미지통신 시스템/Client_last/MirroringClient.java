package Client;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedInputStream;
import java.net.Socket;

import javax.imageio.ImageIO;
import javax.swing.JFrame;

public class MirroringClient extends JFrame {
	Socket c_socket;
	String serverIP;
	Client client;
	
	public MirroringClient(String serverIP, Client client) {
		super("MirroringClient");
		
		this.serverIP = serverIP;
		this.client = client;
		this.setSize(1600, 900);
		this.setLocationRelativeTo(null);
		this.setVisible(true);

		try {
			c_socket = new Socket(serverIP, 5555);
		} catch (Exception e) {}
		
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				try {
					client.mirroringBtn.setEnabled(true);
					c_socket.close();
				} catch(Exception event) {}
			}
		});
		
		MirroringClientPrintThread MCP = new MirroringClientPrintThread(c_socket, this);
		Thread mcpt = new Thread(MCP);
		mcpt.start();
	}
}