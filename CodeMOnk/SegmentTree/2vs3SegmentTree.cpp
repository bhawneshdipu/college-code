#include<bits/stdc++.h>
using namespace std;

//build for sum query
void build(int node,int start,int end){
    if(start=end)
        tree[node]=arr[node];
    else{
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);

        tree[node]=tree[2*node]+tree[2*node+1];

    }

}


int main(){
cin.sync_with_stdio(false);
cout.sync_with_stdio(false);

}
