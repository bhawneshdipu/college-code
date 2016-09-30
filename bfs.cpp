#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void _bfs(vector < vector <int> > &v,int start){
    vector <bool> visited(v.size());
    vector <int> minDist(v.size(),-1);
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


}
int main(){
    int n;
    cout<<"enter number of nodes\n"<<endl;
    cin>>n;
    vector < vector <int> > v(n+1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);

    }
    _bfs(v,1);


}
