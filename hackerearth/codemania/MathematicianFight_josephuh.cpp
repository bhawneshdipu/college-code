#include<bits/stdc++.h>
using namespace std;


int sol(int n){
if(n==1)
    return 1;
    else{
        if(n%2==1)
            return 2*sol(n/2)+1;
            else if(n%2==0){
                return 2*sol(n/2)-1;
            }


    }

}
int main(){
int tt;
cin>>tt;
while(tt--){
    int n;
    cin>>n;
    cout<<sol(n)<<endl;
    }
    }
