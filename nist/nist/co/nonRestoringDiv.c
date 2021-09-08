#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<math.h>
int qsize=0;
int asize=0;
int *c=NULL;
void  add(int *a,int *b){
	int c=0,i,x;

	for(i=asize-1;i>=0;i--){
		x=a[i];
		a[i]=c^x^b[i];
		if((x==1 && c==1) || (x==1 && b[i]==1) ||(c==1 && b[i]==1))
			c=1;
		else
			c=0;
	}

}
void _2scomp(int *a){
int i;
	for(i=0;i<asize;i++){
		if(a[i])a[i]=0;
		else a[i]=1;
	}
	add(a,c);

}

void binary(int *arr,int n){

	int i=qsize-1;

	while(n){
		arr[i]=n%2;
		n/=2;
		i--;
	}

}

void binary2(int *arr,int n){

	int i=asize-1;

	while(n){
		arr[i]=n%2;
		n/=2;
		i--;
	}

}
void  lshift(int *a,int *q){

		int alast=a[0],qlast=q[0],i;
		for(i=0;i<asize-1;i++){
			a[i]=a[i+1];
		}
		a[asize-1]=q[0];
		for(i=0;i<asize-1;i++){
			q[i]=q[i+1];
		}
	
}


int decimal(int *a,int size){
	int ans=0,i,s=0;
	
	for(i=size;i>=0;i--){
		if(a[i]==1){
			ans+=(int)(pow(2,size-i-1));
			//printf("added-from a->%d   i=%d  bit=%d\n",(int)(pow(2,2*bit-i-1)),i,2*bit-i-1);
		}

	}
return ans;
}

int main(){

	int M,Q,i,j,_c=0;
	int *arra,*arrm,*arr2m,*arrq;
	printf("enter dividident and diviser \n");
	scanf("%d %d",&Q,&M);
	
	int tempQ=Q,tmpqsize=0;
	while(tempQ){
		tmpqsize++;
		tempQ=tempQ>>1;
	}
	qsize=tmpqsize;
	asize=qsize+1;
	c=(int*)malloc(sizeof(int)*asize);	
	c=memset(c,0,sizeof(asize));
	c[asize-1]=1;

	arra=(int *)malloc(sizeof(int)*asize);
	memset(arra,0,sizeof(int)*asize);

	arrm=(int *)malloc(sizeof(int)*asize);
	memset(arrm,0,sizeof(int)*asize);

	arr2m=(int *)malloc(sizeof(int)*asize);
	memset(arr2m,0,sizeof(int)*asize);

	arrq=(int *)malloc(sizeof(int)*qsize);
	memset(arrq,0,sizeof(int)*qsize);
	if(M<0){
		binary2(arrm,-1*M);
		_2scomp(arrm);
		binary2(arr2m,-1*M);
		//_2scomp(arr2m);

	}else{

		binary2(arrm,M);
		binary2(arr2m,M);
		_2scomp(arr2m);
	}
	if(Q<0){
		binary(arrq,-1*Q);
		_2scomp(arrq);
	}else{
	binary(arrq,Q);
	}

/*----------------------------------------------------------------------------------------*/

	for(i=0;i<asize;i++){
		printf("%d ",arrm[i]);
	}
	printf("------>M\n");

	for(i=0;i<qsize;i++){
		printf("%d ",arrq[i]);
	}
	printf("-------->Q\n");

	for(i=0;i<asize;i++){
		printf("%d ",arr2m[i]);
	}
	printf("--------->-M\n");

	for(i=0;i<asize;i++){
		printf("%d ",arra[i]);
	}
	printf("----------->A\n");
	printf("-------------------------\n");

int k=qsize;
for(j=0;j<qsize;j++){
/**----------------------------------------------------------------------------------*/
	for(i=0;i<asize;i++){
		printf("%d ",arra[i]);
	}
	printf("    ");

	for(i=0;i<qsize;i++){
		printf("%d ",arrq[i]);
	}
	printf("     %d\n",k);
/*--------------------------------------------------------------------------------------------*/	 
	if(arra[0]==1){
		lshift(arra,arrq);
		add(arra,arrm);
	}else{
		lshift(arra,arrq);
		add(arra,arr2m);
	}
	
		
/**----------------------------------------------------------------------------------*/
	for(i=0;i<asize;i++){
		printf("%d ",arra[i]);
	}
	printf("    ");

	for(i=0;i<qsize;i++){
		printf("%d ",arrq[i]);
	}
	printf("     %d<--left shift  \n",k);
/*--------------------------------------------------------------------------------------------*/	 
	
	if(arra[0]==1){
		arrq[qsize-1]=0;
	}else{
		arrq[qsize-1]=1;
	}
/**----------------------------------------------------------------------------------*/
	for(i=0;i<asize;i++){
		printf("%d ",arra[i]);
	}
	printf("    ");

	for(i=0;i<qsize;i++){
		printf("%d ",arrq[i]);
	}
	printf("     %d<-- a=a-m\n",k);
/*--------------------------------------------------------------------------------------------*/	 


/*-----------------------------------------------------------------------------------*/

	for(i=0;i<asize;i++){
		printf("%d ",arra[i]);
	}
	printf("    ");

	for(i=0;i<qsize;i++){
		printf("%d ",arrq[i]);
	}
	printf("     %d\n",k);
	printf("-------------------------\n");


/*--------------------------------------------------------------------------------------------*/
k--;
}

if(arra[0]==1)
	add(arra,arrm);

	int rem=decimal(arra,asize);
	int que=decimal(arrq,qsize);
	printf("quetient-->%d \n reminder-->%d\n",que,rem);
return 0;
}
