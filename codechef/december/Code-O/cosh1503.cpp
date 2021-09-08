#include<bits/stdc++.h>
using namespace std;
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
    }
    */
    int ans=INFINITY;
    for(int i=1;i<=target;i++){
        if(dp[n][i])
        ans=min(ans,abs(i-abs(target-i)));
    }
    return ans;
    //return dp[n][target];

}

int main(){
    int tt;
    scanf("%d",&tt);
    while(tt--){
        int n;
        scanf("%d",&n);
        int *arr=(int *) malloc(sizeof(int)*n);
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",arr+i);
            sum+=(arr[i]);
        }
        int ans=subsetSum(arr,n,sum);
        printf("ans=%d\n",ans);
    }
}
