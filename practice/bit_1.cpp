//https://www.hackerearth.com/problem/algorithm/xsquare-and-two-arrays/

#include<bits/stdc++.h>
using namespace std;
#define MAX 300000
int BIT1[MAX]={0};
int BIT2[MAX]={0};
void update(int t,int idx,int val,int n){
    for(int i=idx;i<=n;i+=(i&-i)){
        if(t==1)
            BIT1[i]+=val;
        else
            BIT2[i]+=val;
    }
}
void update(int t,int l,int r,int val,int n){
    update(t,l,val,n);
    update(t,r+1,-val,n);
}
int query(int t,int x){
    int sum=0;
    for(int i=x;i>0;i-=(i&-i)){
        if(t==1)
        sum+=BIT1[i];
        else
            sum+=BIT2[i];
    }
    return sum;
}
int query(int t,int l,int r){
    return query(t,r)-query(t,l-1);
}
int main(){
    freopen("in.txt","r",stdin);
    int n,q;
    cin>>n>>q;
    int a[n+7],b[n+7];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int j=1;j<=n;j++){
        cin>>b[j];
    }
    int ta[MAX]={0};
    int tb[MAX]={0};
    int flag=0;
    for(int i=1;i<=n;i++){
        if(flag==0){
            ta[i]=a[i];
            update(1,i,ta[i],n);
            flag=1;

        }else{
            ta[i]=b[i];
            update(1,i,ta[i],n);
            flag=0;
        }
    }
    flag=1;
    for(int i=1;i<=n;i++){
        if(flag==0){
            tb[i]=a[i];
            update(2,i,tb[i],n);
            flag=1;

        }else{
            tb[i]=b[i];
            update(2,i,tb[i],n);
            flag=0;
        }
    }
    //for(int i=1;i<=n;i++)cout<<ta[i]<<" .";
    //for(int i=1;i<=n;i++)cout<<tb[i]<<" _";

    for(int i=0;i<q;i++){
        int t,l,r;
        cin>>t>>l>>r;
        if(t%2==0){
            if(l%2==0)
            cout<<query(1,l,r)<<endl;
            else
                cout<<query(2,l,r)<<endl;

        }else{
            if(l%2==0)
                cout<<query(2,l,r)<<endl;
                else{
                    cout<<query(1,l,r)<<endl;
                }

        }
    }
}



