#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int tree[MAX];//tree array
int A[MAX];//orignal array

void build(int node,int start,int end){
    if(start==end){
        tree[node]=A[start];
    }
    else{
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);

        tree[node]=tree[2*node]+tree[2*node+1];
    }
}


void update(int node,int start,int end,int idx,int val){
    if(start==end){
        tree[node]+=val;
        A[idx]+=val;
    }
    else{
        int mid=(start+end)/2;
        if(start<=idx and idx<=mid)
        update(2*node,start,mid,idx,val);
        else
        update(2*node+1,mid+1,end,idx,val);

        tree[node]+=tree[2*node]+tree[2*node+1];
    }
}

int query(int node,int start,int end,int left,int right){
    if(right<start or left>end){
        return 0;
    }
    if(left<=start and end <=right){
        return tree[node];
    }
    int mid=(start+end)/2;
    int leftquery=query(2*node,start,mid,left,right);
    int rightquery=query(2*node+1,mid+1,end,left,right);
    return(leftquery+rightquery);

}

int main(){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>A[i];
        memset(tree,0,sizeof(int)*MAX);
        build(1,1,n-1);
        for(int i=1;i<2*n;i++)
            cout<<tree[i]<<"----";
        cout<<endl<<query(1,1,n-1,3,6)<<endl;;
}
