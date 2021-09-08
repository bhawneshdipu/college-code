#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int kp(int i){
    int64_t a=i*i;
    stringstream s(to_string(a));
    string str;
    s>>str;
    string s1=str.substr(0,str.length()/2);
    string s2=str.substr(str.length()/2);
    stringstream s11(s1);
    stringstream s22(s2);
    int64_t a1,a2;
    s11>>a1;
    s22>>a2;
   // cout<<i<<"  "<<a1<<"   "<<a2<<endl;
    if(a1+a2==i)
        return 1;
        else
            return 0;

}
int main(){
_
    int p,q;
    cin>>p>>q;
    for(int i=p;i<=q;i++){
        if(kp(i)==1)
            cout<<i<<" ";
    }

}
