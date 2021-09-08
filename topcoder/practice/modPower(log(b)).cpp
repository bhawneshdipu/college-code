#include<bits/stdc++.h>
using namespace std;
int modPow(int a,int b,int m){
    int ans=1;
    while(b!=0){
        if(b%2==1)
            ans=(ans*a)%m;

        a=(a*a)%m;
        b/=2;
    }
    return ans;
}
int main(){
    cout<<modPow(19,21,1000000007)<<endl;

}
