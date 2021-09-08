//cook66 FRUITS
#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,m,k;
        cin>>n>>m>>k;
        if(abs(n-m)<=k)cout<<0<<endl;
        else
        cout<<abs(n-m)-k<<endl;
    }
}
