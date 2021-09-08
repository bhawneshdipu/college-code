#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
int ispal(string str){
    for(int i=0;i<str.size();i++){
        if(str[i]!=str[str.size()-1-i])
            return 0;
    }
    return 1;
}
int main(){
_
    test(){
        string a,b;
        cin>>a>>b;
        int ans=0;
        for(int i=0;i<=a.size();i++){
            string aaa=a.substr(0,i)+b;
            if(i<a.size())
                aaa+=a.substr(i);
                if(ispal(aaa))
                ans++;
        }
        cout<<ans<<endl;
    }

}
