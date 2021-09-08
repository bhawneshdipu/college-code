#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    cin.ignore();
    while(tt--){
        string str;
        cin>>str;
        int ans=0;
        set <char> s;
        auto pre=str[0];
        for (auto i=1;i<str.size();i++){
                if(pre==str[i]){
                    ans++;
                }else
                    pre=str[i];

        }
        cout<<ans<<endl;
    }
}
