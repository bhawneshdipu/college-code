#include<stdio.h>
void asr(int* a,int* q,int bits){
	int fq,la;
	
	if(*a & (bits<<1))
		la=1;
	if(*q& (bits<<1))
		fq=1;
	
	*a=*a>>1;
	*q=*q>>1;
	if(la)
		*a=*a | (bits<<1);
	if(fq)
		*q=*q|(bits<<1);

} 
void show(int n,int bits){
	int k=bits-1;
	while(k>=0){
	if(n & (-n)){
		printf("1");
	
	}else{
		printf("0");

	}	
	n=n>>1;	
	k--;
	}
	printf("\n");
		
}

int main(){
	int num;
	int a=0,m,_m,q,_q=0;
	printf("enter m ans q\n");
	scanf("%d %d",&num,&q);
	m=num;
	int bits=1;
	int tq=q;
	while(num || tq){
		bits++;
		num=num>>1;
		tq=tq>>1;
	}
	show(a,32);
	show(m,32);
	
	show(q,32);
		

	for(int i=0;i<bits;i++){	
		if(~(q&(-q)) && _q==1)
			a=a+m;
		else if((q&(-q)) && _q==0)
			a=a-m;
		
		asr(&a,&q,bits);
		if(_q & (-q))
			_q=1;

		int tmp=bits;
		int l,f;
		if(a&(1<<bits)){
			l=1;
		}
		if(a & 1)
			f=1;
		if(q & 1)
			_q=1;
				
			a=a>>1;
			if(l==1)
			a=(a | 1<<bits);
			q=q>>1;				
			if(f==1)
			q=(q | 1<<bits);

		}
		
		show(a,bits);
		show(q,bits);
	
	
}
