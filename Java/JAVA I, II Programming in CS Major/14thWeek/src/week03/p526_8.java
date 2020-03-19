package week03;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class p526_8 extends JFrame implements ActionListener{
	private JButton sunnyButton = new JButton("Sunny");
	private JButton cloudyButton = new JButton("Cloudy");
	private static int count;
	private static int state;

	public p526_8()
	{
		count = 0; state = 0;
		setSize(400, 300);
		p526_8_win listener = new p526_8_win();
		addWindowListener(listener);

		Container contentPane = getContentPane();
		contentPane.setBackground(Color.white);

		contentPane.setLayout(new FlowLayout());

		contentPane.add(sunnyButton);
		sunnyButton.addActionListener(this);

		contentPane.add(cloudyButton);
		cloudyButton.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e)
	{
		String actionCommand = e.getActionCommand();
		Container contentPane = getContentPane();
		if(actionCommand.equals("Sunny"))
		{
			contentPane.setBackground(Color.blue);
			sunnyButton.setVisible(false);
			cloudyButton.setVisible(true);
			count++;
			state = 1;
		}
		else if(actionCommand.equals("Cloudy"))
		{
			contentPane.setBackground(Color.gray);
			sunnyButton.setVisible(true);
			cloudyButton.setVisible(false);
			count++;
			state = 2;
		}
		else
			System.out.println("Error in button interface.");

		if (count == 10)
		{
			JLabel message = new JLabel("Only one more click");
			contentPane.setLayout(null);
			message.setBounds(130, 40, 200, 30);
			contentPane.add(message);
		}
		else if(count > 10)
			System.exit(0);

		repaint();
	}

	public void paint (Graphics g)
	{
		super.paint(g);
		if(state == 1)
			draw(g, Color.yellow, 180);
		else if (state == 2)
			draw(g, Color.black, 0);
	}

	public void draw(Graphics g, Color c, int state)
	{
		g.setColor(c);
		g.drawOval(160, 100, 80, 80);
		g.fillOval(180,125,8,20);
		g.fillOval(215,125,8,20);
		g.drawArc(184,150,34,20,state,180);
	}
}
