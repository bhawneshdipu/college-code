#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<math.h>
#define bit 4

int  add(int *a,int *b){
	int c=0,i,x;
	
	for(i=bit-1;i>=0;i--){
		x=a[i];
		a[i]=c^x^b[i];
		if((x==1 && c==1) || (x==1 && b[i]==1) ||(c==1 && b[i]==1))
			c=1;
		else
			c=0;
	}
return c;
}
void _2scomp(int *a){

	int c[bit],i;
	memset(c,0,sizeof(bit));
	c[bit-1]=1;
	for(i=0;i<bit;i++){
		a[i]=1-a[i];
	}
	add(a,c);
	
}

void binary(int *arr,int n){

	int i=bit-1;
	
	while(n){
		arr[i]=n%2;
		n/=2;
		i--;
	}

}
int  arshift(int *a,int *q){
	
		int alast=a[bit-1],qlast=q[bit-1],i;
		for(i=bit-1;i>0;i--){
			a[i]=a[i-1];
		}
		
		for(i=bit-1;i>0;i--){
			q[i]=q[i-1];
		}
		q[0]=alast;
		
		return qlast;
}

void  rshift(int *a,int *q){
	
		int alast=a[bit-1],qlast=q[bit-1],i;
		for(i=bit-1;i>0;i--){
			a[i]=a[i-1];
		}
		a[0]=0;
		for(i=bit-1;i>0;i--){
			q[i]=q[i-1];
		}
		q[0]=alast;
}

int decimal(int *a,int *b){
	int ans=0,i,s=0;
	if(a[0]==1){
	for(i=0;i<bit;i++){
		if(a[i]==1)
			a[i]=0;
		else
			a[i]=1;
	}
	for(i=0;i<bit-1;i++){
		if(b[i]==1)
			b[i]=0;
		else
			b[i]=1;
	}
	b[bit-1]=1;
	s=1;
	printf("-ve number\n");

	}

	for(i=bit-1;i>=0;i--){
		if(a[i]==1){
			ans+=(int)(pow(2,2*bit-i-1));
			//printf("added-from a->%d   i=%d  bit=%d\n",(int)(pow(2,2*bit-i-1)),i,2*bit-i-1);
		}			
			
		if(b[i]==1)
			ans+=(int)(pow(2,(bit-1-i)));
			//printf("added-from b->%d   i=%d  bit=%d\n",(int)(pow(2,bit-i-1)),i,bit-i-1);
		
	}
if(s==1)
return -1*ans;

return ans;
}
int main(){

	int M,Q,i,j,_c=0;
	int *arra,*arrm,*arr2m,*arrq;
	printf("enter m and q\n");
	scanf("%d %d",&M,&Q);
	arra=(int *)malloc(sizeof(int)*bit);
	memset(arra,0,sizeof(int)*bit);

	arrm=(int *)malloc(sizeof(int)*bit);
	memset(arra,0,sizeof(int)*bit);

	arr2m=(int *)malloc(sizeof(int)*bit);
	memset(arra,0,sizeof(int)*bit);

	arrq=(int *)malloc(sizeof(int)*bit);
	memset(arra,0,sizeof(int)*bit);
	if(M<0){
		binary(arrm,-1*M);
		_2scomp(arrm);
		binary(arr2m,-1*M);
		//_2scomp(arr2m);
	
	}else{
		
		binary(arrm,M);
		binary(arr2m,M);
		_2scomp(arr2m);
	}
	if(Q<0){
		binary(arrq,-1*Q);
		_2scomp(arrq);
	}else{
	binary(arrq,Q);
	}

/*----------------------------------------------------------------------------------------*/

	for(i=0;i<bit;i++){
		printf("%d ",arrm[i]);
	}
	printf("----->binary^^m\n");

	for(i=0;i<bit;i++){
		printf("%d ",arrq[i]);
	}
	printf("-------->binary^^q\n");

	for(i=0;i<bit;i++){
		printf("%d ",arr2m[i]);
	}
	printf("--------->binary^^2m\n");

	for(i=0;i<bit;i++){
		printf("%d ",arra[i]);
	}
	printf("----------->binary^^a\n");
	printf("-------------------------\n");
	


	for(j=0;j<bit;j++){
		if(arrq[bit-1]==1){
			_c=add(arra,arrm);
			printf("a=a+m\n");
		}
/*----------------------------------------------------------------*/
	printf("%d    ",_c);    
	for(i=0;i<bit;i++){
		printf("%d ",arra[i]);
	}
	printf("    ");

	for(i=0;i<bit;i++){
		printf("%d ",arrq[i]);
	}
	printf("    \n");
/*-------------------------------------------------------------*/	 
	rshift(arra,arrq);
/*-------------------------------------------------------------*/
	printf("%d    ",_c);
	for(i=0;i<bit;i++){
		printf("%d ",arra[i]);
	}
	printf("    ");

	for(i=0;i<bit;i++){
		printf("%d ",arrq[i]);
	}
	printf("    \n");
	printf("-------------------------\n");

/*-----------------------------------------------------------------------------*/
	}
	int ans=decimal(arra,arrq);
	printf("ans-->%d\n\n",ans);
return 0;
}
