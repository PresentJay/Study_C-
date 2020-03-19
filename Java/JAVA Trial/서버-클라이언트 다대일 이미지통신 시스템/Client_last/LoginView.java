package Client;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import org.jsoup.Connection;
import org.jsoup.Jsoup;
import org.jsoup.Connection.Method;

public class LoginView extends JFrame implements ActionListener {
	String sessionID;
	JButton loginBtn = new JButton("로그인");
	JTextField id = new JTextField(16);
	JPasswordField pw = new JPasswordField(16);
	JLabel idLabel = new JLabel("id : ");
	JLabel pwLabel = new JLabel("pw : ");
	Client c;
	public LoginView(String sessionID, Client c) {
		super("로그인");
		this.sessionID = sessionID;
		this.c = c;
		this.setSize(600, 100);
		
		Container container = this.getContentPane();
		container.setLayout(new BorderLayout());
		
		JPanel textPanel = new JPanel();
		textPanel.setLayout(new FlowLayout());
		loginBtn.addActionListener(this);
		textPanel.add(idLabel);
		textPanel.add(id);
		textPanel.add(pwLabel);
		textPanel.add(pw);
		textPanel.add(loginBtn);
		container.add(textPanel, BorderLayout.NORTH);
		
		this.setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e) {
		
		if (e.getActionCommand() == "로그인") {
			try {
				Connection.Response res = Jsoup.connect("http://cs.inje.ac.kr/bbs/login_check.php")
				          .data("mb_id", id.getText(), "mb_password", pw.getText())
				          .method(Method.POST)
				          .execute();
				sessionID = res.cookie("PHPSESSID");
				if (res.body().indexOf("history.go") > -1) {
					JOptionPane.showMessageDialog(null, "로그인 실패", "실패", JOptionPane.WARNING_MESSAGE);
					id.setText("");
					pw.setText("");
				} else {
					c.LoginBtn.setVisible(false);
					c.fileBoardBtn.setVisible(true);
					dispose();
				}
			} catch (Exception error) { error.getMessage(); }
		}
	}
}
