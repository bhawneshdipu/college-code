#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        int *arr=(int*)malloc(sizeof(int)*n+7);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int dup[n+7];
        int i=0;
        int j=n-1;
        int k=0;
        while(i<j){
            dup[k++]=arr[j--];
            dup[k++]=arr[i++];
        }
        dup[k]=arr[i];
        for(int i=0;i<n;i++){
            cout<<dup[i]<<" ";
        }
        cout<<endl;
    }

}
