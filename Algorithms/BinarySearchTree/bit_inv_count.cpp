#include <algorithm>
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long llong;

const int MAXN = 5000200;
llong tree[MAXN], A[MAXN], B[MAXN];

llong read(int idx){
 llong sum = 0;
 while (idx > 0){
  sum += tree[idx];
  idx -= (idx & -idx);
 }
 return sum;
}
void update(int idx ,llong val){
 while (idx <= MAXN){
  tree[idx] += val;
  idx += (idx & -idx);
 }
}
int main(int argc, char *argv[])
{
	//ios::sync_with_stdio(false);
	int t,i,j;
	cin>>t;
	while(t--){
   int N;
   cin>>N;
      memset(tree, 0, sizeof(tree));
      for(int i = 0; i < N; ++i) {
        cin>>A[i];
         B[i] = A[i];
      }
      sort(B, B + N);
      for(int i = 0; i < N; ++i) {
         int rank = int(lower_bound(B, B + N, A[i]) - B);
         A[i] = rank + 1;
      }
      llong inv_count = 0;
      vector<int>v(N);
      for(int i = N - 1; i >= 0; --i) {
         llong x = read(A[i] - 1);
         v[i]=x;

         inv_count += x;
         update(A[i], 1);
      }
      int i;
      for(i=0;i<N;i++)
      printf("%d ",v[i]);
      printf("\n");

//for(i=0;i<N;i++)
//{
//	int ans=0;
//	for(j=i+1;j<N;j++)
//	{
//		if(A[j]<A[i])ans++;
//	}
//	cout<<ans<<" ";
//}
//cout<<"\n";
	}
   return 0;
}
