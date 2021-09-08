#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k=3;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt=i;

        while(cnt<n){
                   printf(" ");
                    cnt++;
                }
          for(int j=0;j<i;j++){
                int ans=k*(k+1)/2;

                if(j<i-1)
                    printf("%05d ",ans);
                else
                    printf("%05d",ans);
                k+=4;
          }
            if(i<n)
            printf("\n");

    }

    return 0;
}
