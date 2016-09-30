#include<bits/stdc++.h>
using namespace std;
void RMQbuild(vector <int> Arr,vector <int> &SMT,int start,int end,int pos){
    if(start==end){
        SMT[pos]=Arr[start];
        return;
    }
    int mid=(start+end)/2;
    RMQbuild(Arr,SMT,start,mid,2*pos+1);
    RMQbuild(Arr,SMT,mid+1,end,2*pos+2);
    SMT[pos]=max(SMT[2*pos+1],SMT[2*pos+2]);
}
int RMQQuery(vector <int> Arr,vector <int> &SMT,int qstart,int qend,int start,int end,int pos){
    if(qstart<=start and qend>=end){
        return SMT[pos];
    }
    if(qstart>end || qend<start){
        return INT_MIN;
    }
    int mid=(start+end)/2;
    return max(RMQQuery(Arr,SMT,qstart,qend,start,mid,2*pos+1),RMQQuery(Arr,SMT,qstart,qend,mid+1,end,2*pos+2));
}

void print(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
   int tt;
   cin>>tt;
   while(tt--){

   	int n,k;
   	cin>>n>>k;
   	vector <int> arr(n);
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}
   	//print(arr);
   	int ans=0;
   	vector <int> smt(2*n-1);
   	RMQbuild(arr,smt,0,n-1,0);
   	//print(smt);
   	for(int i=0;i<n;i++){
   		for(int j=i;j<n;j++){
   			 int val=RMQQuery(arr,smt,i,j,0,n-1,0);

   			 if(val>k)ans++;
   			 //cout<<i<<" "<<j<<" "<<val<<" "<<ans<<endl;
   		}
   	}
   	cout<<ans<<endl;
   }


}
