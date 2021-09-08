#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int BIT[MAX],A[MAX],n;
int query(int x){
    int sum=0;
    while(x>0){
        sum+=BIT[x];
        x-=(x&-x);
    }
    return sum;
}
int query(int left,int right){
    return query(right)-query(left-1);
}
void update(int idx,int val){
    while(idx<=n){
    BIT[idx]+=val;
    idx+=(idx & -idx);
    }
}
void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
}
int main(){
    memset(BIT,0,sizeof(BIT));
    memset(A,0,sizeof(A));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        update(i,A[i]);
    }
    for(int i=1;i<=n;i++)
        cout<<A[i]<<" ";
        cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<BIT[i]<<" ";
        cout<<endl;
    cout<<"Query(5)="<<query(5)<<endl;;
    cout<<"Query(2 ,5)="<<query(2,5)<<endl;
}

