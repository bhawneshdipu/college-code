#include<bits/stdc++.h>
using namespace std;
map <pair <int,int>,pair <int,vector <int> > > m;
void pre(){
for(int i=1;i<=50;i++){

    for(int j=i+1;j<=50;j++){
       int sum=0; vector <int> v;
            for(int k=i;k<=j;k++){
                sum+=(k);
                v.push_back(k);
            }

            //for(int i=0;i<v.size();i++)
              //  cout<<v[i]<<" ";
            //    cout<<"sum="<<sum<<endl;
            m[make_pair(sum,(v.size()))]=make_pair(1,v);

    }

}
}
int main(){
pre();
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        int arr[n];
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        sort(arr,arr+n);
        //cout<<"sum"<<sum<<endl;
        if(m[make_pair(sum,n)].first==1 || m[make_pair(sum,n-1)].first==1 ){
          int ans1=99999999,ans2=99999999;
            if(m[make_pair(sum,n)].first==1){
                vector <int> v=m[make_pair(sum,n)].second;
                ans1=0;
                for(int i=0;i<n;i++){
               cout<<arr[i]<<"-"<<v[i]<<endl;
                    int p=(arr[i]-v[i]);
                    if(p>0)
                    ans1+=(p);
                }
            }
                if(m[make_pair(sum,n-1)].first==1){
                vector <int> v=m[make_pair(sum,n-1)].second;
                ans2=0;
                for(int i=0;i<n;i++){
                    cout<<arr[i]<<"-"<<v[i]<<endl;
                    int p=(arr[i]-v[i]);
                    if(p>0)
                    ans2+=(p);
                }
                }
                int ans=min(ans1,ans2);
                cout<<ans<<endl;

        }else{
            cout<<"-1"<<endl;
        }

    }
}
