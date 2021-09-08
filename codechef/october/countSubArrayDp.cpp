#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test() int tt;cin>>tt;while(tt--)
int  DP(vector <int> &a,vector <int> &dp){
    dp[1] = 1;
    for (int i=2;i<a.size();i++)
        if (a[i] > a[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = dp[i-1];

}
int main(){
_
    test(){
        int n;
        cin>>n;
        vector <int> v,dp(n,0);
            for(int i=0;i<n;i++){
                int a;
                cin>>a;
                v.push_back(a);
            }
        int ans=n;
            DP(v,dp);

            cout<<ans+dp[n-1]<<endl;;
      }

}
