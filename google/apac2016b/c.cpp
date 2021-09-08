#include<bits/stdc++.h>
using namespace std;

int fun(vector <pair <int,int>>v,int index){
    map<int,int>mp;
    for(int i=0;i<v.size();i++){
        if(i!=index){
            pair <int ,int> p=v[i];
     //       cout<<"["<<p.first<<" "<<p.second<<"]";
            for(int j=p.first;j<=p.second;j++){
                if(mp[j]==0){
                    mp[j]=1;
                }
            }
        }
    }
    return(mp.size());
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){
        cout<<"Case #"<<test<<": ";
        int n,l1,r1,a,b,c1,c2,m;
        cin>>n>>l1>>r1>>a>>b>>c1>>c2>>m;
        vector <pair <int,int> > v;
        int xpre=l1;
        int ypre=r1;
        v.push_back(make_pair(l1,r1));
        for(int i=1;i<n;i++){
            int x=(a*xpre+b*ypre+c1)%m;
            int y=((b*xpre+a*ypre+c2)%m);
            xpre=x;
            ypre=y;
           int  li=min(x,y);
            int ri=max(x,y);
            v.push_back(make_pair(li,ri));
        }
        int ans=INT_MAX;
        for(int i=0;i<v.size();i++){
            ans=min(ans,fun(v,i));
        }
        cout<<ans<<endl;

    }
}
