#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
int county(string str){
    int n=str.size();
    int ans=0;
    for(int i=0;i<n;i++){
        if(str[i]=='Y')
            ans++;
    }
return ans;
}

int main(){
_
    test(){
        int n;
        cin>>n;
        cin.get();

        string str;
        getline(cin,str);
        stringstream s(str);

        vector <int> v;
        for(int i=0;i<n;i++){
            string st;
            s>>st;
            v.push_back(st.size()-county(st)+1);
        }
        sort(v.begin(),v.end());
        cout<<v[0]<<endl;
    }
}
