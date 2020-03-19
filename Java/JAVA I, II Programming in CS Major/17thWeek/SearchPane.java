import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import javax.swing.event.*;
import java.sql.*;
import javax.sql.*;
import java.util.*;

public class SearchPane extends JPanel implements ActionListener{
	
  	private Connection con;
  	private Statement stmt;

  	private JPanel panel[];
  	private JLabel label[];
  	private JTextField tf[];
  	private JButton okb;
  	private JButton rsb;
  	
  	public SearchPane()
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

		tf[2].setEditable(false);
		tf[3].setEditable(false);
		tf[4].setEditable(false);
		tf[5].setEditable(false);
		tf[6].setEditable(false);
		tf[7].setEditable(false);
		tf[8].setEditable(false);

		panel[9] = new JPanel();
		okb = new JButton("성적조회");
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
    	if(ae_type.equals(okb.getText()))
    	{
      		try
      		{
				Class.forName("com.mysql.cj.jdbc.Driver");
				con = DriverManager.getConnection("jdbc:mysql://localhost:3306/score?serverTimezone=UTC&user=root&password=wjdguswo3!");
				stmt = con.createStatement();
				String query = "SELECT * FROM score WHERE name=";
				query = query +"'"+tf[0].getText();
				query = query +"' and snum='"+tf[1].getText()+"'";
       			ResultSet rs = stmt.executeQuery(query);

				if(rs.next())
				{
					tf[0].setText(rs.getString("name"));
					tf[1].setText(rs.getString("snum"));
					tf[2].setText(rs.getString("sub1"));
					tf[3].setText(rs.getString("sub2"));
					tf[4].setText(rs.getString("sub3"));
					tf[5].setText(rs.getString("sub4"));
					tf[6].setText(rs.getString("sub5"));
					tf[7].setText(rs.getString("sub6"));
					tf[8].setText(rs.getString("sub7"));
				}
        		stmt.close();
        		con.close();
      		}
      		catch(Exception e)
      		{
				e.printStackTrace();
			}
		}
    	else if(ae_type.equals(rsb.getText()))
    	{
      		for(int i = 0; i<9 ; i++)
        		tf[i].setText("");
   		}
  	}
}
