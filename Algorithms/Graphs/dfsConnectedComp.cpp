#include<bits/stdc++.h>
using namespace std;

int dfs(vector < vector <int> > &v){
    vector <bool> visited(v.size(),0);
    stack <int> s;
    int connectedComp=0;
    for(int i=0;i<v.size();i++){
    if(visited[i]==0){
        visited[i]=1;
        s.push(i);
        connectedComp++;
        while(s.empty()==0){
            int start=s.top();s.pop();
          //  cout<<start+1<<endl;  to print order of visit
            for(int j=0;j<v[start].size();j++){
                if(visited[v[start][j]]==0){
                    visited[v[start][j]]=1;
                    s.push(v[start][j]);
                }
            }
        }
    }
    }
    return connectedComp;
}


int main(){

        int n;//nodes
        cin>>n;
        int m;//edged
        cin>>m;
        vector <vector <int> > v(n);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            v[a-1].push_back(b-1);//-1 as node num starts from 1 and index from zero;
            v[b-1].push_back(a-1);
        }

        cout<<"connected Components= "<<dfs(v)<<endl;;

}


