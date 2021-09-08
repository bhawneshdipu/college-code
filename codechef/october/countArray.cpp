#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
int f(vector <int> &v){
    int64_t ans=0;
    for(int i=0;i<v.size();i++){
        while(v[i]>0){
            ans+=v[i];
            v[i]--;
        }
    }
    return ans;
}
int main(){
_
    test(){
        int n;
        cin>>n;
        vector <int> v;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.pb(a);

        }
        vector <int> ans;
        for(int i=0;i<n-1;i++){
            int c=0;

            while(v[i]<=v[i+1]){
                i++;
                c++;

            }
            ans.pb(c);
        }
        int aa=f(ans);
        cout<<aa+n<<endl;
    }


return 0;
}
