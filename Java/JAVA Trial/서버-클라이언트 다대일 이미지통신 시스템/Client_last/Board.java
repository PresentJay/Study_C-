package Client;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class Board extends JFrame implements ActionListener {
	String sessionID;
	int page = 1;
	String[] URL = new String[17];
	JFileChooser jfc = new JFileChooser();
	
	JLabel[] numLabel = new JLabel[17];
	JLabel[] titleLabel = new JLabel[17];
	JButton[] downBtn = new JButton[17];
	
	JLabel currentPage = new JLabel("1");
	
	public Board(String sessionID) {
		super("수업자료실");
		this.setSize(1000, 500);
		this.sessionID = sessionID;
		
		jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
		Container container = this.getContentPane();
		container.setLayout(new BorderLayout());
		
		
		// 상단 목록
		JPanel TopPanel = new JPanel();
		TopPanel.setLayout(new GridLayout(1,3));
		
		JLabel numList = new JLabel("       번호(날짜)");
		JLabel titleList = new JLabel("제목");
		JLabel downList = new JLabel("");
		TopPanel.add(numList);
		TopPanel.add(titleList);
		TopPanel.add(downList);
		
		container.add(TopPanel, BorderLayout.NORTH);
		
		// 센터 리스트
		JPanel CenterPanel = new JPanel();
		CenterPanel.setLayout(new GridLayout(17, 4));
		

		for (int i=0; i<17; i++) {
			numLabel[i] = new JLabel("       notice");
			titleLabel[i] = new JLabel("title");
			downBtn[i] = new JButton("다운로드");
			
			downBtn[i].addActionListener(this);
			CenterPanel.add(numLabel[i]);
			CenterPanel.add(titleLabel[i]);
			CenterPanel.add(downBtn[i]);
		}
		
		container.add(CenterPanel, BorderLayout.CENTER);
		// 바텀 페이지 이동
		JPanel BottomPanel = new JPanel();
		BottomPanel.setLayout(new FlowLayout());
		
		JButton PreBtn = new JButton("<");
		JButton NextBtn = new JButton(">");
		
		BottomPanel.add(PreBtn);
		BottomPanel.add(currentPage);
		BottomPanel.add(NextBtn);
		PreBtn.addActionListener(this);
		NextBtn.addActionListener(this);
		
		
		container.add(BottomPanel, BorderLayout.SOUTH);
		
		getBoardNum(page);
		getBoardTitle(page);
		this.setVisible(true);
	}
	
	public void getBoardNum(int page) {
		try {
			int j = 6;	// 게시판 첫 번호의 배열
			Document doc = Jsoup.connect("http://cs.inje.ac.kr/bbs/board.php?bo_table=data&page=" + page)
					.cookie("PHPSESSID", sessionID)
					.get();
			
			Elements numElement = doc.getElementsByTag("span");
			
			for (int i=2; i<17; i++) {
				Element num = numElement.get(j);
				numLabel[i].setText(num.text());
				num = numElement.get(j-2);
				numLabel[i].setText("      " + numLabel[i].getText() + "     " + num.text());
				j = j + 4;
			}
		} catch (Exception e) { System.out.println(e.getMessage()); }
	}
	
	public void getBoardTitle(int page) {
		try {
			Document doc = Jsoup.connect("http://cs.inje.ac.kr/bbs/board.php?bo_table=data&page=" + page)
					.cookie("PHPSESSID", sessionID)
					.get();
			
			Elements titleElement = doc.getElementsByClass("12font");
			
			for (int i=0; i<17; i++) {
				Element title = titleElement.get(i);
				titleLabel[i].setText(title.text());
				URL[i] = title.getElementsByTag("a").attr("href");
			}
		} catch (Exception e) { System.out.println(e.getMessage()); }
	}
	
	
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand() == ">") {
			if (page < 7) {
				page++;
				getBoardNum(page);
				getBoardTitle(page);
				currentPage.setText("" + page);
			}
		} else if (e.getActionCommand() == "<") {
			if (page > 1) {
				page--;
				getBoardNum(page);
				getBoardTitle(page);
				currentPage.setText("" + page);
			}
		} else if (e.getActionCommand() == "다운로드") {
			for (int i = 0; i<17; i++) {
				if (e.getSource() == downBtn[i]) {
					  if(jfc.showOpenDialog(this) == JFileChooser.APPROVE_OPTION){
						  FileDownThread FD = new FileDownThread(URL[i].substring(2), jfc.getSelectedFile().toString(), sessionID);
						  Thread fdt = new Thread(FD);
						  fdt.start();
                  }
				}
			}
		}
	}
}
