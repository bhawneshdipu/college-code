#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
int power(int n,int p){
    int ans=1;
        while(p){
            if(p&1)
            ans*=n;
            p>>=1;

            n*=n;
        }
        return ans;
}
int main(){
_
    test(){
        int n;
        cin>>n;
        int flag=0;
        vector <int> a,b;
        a.pb(1);b.pb(1);
        for(int i=2;i<=n;i++){
            for(int j=2;j<=n;j++){
                int aa=power(i,j);
                if(aa>n)break;

                a.pb(aa);
                //cout<<i<<"  "<<j<<"  "<<aa<<endl;
              }
        }

            for(int ii=2;ii<=n;ii++){
                    for(int jj=2;jj<=n;jj++){
                        int aa=power(ii,jj);
                        if(aa>n)break;
                        b.pb(aa);
                        //cout<<aa<<endl;
                    }
            }


        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                int aa=a[i]+b[j];
                if(aa==n){
                    flag=1;
                  //  cout<<aa<<"  "<<n<<endl;
                    break;
                }
            }
            if(flag)break;
        }
        flag ? cout<<"Yes"<<endl:cout<<"No"<<endl;

    }
return 0;
}
