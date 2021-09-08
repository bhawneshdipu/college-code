import java.util.*;
import java.io.*;

public class CandidateCode{
	public static String[] amount_value(int input1,String[] input2){
		int n=input1;
		int[][] arr=new int[input1][input1];
		
		
		for(int i=0;i<n;i++){
			StringTokenizer st=new StringTokenizer(input2[i],"#");
			for(int j=0;j<n;j++){
				if(st.hasMoreTokens()){
					String s=st.nextToken();
//					System.out.println(s+"jjj");
				

						if(s.charAt(0)=='{') {
							String ss=s.substring(1);
//							System.out.println(ss);
							arr[i][j]=Integer.valueOf(ss);
						
						}else if(s.charAt(s.length()-1)=='}'){
							String ss=s.substring(0,s.length()-1);
//							System.out.println(ss);
							arr[i][j]=Integer.valueOf(ss);
						}else{
//							System.out.println(s);
							arr[i][j]=Integer.valueOf(s);
						}
				}
			}

		}
/*		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				System.out.print(arr[i][j]+"  ");
			}
			System.out.println();
		}
*/		
		int[][] arrA=new int[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				arrA[i][j]=9999999;		
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i-1>=0 && j-1>=0  && i-1<n && j-1<n )//1
				arrA[i][j]=Math.min(arrA[i][j],arr[i-1][j-1]);
				if(i-1>=0 && j>=0 && i-1<n && j<n)//2
				arrA[i][j]=Math.min(arrA[i][j],arr[i-1][j]);
				if(i-1>=0 && j+1>=0 && i-1<n && j+1<n)//3
				arrA[i][j]=Math.min(arrA[i][j],arr[i-1][j+1]);
				if(i>=0 && j-1>=0 && i<n && j-1<n)//4
				arrA[i][j]=Math.min(arrA[i][j],arr[i][j-1]);
				if(i>=0 && j>=0 && i<n && j<n)//5
				arrA[i][j]=Math.min(arrA[i][j],arr[i][j]);
				if(i>=0 && j+1>=0 && i<n && j+1<n)//6
				arrA[i][j]=Math.min(arrA[i][j],arr[i][j+1]);
				if(i+1>=0 && j-1>=0 && i+1<n && j-1<n)//7
				arrA[i][j]=Math.min(arrA[i][j],arr[i+1][j-1]);
				if(i+1>=0 && j>=0 && i+1<n && j<n)//8
				arrA[i][j]=Math.min(arrA[i][j],arr[i+1][j]);
				if(i+1>=0 && j+1>=0 && i+1<n && j+1<n)//9
				arrA[i][j]=Math.min(arrA[i][j],arr[i+1][j+1]);		
				
			}
		}
/*		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				System.out.print(arrA[i][j]+"---");
			}
			System.out.println();
		}
*/	
		int maxx=-999999;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(maxx<arrA[i][j])
					maxx=arrA[i][j];
			}
		}	
//		System.out.println(maxx+"-->max");
			int[] x=new int[n];
			int[] y=new int[n];
int k=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(arrA[i][j]==maxx){
						x[k]=i;
						y[k]=j;
						k++;
						
					}
				}
			}

			

			String[] ans=new String[1];
			ans[0]="{";
			for(int i=0;i<k;i++){
				String ch=Integer.toString(x[i]+1);
				//	System.out.println(ch);
				ans[0]+=ch;
				ans[0]+="#";
				ans[0]+=Integer.toString(y[i]+1);
				if(i<k-1)
					ans[0]+=",";
			}
			ans[0]+="}";	

//		System.out.println(ans[0]);
			

		return ans;			
	}
	public static void main(String[] args){
		int n=4;
		String [] ans=amount_value(n,args);
		for(String s : ans )
			System.out.println(s);
	}	
} 
