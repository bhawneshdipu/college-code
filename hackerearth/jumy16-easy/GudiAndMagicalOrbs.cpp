#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,m,k;
        cin>>n>>m>>k;
        int arr[n][m];
        memset(arr,0,sizeof(int)*n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        int ans[n][m];
        memset(ans,0,sizeof(int)*m*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=arr[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0){
                    //ans[i][j]+=arr[i][j];
                }else{
                    if(i==0 and j!=0){
                        ans[i][j]+=(ans[i][j-1]);
                    }else if(j==0 and i!=0){
                        ans[i][j]+=(ans[i-1][j]);
                    }else if(i!=0 and j!=0){
                        ans[i][j]+=max(ans[i-1][j-1],max(ans[i-1][j],ans[i][j-1]));
                        //cout<<"min of "<<ans[i][j-1]<<" "<<ans[i-1][j-1]<<" "<<ans[i-1][j]<<" total="<<ans[i][j]<<endl;
                    }
                }
            }
        }
        cout<<"------------------"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

        if(ans[n-1][m-1]<=k)
        cout<<ans[n-1][m-1]<<endl;
        else
            cout<<"-1"<<endl;
    }
}
