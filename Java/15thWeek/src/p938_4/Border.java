package p938_4;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.*;

public class Border extends JFrame implements ActionListener {
	public static void main(String[] args) {
		Border gui = new Border();
		gui.setVisible(true);

	}

	JLabel l1 = new JLabel("라벨");

	Border() {
		this.setSize(400, 200);
		this.setTitle("보드");
		this.setLayout(new BorderLayout());
		Container contentpane = getContentPane();

		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				dispose();
				System.exit(0);
			}
		});

		JMenu m1 = new JMenu("Border");
		JMenuBar mb = new JMenuBar();

		JMenu m2 = new JMenu("Beveled");
		m1.add(m2);

		JMenuItem m = new JMenuItem("Raised");
		m.setActionCommand("B-R");
		m.addActionListener(this);
		m2.add(m);

		m = new JMenuItem("Lowered");
		m.setActionCommand("B-L");
		m.addActionListener(this);
		m2.add(m);

		m2 = new JMenu("Etched");
		m1.add(m2);

		m = new JMenuItem("Raised");
		m.setActionCommand("E-R");
		m.addActionListener(this);
		m2.add(m);

		m = new JMenuItem("Lowered");
		m.setActionCommand("E-L");
		m.addActionListener(this);
		m2.add(m);

		m2 = new JMenu("Line");
		m1.add(m2);

		JMenu m3 = new JMenu("Black");
		m2.add(m3);

		m = new JMenuItem("Small");
		m.setActionCommand("L-B-S");
		m.addActionListener(this);
		m3.add(m);

		m = new JMenuItem("Medium");
		m.setActionCommand("L-B-M");
		m.addActionListener(this);
		m3.add(m);

		m = new JMenuItem("Large");
		m.setActionCommand("L-B-L");
		m.addActionListener(this);
		m3.add(m);

		m3 = new JMenu("Blue");
		m2.add(m3);

		m = new JMenuItem("Small");
		m.setActionCommand("L-BB-S");
		m.addActionListener(this);
		m3.add(m);

		m = new JMenuItem("Medium");
		m.setActionCommand("L-BB-M");
		m.addActionListener(this);
		m3.add(m);

		m = new JMenuItem("Large");
		m.setActionCommand("L-BB-L");
		m.addActionListener(this);
		m3.add(m);

		m3 = new JMenu("Red");
		m2.add(m3);

		m = new JMenuItem("Small");
		m.setActionCommand("L-R-S");
		m.addActionListener(this);
		m3.add(m);

		m = new JMenuItem("Medium");
		m.setActionCommand("L-R-M");
		m.addActionListener(this);
		m3.add(m);

		m = new JMenuItem("Large");
		m.setActionCommand("L-R-L");
		m.addActionListener(this);
		m3.add(m);

		mb.add(m1);
		contentpane.add("North", mb);
		contentpane.add(l1);

	}

	public void actionPerformed(ActionEvent e) {

		if (e.getActionCommand().equals("B-R")) {
			l1.setText("Raised Beveled Border");
			l1.setBorder(new BevelBorder(BevelBorder.RAISED));
		} else if (e.getActionCommand().equals("B-L")) {
			l1.setText("Lowered Beveled Border");
			l1.setBorder(new BevelBorder(BevelBorder.LOWERED));
		} else if (e.getActionCommand().equals("E-R")) {
			l1.setText("Raised Etched Border");
			l1.setBorder(new EtchedBorder(EtchedBorder.RAISED, Color.yellow,
					Color.green));
		} else if (e.getActionCommand().equals("E-L")) {
			l1.setText("Lowered Etched Border");
			l1.setBorder(new EtchedBorder(EtchedBorder.LOWERED, Color.yellow,
					Color.green));
		} else if (e.getActionCommand().equals("L-B-S")) {
			l1.setText("Small Black Line Border");
			l1.setBorder(new LineBorder(Color.BLACK, 5));
		} else if (e.getActionCommand().equals("L-B-M")) {
			l1.setText("Medium Black Line Border");
			l1.setBorder(new LineBorder(Color.BLACK, 10));
		} else if (e.getActionCommand().equals("L-B-L")) {
			l1.setText("Large Black Line Border");
			l1.setBorder(new LineBorder(Color.BLACK, 20));
		} else if (e.getActionCommand().equals("L-R-S")) {
			l1.setText("Small Red Line Border");
			l1.setBorder(new LineBorder(Color.RED, 5));
		} else if (e.getActionCommand().equals("L-R-M")) {
			l1.setText("Medium Red Line Border");
			l1.setBorder(new LineBorder(Color.RED, 10));
		} else if (e.getActionCommand().equals("L-R-L")) {
			l1.setText("Large Red Line Border");
			l1.setBorder(new LineBorder(Color.RED, 20));
		} else if (e.getActionCommand().equals("L-BB-S")) {
			l1.setText("Small Blue Line Border");
			l1.setBorder(new LineBorder(Color.BLUE, 5));
		} else if (e.getActionCommand().equals("L-BB-M")) {
			l1.setText("Medium Blue Line Border");
			l1.setBorder(new LineBorder(Color.BLUE, 10));
		} else if (e.getActionCommand().equals("L-BB-L")) {
			l1.setText("Large Blue Line Border");
			l1.setBorder(new LineBorder(Color.BLUE, 20));
		}

	}
}