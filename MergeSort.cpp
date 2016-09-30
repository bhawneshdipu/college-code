/* merge sort which return number of innverson*/

#include<bits/stdc++.h>
using namespace std;

int mergeCount(int* arr,int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int larr[n1+1],rarr[n2+1];
    for(int i=0;i<n1;i++)
        larr[i]=arr[l+i];
    for(int j=0;j<n2;j++)
        rarr[j]=arr[m+j+1];

    larr[n1]=INFINITY;
    rarr[n2]=INFINITY;
    int i=0;
    int j=0;
    int inv=0;
    for(int k=l;k<=r;k++){
        if(larr[i]<=rarr[j])
            arr[k]=larr[i++];
            else{
                arr[k]=rarr[j++];
                inv+=(n1-i);
            }
    }
    return inv;
}
int sortAndCount(int *arr,int l,int r){
    if(l<r){

        int mid=(l+r)/2;
        int leftInv=sortAndCount(arr,l,mid);
        int rightInv=sortAndCount(arr,mid+1,r);
        int crossInv=mergeCount(arr,l,mid,r);
        return (leftInv+rightInv+crossInv);
    }else
        return 0;

}
int main(){
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    cout<<"number of inv:"<<sortAndCount(arr,0,9)<<endl;;
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }

}
