#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);cin.tie(false);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        map <int,int> mp;
        int k=0;
        vector <bool> v(n);
        for(int i=m;i<n;i++){
            mp[i]=k++;

        }
        for(int i=0;i<m;i++)
            mp[i]=(k++);

        int flag=1;
        int count=0;
        k=0;
        while(1){
            if(v[mp[k]]==0){
                v[mp[k]]=1;
                k=mp[k];
                count++;
            }else{
                break;
            }


        }
        if(count==n)cout<<"Yes"<<endl;
        else
            cout<<"No "<<count<<endl;
    }

}
