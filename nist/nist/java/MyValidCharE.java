class VowelException extends Exception{
	VowelException(String msg){
		super(msg);
	}
}
class BlankException extends Exception{
		BlankException(String msg){
			super(msg);
		}
}
class ExitException extends Exception{
		ExitException(String msg){
			super(msg);
		}
}
class MyValidCharE{
	public static void main(String[] args){
		
		try{
			if(args.length==0)
				throw new BlankException("BlankException");
			char a=args[0].charAt(0);
			if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
				throw new VowelException("VowelException");
			if(a=='X')
				throw new ExitException("ExitException");
		
			System.out.println("Valid character");
		
		}catch(BlankException e){
			System.out.println(e);
		}catch(VowelException e){
			System.out.println(e);
		}catch(ExitException e){
			System.out.println(e);
			System.exit(0);
		}
	}
}
		
		
			
			