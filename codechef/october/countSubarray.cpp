#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define int64 int64_t
int f(vector <int64> &v){
    int64 ans=0;
    for(int64 i=0;i<v.size();i++){
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
        int64 n;
        cin>>n;
        vector <int64> v;
        for(int64 i=0;i<n;i++){
            int64 a;
            cin>>a;
            v.pb(a);

        }
        vector <int64> ans;
        flag=1;
        for(int64 i=0;i<n-1;i++){
            int64 c=0;
            flag=1;
            if(v[i]<v[i+1]){
                c++;
                i++;
            }else{

            }

            ans.pb(c);
        }
        int64 aa=f(ans);
        cout<<aa+n<<endl;
    }


return 0;
}
