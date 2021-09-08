#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0)
        return b;
        else
            return (gcd(b,a%b));

}
int arrayGCD(int arr[],int l,int r){
    if(r-l<2){
        return(gcd(arr[l],arr[r]));
    }else{
        int mid=(l+r)/2;
        int left=arrayGCD(arr,l,mid);
        int right=arrayGCD(arr,mid+1,r);
        return gcd(left,right);

    }
}

int main(){
    int arr[]={3,6,9,12,18,21,24,27,30,33};
    cout<<arrayGCD(arr,0,9);
}
