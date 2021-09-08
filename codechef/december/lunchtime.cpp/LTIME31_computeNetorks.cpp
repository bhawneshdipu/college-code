#include<bits/stdc++.h>
using namespace std;
int main(){
   int tt;
   cin>>tt;
   while(tt--){
    int m,n;
    cin>>m>>n;
    if(m==n){

        for(int i=0;i<m;i++){

            cout<<(i)%m+1<<" "<<(i+1)%m+1<<endl;
        }
    }else{
        cout<<"-1"<<" "<<"-1"<<endl;
    }
   }
}
