import java.io.*;
import java.net.*;
class Client{
	public static void main(String[] args)throws Exception{
		Socket s=new Socket("localhost",8000);//create a client Socket
		DataOutputStream ds=new DataOutputStream(s.getOutputStream());//send data to server
		BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));//recive data from server
		BufferedReader kb=new BufferedReader(new InputStreamReader(System.in));//keyboard
		String str,str1;
		while(!(str=kb.readLine()).equals("Bye")){
			ds.writeBytes("Client:"+str+'\n');
			str1=br.readLine();
			System.out.println("Server:"+str1);
			System.out.print("Client:");
			
		}
		//close connection
		ds.close();
		br.close();
		kb.close();
		
	}

}