#include<bits/stdc++.h>
using namespace std;

int main(){
//freopen("in.txt","r",stdin);
    int tt;
    cin>>tt;
    while(tt--){

        int n;
        string s;
        cin>>n>>s;
        int flag[26];
        for(int i=0;i<26;i++)
            flag[i]=0;
        for(int i=0;i<s.size();i++){

            flag[s[i]-'a']+=1;
        }
        string str;
        vector <pair <string,pair <int ,int> > >v(n);
        int k=1;
        for(int i=0;i<n;i++){
            cin>>str;
            v[i].first=str;
            v[i].second.first=i;
            for(int j=0;j<str.size();j++){
                v[i].second.second+=flag[str[j]-'a'];
            }
        }
       /* for(int i=0;i<n;i++){
            cout<<v[i].first<<"  "<<v[i].second.first<<"  "<<v[i].second.second<<endl;
        }*/

   //     sort(v.begin(),v.end(),cmp());
     pair <string,pair <int,int> > p=v[0];
     for(int i=1;i<n;i++){
        if(v[i].second.second>p.second.second)
            p=v[i];
        else if(v[i].second.second==p.second.second and v[i].first.size()<p.first.size())
            p=v[i];
            else if(v[i].second.second==p.second.second and v[i].first.size()==p.first.size() and v[i].second.first<p.second.first)
            p=v[i];
     }
        cout<<p.second.first+1<<endl;
    }

}
