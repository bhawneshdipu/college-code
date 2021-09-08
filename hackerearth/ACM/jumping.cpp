#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
int main(){
_
    test(){
        int n,q;
        cin>>n>>q;
        set <int> s;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            s.insert(a);
        }
        vector <int> v(s.begin(),s.end());
        sort(v.begin(),v.end(),greater <int> ());
        int ans=0;
        vector <int> a(n-1,0);
        for(int i=0;i<n-1;i++){
            a[i]=abs(v[i]-v[i+1]);
        }
        int sum=accumulate(a.begin(),a.end(),0,plus <int> ());
        cout<<sum*q<<endl;
    }

}
