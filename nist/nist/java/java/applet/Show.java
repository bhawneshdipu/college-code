import java.applet.*;
import java.awt.*;
import javax.swing.*;

public class Show extends Applet{
	public void init(){
		setBackground(Color.white);
	}
	public void paint(Graphics g){
		g.setColor(Color.red);
		g.drawString("Hello welcome to applet",50,50);
	}
	public void stop(){
	
	}
	public void destroy(){
	
	}

	
	
} 
