#include<bits/stdc++.h>
using namespace std;
int iarr[100005];

map <int,int> mp;
int temp[100005];
int totinv=0;
void merge(int* arr,int left,int mid,int right){
    int p=left,q=mid+1,k=0,inv=0;
    for(int i=left;i<=right;i++){
        if(p>mid){
            temp[k++]=arr[q++];
        }else if(q>right){
            mp[arr[p]]+=inv;
            temp[k++]=arr[p++];
        }else if(arr[p]<=arr[q]){
            temp[k++]=arr[p];
            mp[arr[p]]+=inv;
            p++;
        }else{
            temp[k++]=arr[q++];
            inv++;
            totinv+=(mid+1-p);
        }

    }
    for(int i=0;i<k;i++){
        arr[left++]=temp[i];
    }
}
void mergeSort(int* arr,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);

    }else
        return;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        memset(temp,0,sizeof(temp));
        mp.clear();
        int n;
        cin>>n;
        int arr[n];
        int dup[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            dup[i]=arr[i];
        }
        mergeSort(arr,0,n-1);
        for(int i=0;i<n;i++){
            cout<<mp[dup[i]]<<" ";
        }
    }

}
