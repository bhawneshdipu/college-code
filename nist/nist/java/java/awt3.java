import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

class awt3 extends Frame{
	awt3(){
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
	}
	public void paint(Graphics g){
		g.setColor(Color.black);
		g.fillRect(0,0,500,400);//rectangle(x,y,height,width);
			
		
		//home
		int x[]={250,225,275};
		int y[]={100,125,125};		
		g.setColor(Color.red);
		g.fillPolygon(x,y,3);
		
		g.setColor(Color.white);
		g.fillRect(227,125,40,50);
		g.setColor(Color.red);
		g.fillRect(240,135,20,20);
		g.drawLine(0,175,500,175);
		g.setColor(Color.white);		
		g.fillOval(90,70,50,50);//oval(x,y,height,width);

		g.setColor(Color.green);

		g.fillArc(50,145,50,60,0,180);//arc(x,y,w,h,sangle,aangle);//starting from sangle to(sangle+aangle);
		g.fillArc(80,145,50,60,0,180);
		
		int a,b;
		g.setColor(Color.white);
		
		g.drawString("Hello World (-_-) ",275,350);

		while(1==1){
			a=(int)Math.random()*300;
			b=(int)Math.random()*400;
			g.fillOval(a,b,2,2);
			try{
				Thread.sleep(20);
			}catch(Exception e){
			}			
			
		}
		

	}
	public static void main(String[] args){
		awt3 a=new awt3();
		a.setSize(500,400);
		a.setTitle("sweet home");
		a.setVisible(true);
	}
}



		
	

