#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("A-large.in","r",stdin);
   freopen("A-large.out","w",stdout);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){
        cout<<"Case #"<<test<<": ";

        int n,m;
        cin>>n>>m;
        double ans=double(n-m)/double(m+n);
        printf("%.7lf\n",ans);
    }
}
