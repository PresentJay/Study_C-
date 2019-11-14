import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;

public class Score extends JFrame{

	private JTabbedPane tp;
	private Semester sm;
	private SearchPane sp;
	
	public Score()
	{
		setTitle("성적 관리");
		tp = new JTabbedPane();
		sm = new Semester();
		sp = new SearchPane();

   	 	tp.addTab("성적입력", sm);
    	tp.addTab("성적조회", sp);

    	getContentPane().add(tp);
  	  	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  	}
	
	public static void main(String[] args) {
		Score score = new Score();

		Dimension d = new Dimension(350, 400);
		score.setSize(d);
		score.setVisible(true);
		score.show(true);
	}

}
