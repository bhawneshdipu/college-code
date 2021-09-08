#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
int main(){
_
    test(){
        int n;
        cin>>n;
        map <int,int> m;
        vector <int> v;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.pb(a);
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[j]<v[i]){
                    m[v[i]]+=1;
                }
            }
            cout<<m[v[i]]<<" ";
        }
        cout<<endl;

    }
return 0;
}
