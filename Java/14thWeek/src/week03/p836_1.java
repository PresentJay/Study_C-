package week03;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class p836_1 extends JFrame implements ActionListener {
	private Container contentPane;
	private JPanel labelPanel;
	private JPanel buttonPanel;
	private JButton p836_1;
	private JLabel label;
	private int com = 0;
	private final int width = 400;
	private final int height = 300;

	public p836_1()
	{
		super("p836_1");
		setSize(width, height);
		contentPane = getContentPane();
		contentPane.setLayout(new BorderLayout());

		labelPanel = new JPanel();
		labelPanel.setBackground(Color.gray);
		buttonPanel = new JPanel();
		buttonPanel.setBackground(Color.blue);

		p836_1 = new JButton("Change");
		p836_1.addActionListener(this);
		label = new JLabel("Watch this panel!");
		labelPanel.add(label);
		buttonPanel.add(p836_1);

		contentPane.add(labelPanel, BorderLayout.CENTER);
		contentPane.add(buttonPanel, "South");
	}

	public void actionPerformed(ActionEvent e)
	{
		String actionCommand = e.getActionCommand();
		if(actionCommand.equals("Change"))
		{
			if(com % 2 == 0)
			{
				labelPanel.setBackground(Color.red);
				buttonPanel.setBackground(Color.pink);
			}
			else if(com % 2 == 1)
			{
				labelPanel.setBackground(Color.green);
				buttonPanel.setBackground(Color.blue);
			}
		}
		else
			System.out.println("Error");

		com++;
		repaint();
	}

	public static void main (String[] args)
	{
		p836_1 cb = new p836_1();
		cb.setVisible(true);
	}
}
