import java.util.*;
class FinallyE{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		try{
			System.out.println("enter a num arr");
	
			int n=in.nextInt();
			int arr[]={1,2,3};
			arr[n]=1000;
					System.out.println("string");
	
			String str=in.next();
			int x=Integer.valueOf(str);
				System.out.println("num divide by ");
	
			int k=in.nextInt();
			n=10/k;
			
		}catch(ArrayIndexOutOfBoundsException e){
			System.out.println(e);
		}catch(NumberFormatException e){
			System.out.println(e);
		}catch(ArithmeticException e){
			System.out.println(e);
		}finally{
			System.out.println("Finally block executes");
		}
	}
}