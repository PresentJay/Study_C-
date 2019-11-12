package p870_6;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MemoApplet extends JApplet implements ActionListener
{
	private Container contentPane;
	private final int width = 700;
	private final int height = 550;

	private String saveText1 = "No save memo";
	private String saveText2 = "No save memo";

	private JPanel textPanel;
	private JPanel buttonPanel;
	private JTextArea textBox;

	private JButton saveMemo1 = new JButton("�޸� 1 ����");
	private JButton saveMemo2 = new JButton("�޸� 2 ����");
	private JButton readMemo1 = new JButton("�޸� 1 �б�");
	private JButton readMemo2 = new JButton("�޸� 2 �б�");
	private JButton clear = new JButton("����");
	private JButton exit = new JButton("����");

	public void init()
	{
		setSize(width, height);
		contentPane = getContentPane();
		contentPane.setLayout(new BorderLayout());

		textBox = new JTextArea(10, 40);
		textBox.setLineWrap(true);

		textPanel = new JPanel();
		textPanel.setBackground(Color.blue);

		buttonPanel = new JPanel();
		buttonPanel.setBackground(Color.white);
		buttonPanel.setLayout(new GridLayout(2, 3));

		textPanel.add(textBox);
		saveMemo1.addActionListener(this);
		saveMemo2.addActionListener(this);
		readMemo1.addActionListener(this);
		readMemo2.addActionListener(this);
		clear.addActionListener(this);
		exit.addActionListener(this);

		buttonPanel.add(saveMemo1);
		buttonPanel.add(saveMemo2);
		buttonPanel.add(clear);
		buttonPanel.add(readMemo1);
		buttonPanel.add(readMemo2);
		buttonPanel.add(exit);

		contentPane.add(textPanel, "Center");
		contentPane.add(buttonPanel, "South");
	}

	public void actionPerformed (ActionEvent e)
	{
		String actionCommand = e.getActionCommand();
		if(actionCommand.equals("�޸� 1 ����")) { saveText1 = textBox.getText(); textBox.setText("�޸� 1 ����"); }
		else if(actionCommand.equals("�޸� 2 ����")) { saveText2 = textBox.getText(); textBox.setText("�޸� 2 ����"); }
		else if(actionCommand.equals("�޸� 1 �б�")) { textBox.setText(saveText1); }
		else if(actionCommand.equals("�޸� 2 �б�")) { textBox.setText(saveText2); }
		else if(actionCommand.equals("����")) { textBox.setText(""); }
		else if(actionCommand.equals("����"))	{ System.exit(0); }
		else { System.out.println("Error"); }
	}

	public static void main (String[] args)
	{
		MemoApplet ma = new MemoApplet();
		ma.init();
	}
}