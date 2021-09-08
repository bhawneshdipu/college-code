#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);
#define test() int tt;cin>>tt;for(int test=1;test<=tt;test++)
#define vi vector <int>
#define vis vector <pair <int ,vector <string> > >
#define pb push_back
#define vs vector <string>
int64_t check(vector <pair <int64_t,int64_t> > v){
map <int64_t,int64_t> s;
    for(int64_t i=0;i<v.size();i++){
        if(v[i].first!=0){
        int64_t files=(v[i].second*100)/v[i].first;
        //cout<<files<<endl;
        s[files]+=1;
        }
    }
    int64_t ans=-1;
    for(auto i=s.begin();i!=s.end();i++){
        int64_t file=i->first;
        int64_t feq=i->second;
        if(feq>((v.size()/8)))
        ans=file;
    }
    return ans;
}
int main(){
_
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);

    test(){
        cout<<"Case #"<<test<<": ";
        int64_t n;
        cin>>n;
        vector <pair <int64_t,int64_t> > v;
        for(int64_t i=0;i<n;i++){
            int64_t a,b;
            cin>>a>>b;
            v.pb(make_pair(a,b));
        }
        cout<<check(v)<<endl;

    }
}
