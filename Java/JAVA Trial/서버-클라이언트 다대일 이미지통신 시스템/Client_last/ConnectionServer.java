package Client;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.Socket;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class ConnectionServer extends JFrame implements ActionListener {
	String serverIP;
	String nickName;
	Socket s;
	JTextField inputIP;
	JTextField inputID;
	JLabel text;
	JLabel id;
	JButton send;
	JButton ok;
	JButton reInput;
	
	
	public ConnectionServer() {
		super("대기중");
		
		this.setSize(250, 200);
		this.setLayout(new FlowLayout());
		this.setLocationRelativeTo(null);
		
		text = new JLabel("서버 IP ");
		inputIP = new JTextField(16);
		id = new JLabel("사용할 아이디 ");
		inputID = new JTextField(10);
		send = new JButton("접속");
		ok = new JButton("확인");
		reInput = new JButton("다시 입력");
		
		send.addActionListener(this);
		reInput.addActionListener(this);
		ok.addActionListener(this);
		
		this.add(text);
		this.add(inputIP);
		this.add(id);
		this.add(inputID);
		this.add(send);
		this.add(ok);
		this.add(reInput);
		
		reInput.setVisible(false);
		ok.setVisible(false);
		this.setResizable(false);
	}
	
	
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand() == "접속") {
			serverIP = inputIP.getText();
			nickName = inputID.getText();
			if (nickName.equals("")) { JOptionPane.showMessageDialog(null, "닉네임을 입력해주세요", "실패", JOptionPane.WARNING_MESSAGE); }
			else {
				try {
					s = new Socket(serverIP, 5557);
					text.setText("접속 성공!");
					inputIP.setVisible(false);
					send.setVisible(false);
					ok.setVisible(true);
					id.setVisible(false);
					inputID.setVisible(false);
				} catch (Exception error) {
					text.setText("접속 실패");
					send.setVisible(false);
					reInput.setVisible(true);
					inputIP.setVisible(false);
					id.setVisible(false);
					inputID.setVisible(false);
				}
			}
		} else if (e.getActionCommand() == "확인") {
			FileListeningThread FL = new FileListeningThread(s);
			Thread flt = new Thread(FL);
			flt.start();
			
			Client client = new Client(s, serverIP, nickName);
			client.setVisible(true);
			dispose();
		} else if (e.getActionCommand() == "다시 입력") {
			text.setText("서버 IP ");
			reInput.setVisible(false);
			inputIP.setVisible(true);
			send.setVisible(true);
			id.setVisible(true);
			inputID.setVisible(true);
		}
	}
}
