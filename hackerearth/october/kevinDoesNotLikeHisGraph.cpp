#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);
#define _test() int tt;cin>>tt;for(int test=1;test<=tt;test++)
int main(){
    int n,m;
    cin>>n>>m;
    vector <vector <int> > v(n,vector <int> );
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    int mx=-1;
    for(int i=0;i<n;i++){
        sort(v[i].begin(),v[i].end());
        mx=max(v[i].size(),mx);
    }
    int edges=0;
    for(int i=0;i<n;i++){
        edges+=(mx-v[i].size());
    }
    vector <pair <int,int > > vp;
    int ans=edges;
    while(edges){
        if(v[i].size()<mx){
                for(int j=1;j<=n;j++){
                    if(v[i][j])
                    vp.push_back(i,j)
        }

    }
}
