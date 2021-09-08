#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);
#define _test() int tt;cin>>tt;for(int test=1;test<=tt;test++)

bool check(vector <int> v,int n,int k){
    for(int i=0;i<n;i++){
        if(abs(v[i]-(i+1))>k)
            return 0;
    }
    return 1;

}
int score(vector <int> v,int n){
    int ans=1;
        for(int i=1;i<=n;i++){
            ans*=abs(v[i-1]-i);
        }
        //cout<<"inv="<<ans<<endl;
        return ans;
}
int countInv(vector <int> v,int n){
    int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i]>v[j])
                    ans++;
            }
        }
        //cout<<"score="<<ans<<endl;
return ans;
}
int main(){
_
    _test(){
        int n,k,m;
        cin>>n>>k>>m;
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        int kevin=0;
        int marv=0;
        do{

            if(check(v,n,k)){
                int a=countInv(v,n);
                if(a%2==0 && a!=0)
                    kevin+=(score(v,n));
                else
                    marv+=score(v,n);

            //    cout<<kevin<<"   "<<marv<<endl;
            }

        }while(next_permutation(v.begin(),v.end()));
        cout<<kevin-marv<<endl;
    }
}
