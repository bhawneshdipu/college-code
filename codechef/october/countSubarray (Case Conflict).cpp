#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define test() int tt;cin>>tt;while(tt--)
int is(vector <int> &v,int i,int k){
//cout<<"i="<<i<<"  "<<"k="<<k<<endl;
    for(int j=i;j<i+k-1;j++){
        if(v[j]>v[j+1])
            return 0;
    }
  //  cout<<"true"<<endl;
    return 1;
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
            v.push_back(a);
        }
        int flag=0;
        int ans=v[0],tans=0;
        for(int k=2;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                    if(v[i]<v[i+1])
                        ans++;
            }

           if(ans==tans)break;//becaue if there is no n-1 size subarray than their is no n size subarray;
           }

        cout<<ans<<endl;
    }


}
