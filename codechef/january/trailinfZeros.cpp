#include <iostream>
using namespace std;
#define ll long long
int trailingZeros(int n){
    int count=0;
    for(int i=5;i<n;i*=5){
        count+=(n/i);
    }
    if(n==5)return 1;
    return count;
}
int main()
{
   	ll tt;
   	cin>>tt;
   	while(tt--){
   		ll n;
   		cin>>n;

   		int ans=0;
   		int result=0;
            for(int i=n;i<=10000;i++){
            ans=trailingZeros(i);
            result=i;
            if(ans>=n)break;
   		}
   		cout<<result<<endl;

   	}
    return 0;
}
