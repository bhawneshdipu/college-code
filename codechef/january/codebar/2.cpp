#include<bits/stdc++.h>
using namespace std;
int seive(int l,int r){
vector <bool> v(1000000,1);

    v[0]=0;
    v[1]=0;
    bool flag=0;
    int count=0;
    for(int i=2;i*i<=r;i++){

        if(v[i]==1){
                for(int j=i*i;j<=r;j+=i){
                    v[j]=0;
                }
        }

    }
    for(int i=l;i<=r;i++)
        if(v[i])count++;
return count;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){

        int a,b;
        cin>>a>>b;
        cout<<seive(a,b)<<endl;
    }
}
