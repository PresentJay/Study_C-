package Client;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

import javax.swing.JButton;
import javax.swing.JFrame;

public class Client extends JFrame implements ActionListener {
	
	JButton mirroringBtn = new JButton("�̷���");
	JButton chatBtn = new JButton("ä��");
	JButton LoginBtn = new JButton("�α���");
	JButton fileBoardBtn = new JButton("�����ڷ��");
	static String sessionID = "gg";
	Thread ct;
	Socket s;
	PrintWriter outMsg;
	String serverIP;
	String nickName;
	static boolean live = true;
	
	public Client(Socket s, String serverIP, String nickName) {
		super("Client");
		
		this.s = s;
		this.serverIP = serverIP;
		this.nickName = nickName;
		this.setSize(300, 300);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		this.setLayout(new FlowLayout());
		
		this.add(mirroringBtn);
		this.add(chatBtn);
		this.add(LoginBtn);
		this.add(fileBoardBtn);
		mirroringBtn.addActionListener(this);
		chatBtn.addActionListener(this);
		LoginBtn.addActionListener(this);
		fileBoardBtn.addActionListener(this);
		fileBoardBtn.setVisible(false);
		
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				try {
					live = false;
					s.close();
				} catch(Exception event) {}
			}
		});
	}
	
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand() == "�̷���") {
			MirroringClientThread MCT = new MirroringClientThread(serverIP, this);
			Thread mt = new Thread(MCT);
			mt.start();
			mirroringBtn.setEnabled(false);
		} else if (e.getActionCommand() == "ä��") {
			ChatClientThread CCT = new ChatClientThread(serverIP, this, nickName);
			ct = new Thread(CCT);
			ct.start();
			chatBtn.setEnabled(false);
		} else if (e.getActionCommand() == "�α���") {
			LoginView loginView = new LoginView(sessionID, this);
		} else if (e.getActionCommand() == "�����ڷ��") {
			Board board = new Board(sessionID);
		}
	}
	
	public static void main(String[] args) {
		ConnectionServer connectionServer = new ConnectionServer();
		connectionServer.setVisible(true);
	}
	
	public boolean getLive() { return live; }
	
	public void setSessionID(String si) { sessionID =si; } 
}
