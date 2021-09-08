#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){
        cout<<"Case #"<<test<<": ";
        int n;
        cin>>n;
        cin.ignore();
        map <string,int> mp;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            string str;
            getline(cin,str);
            set <char> st;
            for(int j=0;j<str.size();j++){
                if(str[j]!=' '){
                    st.insert(str[j]);
                }
            }
            mp[str]=st.size();
            ans=max(ans,int(st.size()));

        }
        vector <pair <string,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end());
        string leader=v[0].first;
        for(int i=0;i<v.size();i++){
            if(v[i].second==ans){
                leader=v[i].first;
                break;
            }
        }
        cout<<leader<<endl;



    }

}
