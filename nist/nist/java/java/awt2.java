import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

class awt2 extends Frame{
	awt2(){
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
	}
	public void paint(Graphics g){
		g.setColor(Color.blue);
		g.fillRect(40,40,200,200);//rectangle(x,y,height,width);
		g.setColor(Color.yellow);
		g.fillOval(90,70,80,80);//oval(x,y,height,width);
		g.setColor(Color.black);
		g.fillOval(110,95,5,5);
		g.fillOval(145,95,5,5);
		g.drawLine(130,95,130,115);//line(x,y,x2,y2);
		g.setColor(Color.red);
		g.fillArc(113,115,35,20,180,180);//arc(x,y,w,h,sangle,aangle);//starting from sangle to(sangle+aangle);
	}
	public static void main(String[] args){
		awt2 a=new awt2();
		a.setSize(400,400);
		a.setTitle("hello awt1");
		a.setVisible(true);
	}
}



		
	

