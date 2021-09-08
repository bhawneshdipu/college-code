#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){
        cout<<"Case #"<<test<<": ";
        int l,r;
        cin>>l>>r;
        long long int n=min(l,r);
        cout<<n*(n+1)/2<<endl;
    }
}
