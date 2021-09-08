#include<bits/stdc++.h>
using namespace std;
#define test() int tt;cin>>tt;cin.get();while(tt--)
#define boost() cin.sync_with_stdio(false);cout.sync_with_stdio(false);
bitset <7 > mymax(bitset <7> &b1,bitset <7> &b2){
        if(b1.to_ulong()<b2.to_ulong()){
            return b2;
        }
return b1;
}
int main(){
boost();
    int n;
    cin>>n;
    vector <bitset <7> > v;
    for(int i=0;i<n;i++){
         int a;
            cin>>a;
            v.push_back(bitset <7> (a));
    }
    bitset <7> b,bt1,bt2,temp;
    for(int i=0;i<n;i++){
        bt1=v[0];
        bt2=v[i];
        for(int j=i+1;j<n;j++){

            bt1=bt1^v[j];

        }
        for(int j=1;j<i;j++){
            bt2=bt2^v[j];
        }
        temp=mymax(bt1,bt2);
        b=mymax(b,temp);
    }
    cout<<b.to_ulong()<<endl;

}
