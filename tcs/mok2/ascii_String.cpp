#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        string str;
        cin>>str;
        int ans=0;
        map <char,int> mp;
        int cnt=0;

        for(int i=0;i<str.size();i++){
            if(mp[str[i]]==0)
                cnt+=(str[i]+1-'a');
            mp[str[i]]+=1;

        }
        if(str.size()==cnt){
            for(int i=0;i<str.size();i++){
                if(mp[str[i]]>(str[i]+1-'a')){
                    ans+=2*(mp[str[i]]-(str[i]+1-'a'));
                }
            }
        }else if(str.size()>cnt){

        }else {

        }

    }

}
