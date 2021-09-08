import java.util.*;
class Student{
	int roll;
	String name;
	int age;
	Student (int r,String n,int a){
		roll=r;
		name=n;
		age=a;
	}
}
class AgeNotWithinRangeException extends Exception{
	AgeNotWithinRangeException(String mgs){
		super(mgs);
	}
}
class NameNotValidException extends Exception{
		NameNotValidException(String msg){
			super(msg);
		}
}
class StudentE{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		try{	
			System.out.println("enter name  roll  age ");
			String n=in.next();
			
			int r=in.nextInt();
			int a=in.nextInt();
				
			if(a<15|| a>=21)
				throw new AgeNotWithinRangeException("AgeNotWithinRangeException");
			
			for(int i=0;i<n.length();i++){
				if((n.charAt(i)>='a' && n.charAt(i)<='z' )|| (n.charAt(i)>='A' && n.charAt(i)<='Z'))
					{}
				else
					throw new NameNotValidException("NameNotValidException");
			}
			Student s=new Student(r,n,a);
			System.out.println("student data inserted");
		}catch(AgeNotWithinRangeException e){
			System.out.println(e.getMessage());
		}catch(NameNotValidException e){
			System.out.println(e);
		}finally{
			System.out.println("Exception ends");
		}
	}
}