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
		super("�����");
		
		this.setSize(250, 200);
		this.setLayout(new FlowLayout());
		this.setLocationRelativeTo(null);
		
		text = new JLabel("���� IP ");
		inputIP = new JTextField(16);
		id = new JLabel("����� ���̵� ");
		inputID = new JTextField(10);
		send = new JButton("����");
		ok = new JButton("Ȯ��");
		reInput = new JButton("�ٽ� �Է�");
		
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
		if (e.getActionCommand() == "����") {
			serverIP = inputIP.getText();
			nickName = inputID.getText();
			if (nickName.equals("")) { JOptionPane.showMessageDialog(null, "�г����� �Է����ּ���", "����", JOptionPane.WARNING_MESSAGE); }
			else {
				try {
					s = new Socket(serverIP, 5557);
					text.setText("���� ����!");
					inputIP.setVisible(false);
					send.setVisible(false);
					ok.setVisible(true);
					id.setVisible(false);
					inputID.setVisible(false);
				} catch (Exception error) {
					text.setText("���� ����");
					send.setVisible(false);
					reInput.setVisible(true);
					inputIP.setVisible(false);
					id.setVisible(false);
					inputID.setVisible(false);
				}
			}
		} else if (e.getActionCommand() == "Ȯ��") {
			FileListeningThread FL = new FileListeningThread(s);
			Thread flt = new Thread(FL);
			flt.start();
			
			Client client = new Client(s, serverIP, nickName);
			client.setVisible(true);
			dispose();
		} else if (e.getActionCommand() == "�ٽ� �Է�") {
			text.setText("���� IP ");
			reInput.setVisible(false);
			inputIP.setVisible(true);
			send.setVisible(true);
			id.setVisible(true);
			inputID.setVisible(true);
		}
	}
}
