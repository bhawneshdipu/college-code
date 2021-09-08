#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int fsum=0;
void fun(int *arr,vector <int> v,int k,int n){

    if(k>n)
        return ;
    int ans=0;




    list <int> l1(v.begin(),v.end());
    l1.push_back(arr[k]);
    vector <int> v1(l1.begin(),l1.end());
    fun(arr,v1,k+1,n);

    list <int> l2(v.begin(),v.end());
    l2.push_front(arr[k]);
    vector <int> v2(l2.begin(),l2.end());
    fun(arr,v2,k+1,n);

  if(k==n){
        for(int i=0;i<n-1;i++){
            ans+=(v[i]*v[i+1])%MOD;
            ans%=MOD;
        }
        //cout<<"ans="<<ans<<"k=="<<k<<endl;
        fsum+=ans;
        fsum%=MOD;
        /*for(int i=0;i<v.size();i++){
        cout<<v[i]<<"::";
        }
        cout<<endl;*/
        return;
    }
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<=n;i++){
            cin>>arr[i];
        }
        fsum=0;
        vector <int> v;
        v.push_back(arr[0]);
        fun(arr,v,1,n+1);
        cout<<fsum<<endl;
    }
}
