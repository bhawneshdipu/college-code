#include<bits/stdc++.h>
using namespace std;
#define NUM 102
vector < vector <long long int> > arr(NUM,vector <long long int> (NUM,0));

int ncr(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(i==0 || j==0 )
                arr[i][j]=1;
                else{
                    arr[i][j]=(arr[i-1][j-1]+arr[i-1][j]);
                }
        }
    }
}

int main(){
ncr(100);

for(int i=0;i<50;i++){
    for(int j=0;j<=i;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
}

