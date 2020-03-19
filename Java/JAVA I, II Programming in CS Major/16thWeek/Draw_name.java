import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class Draw_name extends JFrame
{
	private Vector<Point> point;
	private Vector<Vector<Point>> lines = new Vector<Vector<Point>>();

	public Draw_name()
	{
		setSize(500, 500);
		setBackground(Color.WHITE);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		addMouseListener(new MouseAdapter()
		{
			public void mousePressed(MouseEvent e)
			{
				point = new Vector<Point>();
			}
			
			public void mouseReleased(MouseEvent e)
			{
				lines.add(point);
				repaint();
			}
		});
		//repaint();

		addMouseMotionListener(new MouseMotionAdapter()
		{
			public void mouseDragged(MouseEvent e)
			{
				int x, y;
				x = e.getX(); y = e.getY();
				point.add(new Point(x,y));
				//repaint();
			}
		});
	}

	public void paint(Graphics g)
	{
		for(int num=0;num<lines.size();num++)
		{
			Vector<Point> line = lines.get(num);
			for(int i=0;i<line.size()-1;i++)
			{
				Point oldP = line.get(i);
				Point p = line.get(i+1);
				g.drawLine(oldP.x, oldP.y, p.x, p.y);
			}
		}
	}
	
	public static void main(String[] args)
	{
		Draw_name m = new Draw_name();
		m.setVisible(true);
	}
}
