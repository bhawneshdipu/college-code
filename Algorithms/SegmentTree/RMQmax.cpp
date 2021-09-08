#include<bits/stdc++.h>
using namespace std;
void RMQbuild(int* Arr,int *SMT,int start,int end,int pos){
    if(start==end){
        SMT[pos]=Arr[start];
        return;
    }
    int mid=(start+end)/2;
    RMQbuild(Arr,SMT,start,mid,2*pos+1);
    RMQbuild(Arr,SMT,mid+1,end,2*pos+2);
    SMT[pos]=max(SMT[2*pos+1],SMT[2*pos+2]);
}
int RMQQuery(int *Arr,int *SMT,int qstart,int qend,int start,int end,int pos){
    if(qstart>=start and qend<=end){
        return SMT[pos];
    }
    if(qstart>end || qend<end){
        return INT_MIN;
    }
    int mid=(start+end)/2;
    return max(RMQQuery(Arr,SMT,qstart,qend,start,mid,2*pos+1),RMQQuery(Arr,SMT,qstart,qend,mid+1,end,2*pos+2));
}

int main(){
    int Arr[]={1,2,3,4,5,6,-11,10};
    int SMT[15]={INT_MIN};//size is 2*n - 1
    RMQbuild(Arr,SMT,0,7,0);
    for(int i=0;i<15;i++){
        cout<<SMT[i]<<" ";
    }
    cout<<endl;

    cout<<RMQQuery(Arr,SMT,1,4,0,7,0)<<endl;;
}
