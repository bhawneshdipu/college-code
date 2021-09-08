#include<bits/stdc++.h>
using namespace std;

#define rep(it,container) for(auto it=container.begin();it!=container.end();it++)
#define rev(it,container) for(auto it=container.rbegin();it!=container.rend();it++)

std::cout.sync_with_stdio(false);
std::cin.sync_with_stdio(false);


int main(){
int tt;
cin>>tt;
while(tt--){
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    int i=0,ans=0;
    while(i<=k){
        if((a*i*i+b*i+c)>=k){
            ans=i;
            break;
        }
i++;
    }
    cout<<ans<<endl;
}
return 0;
}
