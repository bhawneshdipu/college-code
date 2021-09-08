#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator () (string s1,string s2){
        if(s1.size()!=s2.size())
        return s1.length()<s2.length();
        else
            s1<s2;
    }
};




int minOp(string str1,string str2){
    int ans=0;
    //cout<<str1<<" "<<str2<<endl;
    if(str1.size()>str2.size()){
        swap(str1,str2);
    }
    int index=str1.size();
    for(int i=str1.size();i>=0;i--){
        if(str1[i]!=str2[i]){
            index=i-1;
        }

    }
    if(index==-1){
        return str1.size()+str2.size();
    }
    return (str2.size()+str1.size()-2*(index+1));
}


int n,k;
int val[1000][1000];
vector <string > vans;
int ans=INT_MAX;
string arr[1000];




void DFS(int i,int frame,vector  <string> str,int total,vector <int> visited)
{


    //cout<<"i="<<i<<" frame="<<frame<<" k="<<k<<" total="<<total<<endl;
    visited[i]=1;
    vector <string > v1(str.begin(),str.end());

    v1.push_back(arr[i]);
   // cout<<"pushed "<<arr[i]<<endl;
    if(frame==k){
        //cout<<"equal"<<endl;
        if(ans>total){
                ans=total;
                vans=v1;
         //       cout<<"answer="<<ans<<" total="<<total<<endl;
                for(int i=0;i<vans.size();i++){
                    cout<<vans[i]<<" ";
                }
                cout<<endl;

        }
    }

    int j;
    //printf("\n%d",i);

    for(j=1;j<=n;j++)
        if(visited[j]==0 && val[i][j]>0 && total<=ans && frame<=k)
            DFS(j,frame+1,v1,total+val[i][j],visited);
}
int main(){
    freopen("in4.txt","r",stdin);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){
        cout<<"Case #"<<test<<": ";
        cin>>n>>k;

        arr[0]="";
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n+1);
        sort(arr,arr+n+1,cmp());
        for(int i=0;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        vans.clear();
        vector <string> sarr;



        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                val[i][j]=minOp(arr[i],arr[j]);
            }
        }
        cout<<endl;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                cout<<val[i][j]<<" ";
            }
            cout<<endl;
        }

        ans=INT_MAX;
        vector <int> visited(1000,0);
        for(int i=0;i<=n;i++){
            visited[i]=0;
        }
            DFS(0,0,sarr,0,visited);


        //cout<<"ans before ="<<ans<<endl;

        ans+=k;
        ans+=vans[vans.size()-1].size();

        cout<<ans<<endl;
    }
}
