#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define ll long long
ll n;
ll *BIT;
void update(ll index,ll val){
    for(;index<=n;index+=(index&-index)){
        BIT[index]+=val;
    }
}
ll query(ll index){
    ll sum=0;
    for(;index>0;index-=(index&-index)){
        sum+=BIT[index];
    }
    return sum;
}
ll query(ll left,ll right){
    return (query(right)-query(left-1));
}

int main(){
//ios_base::sync_with_stdio(0);
//cin.tie(0);
    freopen("in3.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tt;
    cin>>tt;
    BIT=(ll*)(malloc(sizeof(ll)*MAX));

    for(int test=1;test<=tt;test++){
        cout<<"Case #"<<test<<": ";
        memset(BIT,0,sizeof(ll)*MAX);
        ll p;
        cin>>n>>p;
        vector <ll> v(n+1);

        for(ll i=1;i<=n;i++){
            cin>>v[i];
            update(i,v[i]);
        }

        ll ans=0;

        for(ll i=1;i<=n;i++){
            for(ll j=i;j<=n;j++){
                if(query(i,j)<=p)ans++;
            }
        }
        cout<<ans<<endl;
    }
}
