/* merge sort which return number of innverson*/
/* count inversion in left array ,right array and cross inversion i.e. l[i]<r[j];
/* if we have k swaps then:
    if k<=inv then after k swap we have min of inv-k inversions remaining;
    if k>inv then
        if k is even then we have 0 inversions remaining
        if k is odd then we have 1 inversion remaining;
        because if odd we swap one adjecent pair odd number of times then one inversion left at end;
        if even we swap one adjecent pair and swap even number of times then we have zero inversion left;
        */

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
    int tt;
    cin>>tt;
    while(tt--){
    int n;
    cin>>n;
    int arr[n+3];
    int i=0;
    while(i<n){
        cin>>arr[i++];
    }
    int xx=sortAndCount(arr,0,(n-1));
    cout<<xx<<endl;
    if(xx<(n)){
        cout<<0<<endl;
    }else{
        cout<<(n)-xx<<endl;
    }
    }

}
