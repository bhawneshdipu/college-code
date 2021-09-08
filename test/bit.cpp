#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int BIT[MAX];
int n;
void update(int index,int val){
   for(;index<=n;index+=(index&-index)){
        BIT[index]+=val;
   }

}
void update(int left,int right,int val){
    update(left,val);
    update(right+1,-val);
}
int query(int index){
    int sum=0;
    for(;index>0;index-=(index&-index)){
            sum+=BIT[index];
    }
    return sum;
}
int query(int left,int right){
    return(query(right)-query(left-1));
}
int main(){
    cin>>n;
    int arr[n+1];
    memset(BIT,0,sizeof(int)*(n+1));
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        update(i,arr[i]);
    }
    cout<<query(3,6)<<endl;
}
