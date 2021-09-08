#include <cstdio>
 
int D(int N){
	int res=0;
	while(N){
		res+= (N&1) ? N%10 : 2*(N%10);
		N/=10;
	}
	return res%10;
}
 
int C(int hi){
	int res=0;
	while(hi%10)
		res+=D(--hi);
	return res+45*(hi/10);
}
 
int main(){
	int T, A, B;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &A, &B);
		printf("%d\n", C(B+1)-C(A));
	}
	return 0;
}