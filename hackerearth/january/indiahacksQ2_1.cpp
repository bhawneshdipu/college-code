#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        ll num=n;
        ll ans=(n*n*n)-(n-2)*(n-2)*(n-2);

        if(num==1){
            cout<<1<<endl;
        }else {
            cout<<ans<<endl;
        }
    }
}
