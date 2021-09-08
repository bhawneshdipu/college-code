import javax.swing.*;
import java.awt.*;

class MyPanel extends JPanel{
	MyPanel(){
		this.setBackground(Color.red);
	}
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		g.setColor(Color.white);
		g.setFont(new Font("Consolas",Font.BOLD,30));
		g.drawString("Hello Swing",50,100);
		g.setFont(new Font("Arial",Font.BOLD,20));
		g.drawString("Welcome",100,200);
		g.setFont(new Font("Ubuntu",Font.BOLD,20));
		g.drawString("Welcome again",200,200);
	}
}
public class Swing1 extends JFrame{
	Swing1(){
		Container c=this.getContentPane();
		MyPanel mp= new MyPanel();
		c.add(mp);
	}
	
	public static void main(String[] args){
		Swing1 sw=new Swing1();
		sw.setTitle("My Swing 1");
		sw.setSize(400,400);
		sw.setVisible(true);
		sw.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}	
