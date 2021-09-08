#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map <int,int> mp;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        if(k!=0)
            mp[k]=1;
        else
            mp[i]=1;

    }
    for(int i=1;i<=n;i++)
        if(mp[i]==0)
            cout<<i<<" ";

}
