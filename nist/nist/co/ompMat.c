#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(){

	printf("enter mat size\n");
	int n,i,j;
	scanf("%d",&n);
	int **a=(int**)(malloc(sizeof(int *)*n));
	int *b=(int*)(malloc(sizeof(int *)*1));
	int *c=(int*)(malloc(sizeof(int *)*1));
	for(i=0;i<n;i++){
		*(a+i)=(int*)malloc(sizeof(int)*n);
	}

	printf("enter a\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j]=rand()%3;
		}
	}
	printf("enter b vector \n");
	for(i=0;i<n;i++)
		b[i]=rand()%3;

	#pragma omp parallel for private(j)

	for(i=0;i<n;i++){
		c[i]=0;
		int t=0;
		#pragma omp parallel for reduction(+:t)
		for(j=0;j<n;j++){
			t+=a[i][j]*b[j];
		}
		c[i]=t;
	}

	for(i=0;i<n;i++){
		printf("%d  \n",c[i]);
	}



}
