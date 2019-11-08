package week02;

import javax.swing.*;
import java.awt.*;



public class p460_7 extends JApplet {
	
	private int[] firstfloorx = {100, 0, 200};
	private int[] firstfloory = {0, 100, 100};
	private int[] secondfloory = {80, 180, 180};
	private int[] thirdfloory = {160, 260, 260};
	
	public void paint(Graphics canvas) {
		
		canvas.setColor(Color.GREEN);
		canvas.fillPolygon(firstfloorx,firstfloory, firstfloorx.length);
		canvas.fillPolygon(firstfloorx,secondfloory, firstfloorx.length);
		canvas.fillPolygon(firstfloorx,thirdfloory, firstfloorx.length);
		canvas.setColor(Color.GRAY);
		canvas.fillRect(80, 260, 40, 150);
	}
}
