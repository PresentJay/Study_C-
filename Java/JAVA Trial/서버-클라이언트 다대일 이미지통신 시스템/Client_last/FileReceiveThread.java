package Client;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class FileReceiveThread extends JFrame implements Runnable, ActionListener {
	Socket s;
	BufferedReader  inMsg;
	PrintWriter outMsg;
	String msg;
	String savePath;
	JLabel text = new JLabel("파일을 받으시겠습니까?");
	JButton yesBtn = new JButton("네");
	JButton noBtn = new JButton("아니오");
	String onlyFileName;
	FileListeningThread flt;
	
	JFileChooser jfc = new JFileChooser();
	public FileReceiveThread(Socket s, String onlyFileName, FileListeningThread flt) {
		this.s = s;
		this.onlyFileName = onlyFileName;
		this.flt = flt;
		
		this.setSize(200, 200);
		this.setLayout(new FlowLayout());
		this.add(text);
		this.add(yesBtn);
		this.add(noBtn);
		yesBtn.addActionListener(this);
		noBtn.addActionListener(this);
		
		jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
		
		try {
			outMsg = new PrintWriter(new OutputStreamWriter(s.getOutputStream(), StandardCharsets.UTF_8));
			inMsg = new BufferedReader(new InputStreamReader(s.getInputStream(), StandardCharsets.UTF_8));
		} catch (Exception e) {}
	}
	
	public void run() {
		this.setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand() == "네") {
			if(jfc.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
			    savePath = jfc.getSelectedFile().toString();
			}
			InputStream is = null;
			FileOutputStream fos = null;
		    
		    int readBytes = 0;
		    byte[] buf = new byte[4096];
		    
		    try {
				text.setText("다운중");
				yesBtn.setVisible(false);
				noBtn.setVisible(false);
			    outMsg.println("FILEOK");
			    outMsg.flush();
		    	is = s.getInputStream();
		    	fos = new FileOutputStream(savePath + "/" + onlyFileName);
		        while((readBytes = is.read(buf)) != -1) {
		        	fos.write(buf, 0, readBytes);
		        	if (readBytes < 4096) break;
		        }
		        flt.setStart();
		        fos.flush();
		        fos.close();
		    } catch(Exception error) {
		        System.out.println("파일 저장 에러 : " + error.getMessage() + "      " + onlyFileName);
		    } finally {
				FileListeningThread FL = new FileListeningThread(s);
				Thread flt = new Thread(FL);
				flt.start();
		        dispose();
		    }
		} else if (e.getActionCommand() == "아니오") {	// 버퍼만 비우기
			InputStream is = null;
		    
		    int readBytes = 0;
		    byte[] buf = new byte[4096];
		    try {
			    outMsg.println("FILEOK");
			    outMsg.flush();
		    	is = s.getInputStream();

		        while((readBytes = is.read(buf)) != -1) {
		        	if (readBytes < 4096) break;
		        }
		    } catch(Exception error) {
		        System.out.println("파일 저장 에러 : " + error.getMessage() + "      " + onlyFileName);
		    } finally {
		        dispose();
		    }
		}
	}
}
