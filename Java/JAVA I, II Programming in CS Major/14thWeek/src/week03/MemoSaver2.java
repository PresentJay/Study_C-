package week03;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MemoSaver2 extends JFrame implements ActionListener	// i
{
	private String saveText1 = "No save memo";
	private String saveText2 = "No svae memo";

	private JPanel textPanel;
	private JPanel buttonPanel;
	private JTextArea textBox;

	private JButton saveMemo1 = new JButton("Save Memo1");
	private JButton saveMemo2 = new JButton("Save Memo2");
	private JButton clear = new JButton("Clear");
	private JButton getMemo1 = new JButton("Get Memo1");
	private JButton getMemo2 = new JButton("Get Memo2");
	private JButton exit = new JButton("Exit");

	public MemoSaver2()
	{
		super("textBox1");
		setSize(700, 550);
		setLayout(new BorderLayout());

		textBox = new JTextArea(10, 40);
		textBox.setLineWrap(true);	// vii

		textPanel = new JPanel();
		textPanel.setBackground(Color.lightGray);
		buttonPanel = new JPanel();
		buttonPanel.setBackground(Color.white);
		buttonPanel.setLayout(new GridLayout(2, 3));	// ii

		saveMemo1.addActionListener(this);
		saveMemo2.addActionListener(this);
		clear.addActionListener(this);
		getMemo1.addActionListener(this);
		getMemo2.addActionListener(this);
		exit.addActionListener(this);

		textPanel.add(textBox);
		buttonPanel.add(saveMemo1);
		buttonPanel.add(saveMemo2);
		buttonPanel.add(clear);
		buttonPanel.add(getMemo1);
		buttonPanel.add(getMemo2);
		buttonPanel.add(exit);

		add(textPanel, "Center");
		add(buttonPanel, "South");
	}

	public MemoSaver2(int lineCount, int charCount)		// v.
	{
		super("textBox2");
		setSize(700, 550);
		setLayout(new BorderLayout());

		textBox = new JTextArea(lineCount, charCount);
		textBox.setLineWrap(true);

		textPanel = new JPanel();
		textPanel.setBackground(Color.gray);
		buttonPanel = new JPanel();
		buttonPanel.setBackground(Color.white);
		buttonPanel.setLayout(new GridLayout(2, 3));

		saveMemo1.addActionListener(this);
		saveMemo2.addActionListener(this);
		clear.addActionListener(this);
		getMemo1.addActionListener(this);
		getMemo2.addActionListener(this);
		exit.addActionListener(this);

		textPanel.add(textBox);
		buttonPanel.add(saveMemo1);
		buttonPanel.add(saveMemo2);
		buttonPanel.add(clear);
		buttonPanel.add(getMemo1);
		buttonPanel.add(getMemo2);
		buttonPanel.add(exit);

		add(textPanel, "Center");
		add(buttonPanel, "South");
	}

	public void actionPerformed(ActionEvent e)
	{
		String actionCommand = e.getActionCommand();
		
		// iii
		if(actionCommand.equals("Save Memo1"))
		{
			saveText1 = textBox.getText();
			textBox.setText("Memo 1 saved.");
		}
		else if(actionCommand.equals("Save Memo2"))
		{
			saveText2 = textBox.getText();
			textBox.setText("Memo 2 saved.");
		}
		else if(actionCommand.equals("Clear"))
		{
			textBox.setText("");
		}
		else if(actionCommand.equals("Get Memo1"))
		{
			textBox.setText(saveText1);
		}
		else if(actionCommand.equals("Get Memo2"))
		{
			textBox.setText(saveText2);
		}
		else if(actionCommand.equals("Exit")) // iv
		{
			System.exit(0);
		}
		else
		{
			System.out.println("Error");
		}
	}

	public static void main(String[] args)
	{
		MemoSaver2 ms = new MemoSaver2();
		ms.setVisible(true);

		MemoSaver2 ms2 = new MemoSaver2(5, 60);  // vii
		ms2.setVisible(true);
	}
}