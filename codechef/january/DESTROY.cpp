//cook66 DESTROY
#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
            int n;cin>>n;
            int *arr=(int*)malloc(sizeof(int)*n+7);
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
            sort(arr,arr+n);
            int ans=0;
            for(int i=0;i<n-1;){
                if(arr[i]!=arr[i+1]){
                        ans++;
                        i+=2;
                }else{
                    ans+=2;
                    i+=2;
                }
                if(i==n-1)ans++;

            }
            cout<<ans<<endl;




    }
}
