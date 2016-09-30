#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstring>

#define NMAX 110

using namespace std;


int mem[NMAX][NMAX];

int A[NMAX];

int N;

int min_cost(int i, int j){
	if(j < i) return 0;
	int &val = mem[i][j];
	if(val >= 0) return val;

	int k,ff,fl,lf,ll;
	ff = fl = lf = ll = 0;

	for(k = 0; k < i; ++k){
		ff += A[i] > A[k],	fl += A[i] < A[k];
		lf += A[j] > A[k], ll += A[j] < A[k];
	}

	for(k = j+1; k < N; ++k){
		ff += A[i] > A[k],	fl += A[i] < A[k];
		lf += A[j] > A[k], ll += A[j] < A[k];
	}

	val = min(min_cost(i+1,j)+min(fl,ff),min_cost(i,j-1)+min(lf,ll));
	return val;
}

int main(){

	int i,t;

	scanf("%d",&t);

	while(t--){
		scanf("%d",&N);
		memset(mem,-1,sizeof(mem));
		for(i =0 ; i < N; ++i){
			scanf("%d",&A[i]);
		}

		printf("%d\n",min_cost(0,N-1));
	}

	return 0;
}
