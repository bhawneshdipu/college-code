//https://www.hackerearth.com/indiahacks-code-hunt-2r/algorithm/equal-candies-distribution-3/

#include<bits/stdc++.h>
using namespace std;
int cal(vector <int> v,int n){
long long int ans=0;
    for(int i=1;i<n;i++){
        v[i]-=v[0];
    }
    for(int i=1;i<n;i++){
        if(v[i]/5>0){
            ans+=(v[i]/5);
            v[i]%=5;
        }
        if(v[i]/2>0){
            ans+=(v[i]/2);
            v[i]%=2;
        }
        if(v[i]>0){
            ans+=v[i]/1;
            v[i]%=1;
        }

    }
    return ans;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector <int> v;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            v.push_back(a);

        }
        cout<<cal(v,n)<<endl;

    }
}
