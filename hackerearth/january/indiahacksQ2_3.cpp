#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main()
{
   ll n,k;
   cin>>n>>k;
   int *arr=(int *)(malloc(sizeof(int)*n+7));
   for(int i=0;i<n;i++)cin>>arr[i];
   int rep=0;
   while(rep<=k){
        ll ans=0;
        for(int i=1;i<=k;i++){
            ans+=(i*i*arr[rep+i-1]);
        }
        rep++;
        cout<<ans<<" ";
    }
}
