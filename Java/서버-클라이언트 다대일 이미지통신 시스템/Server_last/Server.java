package Server;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class Server extends JFrame implements ActionListener {
	JPanel listPanel = new JPanel();
	JTextArea chatList = new JTextArea(20, 20);
	JTextArea mirroringList = new JTextArea(20, 20);
	JTextArea fileList = new JTextArea(20, 20);
	JTextArea globalChat = new JTextArea(20, 20);
	JButton fileSend = new JButton("파일전송");
	JFileChooser jfc = new JFileChooser();
	
	static Vector fileVector = new Vector();
	
	
	public Server() {
		super("Server");
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(1000, 500);
		this.setLocationRelativeTo(null);
		
		Container container = this.getContentPane();
		container.setLayout(new BorderLayout());
		
		listPanel.setLayout(new FlowLayout());
		
		globalChat.setEditable(false);
		chatList.setEditable(false);
		mirroringList.setEditable(false);
		fileList.setEditable(false);
		
		chatList.setText("채팅 접속 IP 목록 (0명)\n");
		mirroringList.setText("미러링 접속 IP 목록 (0명)\n");
		fileList.setText("현재 모든 접속 IP 목록 (0명)\n");

		JScrollPane globalChatScroll = new JScrollPane(globalChat);
		JScrollPane chatListScroll = new JScrollPane(chatList);
		JScrollPane mirroringListScroll = new JScrollPane(mirroringList);
		JScrollPane fileListScroll = new JScrollPane(fileList);
		
		listPanel.add(globalChatScroll);
		listPanel.add(chatListScroll);
		listPanel.add(mirroringListScroll);
		listPanel.add(fileListScroll);
		
		fileSend.addActionListener(this);
		
		container.add(listPanel, BorderLayout.NORTH);
		container.add(fileSend, BorderLayout.CENTER);
		
		
		try {
				ChatServer CS = new ChatServer(this);
				Thread cst = new Thread(CS);
				cst.start();
				
				MirroringServer MS = new MirroringServer(this);
				Thread mst = new Thread(MS);
				mst.start();
				
				FileSendServer FS = new FileSendServer(this, fileVector);
				Thread fst = new Thread(FS);
				fst.start();
		} catch(Exception e) {}
	}
	
	public void setChatUserStr(String str, String str2) {
		chatList.setText(str + str2);
	}
	
	public void setMirroringUserStr(String str, String str2) {
		mirroringList.setText(str + str2);
	}
	
	public void setFileUserStr(String str, String str2) {
		fileList.setText(str + str2);
	}
	
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand() == "파일전송") {
			if(jfc.showOpenDialog(this) == JFileChooser.APPROVE_OPTION){
				for (int i=0; i<fileVector.size(); i++) {
					FileSendThread FS = new FileSendThread((FileClientInfo)fileVector.get(i), jfc.getSelectedFile().toString());
					Thread fst = new Thread(FS);
					fst.start();
				}
			}
		}
	}
	public static void main(String[] args) {
		Server server = new Server();
		server.setVisible(true);
	}
}
