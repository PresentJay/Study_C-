package Client;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URL;
import java.net.URLConnection;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class FileDownThread extends JFrame implements Runnable, ActionListener {
	String boardURL;
	String savePath;
	String sessionID;
	static String[] fileNameAndUrl;
	static JLabel str;
	static JButton yesBtn = new JButton("확인");
	
	public FileDownThread(String boardURL, String savePath, String sessionID) {
		super("다운중");
		
		this.setSize(200, 100);
		this.boardURL = boardURL;
		this.savePath = savePath;
		this.sessionID = sessionID;
		
		this.setLayout(new BorderLayout());
		str = new JLabel("다운중");
		this.add(str, BorderLayout.NORTH);
		this.add(yesBtn, BorderLayout.SOUTH);
		yesBtn.setVisible(false);
		yesBtn.addActionListener(this);
		this.setVisible(true);
	}
	
	public void run() {
		try {
			Document doc = Jsoup.connect("http://cs.inje.ac.kr" + boardURL)
					.cookie("PHPSESSID", sessionID)
					.get();
			
			Elements fileElements = doc.getElementsByTag("a");

			int j = 7;
			while (true) {
				Element file = fileElements.get(j);
				fileNameAndUrl = file.attr("href").split("'");
				
				if(fileNameAndUrl[0].equals("")) break;

				saveAttach("http://cs.inje.ac.kr/bbs" + fileNameAndUrl[1].substring(1), fileNameAndUrl[3], sessionID, savePath);
				j++;
			}
			Thread.sleep(1000);
			str.setText("다운완료!");
			yesBtn.setVisible(true);
		} catch (Exception e) { System.out.println(e.getMessage()); }
	}
	
	private static void saveAttach(String url, String fileName, String sessionID, String savePath) {
	    File dir = new File(savePath + '/');

	    if(!dir.exists()) {
	        dir.mkdirs();
	    }

	    URL fileUrl = null;
	    URLConnection urlConn = null;
	    InputStream is = null;
	    OutputStream os = null;

	    int readBytes = 0;
	    byte[] buf = new byte[4096];

	    try {
	    	System.out.println(url + " << url");
	        fileUrl = new URL(url);
	        urlConn = fileUrl.openConnection();
	        urlConn.setRequestProperty("Cookie", "PHPSESSID="+sessionID);
	        urlConn.connect();

	        is = urlConn.getInputStream();
	        os = new BufferedOutputStream(new FileOutputStream(savePath + '/' + fileName));

	        while((readBytes = is.read(buf)) != -1) {
	            os.write(buf, 0, readBytes);
	        }
	    } catch(Exception e) {
	        System.out.println("파일 저장 에러 : " + e.getMessage());
	    } finally {
	        if(is != null) try { is.close(); } catch(Exception ignore) {}
	        if(os != null) try { os.close(); } catch(Exception ignore) {}
	    }
	}
	
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand() == "확인") {
			dispose();
		}
	}
}
