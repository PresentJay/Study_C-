package week01;
import javax.swing.*;
import java.awt.*;

public class snowman extends JApplet {
	public void paint(Graphics canvas)
	{
		canvas.drawOval(100, 50, 200, 200);
		canvas.fillOval(155, 100, 10, 20);
		canvas.fillOval(230, 100, 10, 20);
		canvas.drawArc(150, 160, 100, 50, 180, 180);
		canvas.drawOval(50, 250, 300, 300);
		canvas.drawLine(50, 400, 25, 300);
		canvas.drawLine(350,400, 375, 300);
	}
}
