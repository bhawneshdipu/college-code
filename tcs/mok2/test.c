#include<stdio.h>
int main(){
        int n,i,j;
    scanf("%d",&n);
    int arr[n];
    int dist;
    scanf("%d",&dist);
    for(i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    int ans=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
                if(arr[i]+arr[j]==dist)
                    ans=1;
        }
    }
    if(ans==1)
        printf("1");
    else
        printf("0");
}
