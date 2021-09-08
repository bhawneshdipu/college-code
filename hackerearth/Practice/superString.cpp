#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
int main(){
_
    test(){
        string str;
        cin>>str;
        vector <int> v(26,0);
        for(int i=0;i<str.size();i++){
            v[26-str[i]-'a']+=1;
        }
        int ans=1;
        for(int i=0;i<27;i++){
            if(v[i]!=i+1)
                ans=0;
        }
        (ans)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }


return 0;
}
