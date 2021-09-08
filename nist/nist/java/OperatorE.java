class IllegalNumberOfArgumentsException extends Exception{
		IllegalNumberOfArgumentsException(String msg){
			super(msg);
		}
}
class InvalidOperatorException extends Exception{
		InvalidOperatorException(String msg){
			super(msg);
		}
}
class NegativeResultException extends Exception{
		NegativeResultException(String msg){
			super(msg);
		}
}
class OperatorE{
	public static void main(String[] args){
		try{
			if(args.length<3)
				throw new IllegalNumberOfArgumentsException("less than 3");
			char c=args[1].charAt(0);
			if(c=='+' || c=='-' || c=='*' || c=='/')
			{}
			else
				throw new InvalidOperatorException("Invalid operator");
			
			int a=Integer.valueOf(args[0]);
			int b=Integer.valueOf(args[2]);
			int r=0;
			if(c=='+')
				r=a+b;
			if(c=='-')
				r=a-b;
			if(c=='*')
				r=a*b;
			if(c=='/')
				r=a/b;
			
			if(r<0)
				throw new NegativeResultException("NegativeResult");

			System.out.println("result is:"+r);
		}catch(IllegalNumberOfArgumentsException e){
			System.out.println(e);
		}catch(InvalidOperatorException e){
			System.out.println(e);
		}catch(NegativeResultException e){
			System.out.println(e);
		}
	}
}