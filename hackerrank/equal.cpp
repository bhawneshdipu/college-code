#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);
#define test() int tt;cin>>tt;for(int test=1;test<=tt;test++)
int fmin(int x){
int a=0;
            if(x/5>0){
                a+=(x/5);
                x%=5;
            }
            if(x/2>0){
                a+=(x/2);
                x%=2;
            }

            a+=(x);
    return a;
}
int main(){
    test(){
        int n;
        cin>>n;
        vector <int> v;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());

            vector <int> ans(6,0);
            long long int sum[6];
        for(int j=0 ; j<=5 ; j++)
        {
        int a=0;
            for(int i=0;i<n;i++){
                a+=fmin(abs(v[i]-(v[0]-j)));
            }
            ans[j]=a;
        }
        cout<<*min_element(ans.begin(),ans.end())<<endl;
    }
}
