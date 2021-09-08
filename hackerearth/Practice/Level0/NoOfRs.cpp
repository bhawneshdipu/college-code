#include<bits/stdc++.h>
using namespace std;
#define int64 int64_t
#define test() int tt;cin>>tt;cin.get();while(tt--)
int calcK(string s){
int cans=0;
    for(int k=0;k<s.size();k++){
        if(s[k]=='K')
            cans++;
    }
return cans;
}
int calcR(string s){
int cans=0;
    for(int k=0;k<s.size();k++){
        if(s[k]=='R')
            cans++;
    }
return cans;
}
int main(){
    test(){
        string str;
        cin>>str;
       int  n=str.size();
       vector <int> v;
        int total=0;
        for(int i=0;i<n;i++){
            if(str[i]=='R'){
                v.push_back(-1);
                total++;
                }
                else
                v.push_back(1);

        }
        int ans=0,tans=0;
        for(int i=0;i<n;i++){
                tans=max(v[i],tans+v[i]);

                    ans=(max(ans,tans));
        }

        (ans!=0)?cout<<ans+total<<endl:cout<<total-1<<endl;;
    }
return 0;
}
