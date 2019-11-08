package week02;
import javax.swing.*;
import java.awt.*;

public class p290_8 extends JApplet {
	public void paint(Graphics canvas) {
	
		canvas.fillOval(0, 0, 200, 200);
		canvas.setColor(Color.WHITE);
		canvas.fillOval(25, 25, 150, 150);
		canvas.setColor(Color.BLACK);
		canvas.fillOval(50, 50, 100, 100);
		canvas.setColor(Color.WHITE);
		canvas.fillOval(75, 75, 50, 50);
	}
}
