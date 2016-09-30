#include<bits/stdc++.h>
using namespace std;
int subsetSum(int* arr,int n,int target){
    bool dp[n+1][target+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int j=1;j<=target;j++){
        dp[0][j]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            dp[i][j]=dp[i-1][j];

            if(dp[i][j]==false and j>=arr[i-1]){
                dp[i][j]=dp[i][j] || dp[i-1][j-arr[i-1]];
            }

        }
    }
    /*
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return dp[n][target];

}
int main(){
        int arr[]={1,2,3,4,5,6,7,8,9,10};
        int target=17;
        cout<<subsetSum(arr,10,target)<<endl;

}
