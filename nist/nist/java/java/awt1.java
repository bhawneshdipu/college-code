import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

class awt1 extends Frame{
	awt1(){
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
	}
	public void paint(Graphics g){
		g.setColor(Color.blue);
		g.drawRect(40,40,200,200);//rectangle(x,y,height,width);
		g.drawOval(90,70,80,80);//oval(x,y,height,width);
		g.drawOval(110,95,5,5);
		g.drawOval(145,95,5,5);
		g.drawLine(130,95,130,115);//line(x,y,x2,y2);
		g.drawArc(113,115,35,20,0,-180);//arc(x,y,w,h,sangle,aangle);
	}
	public static void main(String[] args){
		awt1 a=new awt1();
		a.setSize(400,400);
		a.setTitle("hello awt1");
		a.setVisible(true);
	}
}



		
	

