import java.io.*;
import java.net.*;

class Server{
	public static void main(String[] args) throws IOException{
		ServerSocket ss=new ServerSocket(8000);
		Socket s=ss.accept();
		System.out.println("Connection Created");
		PrintStream ps=new PrintStream(s.getOutputStream());//to send data to client
		InputStreamReader cin=new InputStreamReader(s.getInputStream());//to get data from client
		BufferedReader br=new BufferedReader(cin);//buffer to read clinet data
		BufferedReader kb=new BufferedReader(new InputStreamReader(System.in));//keyboard
		while(true){
			String str1,str;

			while(!(str=br.readLine()).equals("Bye")){
				System.out.println(str);
				System.out.print("Server:");
				str1=kb.readLine();
				ps.println(str1);
			}
			//close connection
			ps.close();
			br.close();
			kb.close();
			ss.close();
			s.close();
			System.exit(0);
		}
		
			
	}
}
