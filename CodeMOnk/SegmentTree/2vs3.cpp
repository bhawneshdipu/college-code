#include<bits/stdc++.h>
using namespace std;
long long int fun(string str){
long long int ans=0;
    int i=str.size();
    if(i>1){
        string s=str.substr(str.size()-2,2);
        if(s[0]=='0' && s[1]=='0')
            return 0;
            else if(s[0]=='0' && s[1]=='1')
            return 1;
            else if(s[0]=='1' && s[1]=='0')
            return 2;
            else if(s[0]=='1' && s[1]=='1')
            return 0;
        }else {
            if(str[0]==0)
                return 0;
                else
                    return 1;

        }

}
int main(){
     int n;
    cin>>n;
    string str;
    cin>>str;

    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        if(a==0){
            int l,r;
            cin>>l>>r;
            cout<<fun(str.substr(l,r-l+1))<<endl;

        }else{
            int k;
            cin>>k;
            str[k]='1';
            //cout<<"index="<<n-k-1<<endl;
            //cout<<b<<endl;
        }

    }

}
