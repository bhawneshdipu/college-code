#include<bits/stdc++.h>
using namespace std;
int  main(){
    int tt;
    cin>>tt;
    while(tt--){
        int m,n;
        cin>>n>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int ans=0;
        int l=0,r=n-1;
        for (int i=0;i<=n/2;i++){
            if(arr[l]+arr[r]<=m){
                ans+=1;
                l++;r--;
            }else {
                    ans++;
                    r--;

            }
        }
        cout<<ans<<endl;



        }
    }

