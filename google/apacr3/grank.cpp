#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);
#define test() int tt;cin>>tt;for(int test=1;test<=tt;test++)
#define vi vector <int>
#define vis vector <pair <int ,vector <string> > >
#define pb push_back
#define vs vector <string>
struct cmp{
    bool operator () (pair <int,vector <string >> p1,pair <int,vector <string >> p2){
        return p1.first>p2.first;

    }
};
struct cmp2{
    bool operator () (pair <string,int> p1,pair <string,int> p2){
        return p1.second>p2.second;
    }
};
int main(){
_
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    test(){
        cout<<"Case #"<<test<<":"<<endl;
        int p;// places with points
        cin>>p;
        vi s;//each place points
        for(int i=0;i<p;i++){
            int a;
            cin>>a;
            s.pb(a);
        }
        int n;//total num of competitions
        cin>>n;
        vis v;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            vs name;
            for(int j=0;j<p;j++){
                string str;
                cin>>str;
                name.pb(str);
            }
            v.pb(make_pair(a,name));
        }
        int m;//num of compitition taken into account;
        cin>>m;
        sort(v.begin(),v.end(),cmp());
        /*for(int i=0;i<n;i++){
            cout<<v[i].first<<"  "<<v[i].second[0]<<"  "<<v[i].second[1]<<endl;
        }*/
        map <string,int> mm;
        map <string,int> mp;
        for(int i=0;i<n;i++){
            int times=v[i].first;

            for(int j=0;j<p;j++){
                string winner=v[i].second[j];
                if(mp[winner]<p){
                mm[winner]+=times*s[j];
              //  cout<<winner<<"----"<<mm[winner]<<endl;
                mp[winner]+=1;
                }
            }
        }

        set <pair <string,int> > sans(mm.begin(),mm.end());

        vector  <pair <string,int> > vans(sans.begin(),sans.end());
        sort(vans.begin(),vans.end(),cmp2());
       /* for(int i=0;i<vans.size();i++){
            cout<<vans[i].first<<"  "<<vans[i].second<<endl;

        }*/
        vector <pair <string,int> > ans=vans;
        ans[0].second=1;
        int curr=2;
        int temp=0;
        for(int i=0;i<ans.size()-1;i++){
            if(vans[i].second==vans[i+1].second){
                while(vans[i].second==vans[i+1].second){
                    ans[i+1].second=ans[i].second;
                    curr++;
                    i++;
                }

            }

                ans[i+1].second=curr++;
        }

        for(int i=0;i<ans.size();i++){
            cout<<ans[i].second<<": "<<ans[i].first<<endl;

        }
    }

}
