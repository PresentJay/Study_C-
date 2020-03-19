import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import javax.swing.event.*;
import java.sql.*;
import java.util.*;

public class Semester extends JPanel implements ActionListener{
	private String url = "jdbc:odbc:score";
  	private Connection con;
  	private Statement stmt;

  	private JPanel panel[];
  	private JLabel label[];
  	private JTextField tf[];
  	private JButton okb;
  	private JButton rsb;

  	public Semester()
  	{
    	setLayout(new GridLayout(10,1));
    	EtchedBorder eb = new EtchedBorder();
    	setBorder(eb);

    	panel = new JPanel[10];
    	label = new JLabel[9];
    	tf = new JTextField[9];

    	label[0] = new JLabel("이   름 : ");
    	label[1] = new JLabel("학   번 : ");
    	label[2] = new JLabel("앱을 위한 자바B : ");
    	label[3] = new JLabel("안드로이드 앱개발B : ");
    	label[4] = new JLabel("전문가초청세미나 : ");
    	label[5] = new JLabel("C++ : ");
    	label[6] = new JLabel("JAVA I : ");
    	label[7] = new JLabel("이산구조 : ");
		label[8] = new JLabel("인간과컴퓨터  : ");
		

		for(int i = 0; i<9 ; i++) {

			tf[i] = new JTextField(15);
		  	panel[i] = new JPanel();
		  	panel[i].add(label[i]);
		  	panel[i].add(tf[i]);

      		add(panel[i]);
    	}

		panel[9] = new JPanel();
		okb = new JButton("저장하기");
		okb.addActionListener(this);
		rsb = new JButton("다시쓰기");
		rsb.addActionListener(this);
		panel[9].add(okb);
		panel[9].add(rsb);
		add(panel[9]);
  	}

 	public void actionPerformed(ActionEvent ae)
 	{
    	String ae_type = ae.getActionCommand();

    	if(ae_type.equals(okb.getText())) {
			try
			{
				Class.forName("com.mysql.cj.jdbc.Driver");
				con = DriverManager.getConnection("jdbc:mysql://localhost:3306/score?serverTimezone=UTC&user=root&password=wjdguswo3!");
				stmt = con.createStatement();

				String query = "INSERT INTO score(name, snum, sub1, sub2, sub3, sub4, sub5, sub6, sub7) VALUES (";

				query = query + "'"+ tf[0].getText() + "', ";
				query = query + "'"+ tf[1].getText() + "', ";
				query = query + "'"+ tf[2].getText() + "', ";
				query = query + "'"+ tf[3].getText() + "', ";
				query = query + "'"+ tf[4].getText() + "', ";
				query = query + "'"+ tf[5].getText() + "', ";
				query = query + "'"+ tf[6].getText() + "', ";
				query = query + "'"+ tf[7].getText() + "', ";
				query = query + "'"+ tf[8].getText() + "')";

				stmt.execute(query);
				stmt.close();
				con.close();
			}
			catch(Exception e)
			{}
		}
    	else if(ae_type.equals(rsb.getText()))
    	{
      		for(int i = 0; i<9 ; i++)
        	tf[i].setText("");
    	}
 	}
}
