#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        string str;
        cin>>str;
        set <string> ss;
        for(int i=0;i<str.size()-1;i++){
            string s="";
            s+=str[i];
            s+=str[i+1];
            ss.insert(s);
        }
        cout<<ss.size()<<endl;
    }
}
