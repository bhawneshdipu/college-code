import java.applet.Applet;
import java.awt.*;
import javax.swing.*;

public class MovingBall extends Applet{
	public void init(){
		setBackground(Color.white);
	}
	public void paint(Graphics g){
		Image img=getImage(getDocumentBase(),"Ball.jpg");
		for(int x=0;x<=400;x++){
			setBackground(Color.white);
			g.drawImage(img,x,50,null);
			
			try{
				Thread.sleep(20);
			}catch(Exception e){
			
			}
		}
	}
	public void stop(){

	}
	public void destroy(){

	}

}