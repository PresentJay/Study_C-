package Client;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
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
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.border.EtchedBorder;

public class ChatClient extends JFrame  implements ActionListener {
	JTextArea inputArea = new JTextArea(5, 20);
	JPanel sendPanel = new JPanel();
	JTextArea outputArea = new JTextArea();
	JButton send = new JButton("전송");
	Socket c_socket;
	String msg;
	BufferedReader  in;
	PrintWriter out;
	String serverIP;
	Client client;
	String[] filterMsg;
	String nickName;
	String space;
	JScrollPane inputScroll;
	JScrollPane outputScroll;
	
	public ChatClient(String serverIP, Client client, String nickName) {
		super("채팅");

		
		this.setSize(400, 600);
		this.serverIP = serverIP;
		this.client = client;
		this.nickName = nickName;
		this.setLocationRelativeTo(null);
		Container container = this.getContentPane();
		container.setLayout(new BorderLayout());
		
		sendPanel.setLayout(new BorderLayout());
		inputArea.setLineWrap(true);
		outputArea.setLineWrap(true);
		inputScroll = new JScrollPane(inputArea);
		send.addActionListener(this);
		sendPanel.add(inputScroll, BorderLayout.CENTER);
		sendPanel.add(send, BorderLayout.EAST);
		
		outputArea.setBorder(new EtchedBorder());
		outputArea.setEditable(false);
		outputScroll = new JScrollPane(outputArea);
		
		container.add(outputScroll, BorderLayout.CENTER);
		container.add(sendPanel, BorderLayout.SOUTH);
		
		try {
			c_socket = new Socket(serverIP, 5556);
			
			out = new PrintWriter(new OutputStreamWriter(c_socket.getOutputStream(), StandardCharsets.UTF_8));
			in = new BufferedReader(new InputStreamReader(c_socket.getInputStream(), StandardCharsets.UTF_8));
			
			out.println(nickName);
			out.flush();

		} catch (Exception e) {
			System.out.println(e.getStackTrace());
		}
		
		ChatActionClientThread CACT = new ChatActionClientThread(c_socket, this);
		Thread rt = new Thread(CACT);
		rt.start();
		
		// Enter KeydownEvent 발생 (전송버튼과 같은 기능) 
	      inputArea.addKeyListener(new KeyAdapter() {
	         public void keyPressed(KeyEvent e) {
	             if(e.getKeyCode() == KeyEvent.VK_ENTER && (e.getModifiers() & e.SHIFT_MASK) != 0){
	                 inputArea.setText(inputArea.getText() + "\n");
	             }
	             else if (e.getKeyCode() == 10) {
	        		 try {
	 	                  send.doClick();
	 	                  e.consume();
	        		 } catch (Exception exception) {} 
	        	 }
	         }
	      });
	      //
		
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				try {
					client.chatBtn.setEnabled(true);
					c_socket.close();
				} catch(Exception event) {}
			}
		});
		this.setVisible(true);
	}
	
	public void setOutputArea(String msg) {
		outputArea.setText(outputArea.getText() + msg + "\n");
		outputScroll.getVerticalScrollBar().setValue(outputScroll.getVerticalScrollBar().getMaximum());
	}
	
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand() == "전송") {
			try {
				msg = inputArea.getText();
				filterMsg = msg.split("\n");
				if (filterMsg.length > 1) {
					for (int i=0; i<filterMsg.length; i++) {
						out.println(filterMsg[i]);
						out.flush();
						Thread.sleep(10);
					}
				} else {
					Thread.sleep(10);
					out.println(msg);
					out.flush();
				}
				inputArea.setText("");
			} catch (Exception exception) {}
		}
	}
}
