#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        vector <int> va(n),vb(n);
        long long int sum=0;
        int key=0;
        for(int i=0;i<n;i++){
            cin>>va[i];
        }

        for(int i=0;i<n;i++){
            cin>>vb[i];
        }


        pair <int,int> mxa,mxb,mia,mib;
        for(int i=0;i<n;i++){
            int x,y;
            x=va[i];
            y=vb[i];
            if(mxa.first<x){
                mxa.first=x;
                mxa.second=y;
            }
            if(mxb.second<y){
                mxb.first=x;
                mxb.second=y;
            }
            if(mia.first>x){
                mia.first=x;
                mia.second=y;
            }
            if(mib.second>y){
                mib.first=x;
                mib.second=y;
            }

            int pro=x*y;
            sum+=pro;
        }
        int pos=max(mxa.first,mxb.second);
        int neg=min(mia.first,mib.second);
        int aa=max(abs(pos),abs(neg));
        sum+=(aa*k);
        cout<<sum<<endl;
    }
}

