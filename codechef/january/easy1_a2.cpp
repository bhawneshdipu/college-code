#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


int main(){
    int tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        ll arr[n+1];
        for(int i=0;i<=n;i++){
            cin>>arr[i];
        }
        ll fsum=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                fsum+=(arr[i]*arr[j]);
            }
        }
        cout<<fsum<<endl;
    }
}
