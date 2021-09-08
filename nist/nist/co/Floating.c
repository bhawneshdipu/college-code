#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define bit 32

void binary(int *arr,float f){
int count=0;
int it=(int)(f);
int ff=f-(int)f;
int k=0;
int flot[5];
int real[bit-5];

int i=bit-5;
	while(it){
		arr[i]=it%2;
		it/=2;
		i--;
	printf("in binary int ");
	}
 i=bit-5;
count=5;

	while(count-- && f){
		f=f*2;
		if(f>0.99999)
		arr[i]=1;
		else
		arr[i]=0;
		f=f-(int)f;
	printf("in binary float ");
	}


}
void normalization(int *arr,int *arre,int *arrm){
	int count=0;
	int i=0;
	int e;
	for(i=0;i<32;i++){
		if(arr[i]==1)
		count=i;
 		break;
	}
for(i=bit-1;i>count;i--){
	arrm[i]=arr[i];
	}
if(count>bit-5){
	e=bit-5-count;
}
else{
	e=count-bit-5;

}

binary(arre,e);



}
int floating(int *arr,int*arre,int *arrm,int s,float f){
	
binary(arr,f);
normalization(arr,arre,arrm);
}


int main(){
	int *arr=(int*)malloc(sizeof(int)*32);
	memset(arr,0,sizeof(int)*32);
	int *arre=(int*)malloc(sizeof(int)*8);
	memset(arre,0,sizeof(int)*8);

	int *arrm=(int*)malloc(sizeof(int)*bit-9);
	memset(arrm,0,sizeof(int)*(bit-9));	
	float f;
	int s;
	printf("enter floating point num\n");
	scanf("%f",&f);
	if(f>0)
	s=0;
	else 
	s=1;

	floating(arr,arre,arrm,s,f);
int i;

printf("%d ",s);
for(i=0;i<8;i++)
printf("%d ",arre[i]);

for(i=0;i<bit-9;i++)
printf("%d ",arrm[i]);
}
