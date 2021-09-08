#include<bits/stdc++.h>
using namespace std;
int modPow(int a,int b,int c){
    int ans=1;
    while(b!=0){
        if(b%2==1){
            ans*=a;
            ans%=c;
        }
        a*=a;
        b/=2;
        a%=c;
    }
return ans;
}
int main(){
    int a=10,b=10;
    cout<<modPow(a,b,10000007)<<endl;

}
