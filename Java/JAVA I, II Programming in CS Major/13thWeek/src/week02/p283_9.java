package week02;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class p283_9 extends JApplet implements ActionListener {

	

	public void init() {
		Container contentPane = getContentPane();
		contentPane.setBackground(Color.WHITE);
		
		contentPane.setLayout(new FlowLayout());
		
		JButton redButton = new JButton("Red");
		contentPane.add(redButton);
		redButton.addActionListener(this);
		
		JButton whiteButton = new JButton("White");
		contentPane.add(whiteButton);
		whiteButton.addActionListener(this);
		
		JButton blueButton = new JButton("Blue");
		contentPane.add(blueButton);
		blueButton.addActionListener(this);	
	}
	
	public void actionPerformed(ActionEvent e) {
		Container contentPane = getContentPane();
		
		if (e.getActionCommand().equals("Red")) contentPane.setBackground(Color.RED);
		else if (e.getActionCommand().equals("White")) contentPane.setBackground(Color.WHITE);
		else if (e.getActionCommand().equals("Blue")) contentPane.setBackground(Color.BLUE);
	}
}
