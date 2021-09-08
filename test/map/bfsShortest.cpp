#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void _bfsMinDist(vector < vector <int> > &v,int start){
    vector <bool> visited(v.size());
    vector <int> minDist(v.size(),-1);
    int level=0;
    visited[start]=1;
    minDist[start]=0;
   // cout<<start<<" ";
    queue <int> q;
    q.push(start);
        while(q.empty()==0){
            start=q.front();
            q.pop();
            for(auto i=0;i<v[start].size();i++){
                    if(visited[v[start][i]]==0){
                    visited[v[start][i]]=1;
                   // cout<<v[start][i]<<"  ";
                    q.push(v[start][i]);
                    minDist[v[start][i]]=minDist[start]+1;
                    }

            }
            //cout<<endl;
        }
        for(auto i=0;i<v.size();i++){
            if(minDist[i]>0)
                minDist[i]*=6;

            if(minDist[i]!=0)
                cout<<minDist[i]<<" ";
        }
        cout<<endl;
}
int main(){

    int tt;
    cin>>tt;
    while(tt--){

    int n;
    cin>>n;
    vector < vector <int> > v(n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);

    }
    int start;
    cin>>start;
    _bfsMinDist(v,start-1);

}
}
