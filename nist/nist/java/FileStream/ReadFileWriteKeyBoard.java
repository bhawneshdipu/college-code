import java.io.*;
class ReadFileWriteKeyBoard{
	public static void main(String[] args)throws IOException{
		FileInputStream fin=new FileInputStream("myfile1.txt");
		char ch;
		while((ch=(char)fin.read())!=(char)-1)
			System.out.print(ch);
	
		fin.close();
	}
}
