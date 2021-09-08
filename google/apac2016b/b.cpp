#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int modPow(int a,int b){
    long long int ans=1;
    while(b!=0){
        if(b%2==1)
            ans=(ans*a)%mod;

        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}

int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){
        cout<<"Case #"<<test<<": ";
        int a,b,n,k;
        cin>>a>>b>>n>>k;
        long long int ans=0;

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){

                    if((modPow(i,a)+modPow(j,b))%k==0){
                        ans++;
                        ans%=mod;
                    }
                    if((modPow(i,b)+modPow(j,a))%k==0){
                        ans++;
                        ans%=mod;
                    }


            }
        }
        cout<<ans<<endl;

    }
}
