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

	private JButton saveMemo1 = new JButton("메모 1 저장");
	private JButton saveMemo2 = new JButton("메모 2 저장");
	private JButton readMemo1 = new JButton("메모 1 읽기");
	private JButton readMemo2 = new JButton("메모 2 읽기");
	private JButton clear = new JButton("삭제");
	private JButton exit = new JButton("종료");

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
		if(actionCommand.equals("메모 1 저장")) { saveText1 = textBox.getText(); textBox.setText("메모 1 저장"); }
		else if(actionCommand.equals("메모 2 저장")) { saveText2 = textBox.getText(); textBox.setText("메모 2 저장"); }
		else if(actionCommand.equals("메모 1 읽기")) { textBox.setText(saveText1); }
		else if(actionCommand.equals("메모 2 읽기")) { textBox.setText(saveText2); }
		else if(actionCommand.equals("삭제")) { textBox.setText(""); }
		else if(actionCommand.equals("종료"))	{ System.exit(0); }
		else { System.out.println("Error"); }
	}

	public static void main (String[] args)
	{
		MemoApplet ma = new MemoApplet();
		ma.init();
	}
}