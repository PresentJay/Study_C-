package week01;
import javax.swing.*;
import java.awt.*;

public class runningman extends JApplet{
	public static final int face_dia = 50;
	public static final int faceX = 10;
	public static final int faceY = 5;

	public static final int eye_Width = 5;
	public static final int eye_height = 10;
	public static final int righteyeX = 20;
	public static final int righteyeY = 15;
	public static final int lefteyeX = 45;
	public static final int lefteyeY = righteyeY;

	public static final int nose_dia = 5;
	public static final int noseX = 32;
	public static final int noseY = 25;

	public static final int mouth_width = 30;
	public static final int mouth_height = 10;
	public static final int mouthX = 20;
	public static final int mouthY = 40;
	public static final int mouth_sAngle = 180;
	public static final int mouth_deg = 180;

	public void paint(Graphics canvas){
		for(int i = 0; i < 10; i++){
			switch(i % 5){
				case 0:
				canvas.setColor(Color.WHITE);
				canvas.fillOval(faceX + 70 * i, faceY + 30*i, face_dia, face_dia);
				break;
				case 1:
				canvas.setColor(Color.PINK);
				canvas.fillOval(faceX + 70 * i, faceY + 30*i, face_dia, face_dia);
				break;
				case 2:
				canvas.setColor(Color.RED);
				canvas.fillOval(faceX + 70 * i, faceY + 30*i, face_dia, face_dia);
				break;
				case 3:
				canvas.setColor(Color.YELLOW);
				canvas.fillOval(faceX + 70 * i, faceY + 30*i, face_dia, face_dia);
				break;
				case 4:
				canvas.setColor(Color.GREEN);
				canvas.fillOval(faceX + 70 * i, faceY + 30*i, face_dia, face_dia);
				break;
			}
			canvas.setColor(Color.BLACK);
			canvas.drawOval(faceX + 70 * i, faceY + 30*i, face_dia, face_dia);

			canvas.fillOval(righteyeX +70 * i, righteyeY + 30 * i,eye_Width, eye_height);
			canvas.fillOval(lefteyeX +70 * i, lefteyeY + 30 * i,eye_Width, eye_height);
			canvas.fillOval(noseX + 70*i, noseY + 30 * i,nose_dia, nose_dia);
			if(mouth_height - 2*i>=0){
				canvas.drawArc(mouthX +70*i, mouthY + 30 * i,mouth_width, mouth_height - i*2, 180, 180);
			}
			else{
				canvas.drawArc(mouthX +70*i, mouthY + 30 * i,mouth_width, 0 + i*2, 0, 180);
			}

			canvas.drawOval(23+70*i,55+30*i,25,70);
			canvas.drawOval(48+70*i,65+30*i,20,10);
			canvas.drawOval(68+70*i,45+30*i,10,30);
			canvas.drawOval(5+70*i,65+30*i,20,10);
			canvas.drawOval(0+70*i,70+30*i,10,30);
			canvas.drawOval(40+70*i,120+30*i,20,10);
			canvas.drawOval(60+70*i,120+30*i,10,40);
			canvas.drawOval(25+70*i,120+30*i,10,30);
			canvas.drawOval(0+70*i,145+30*i,30,10);
		}
	}
}
