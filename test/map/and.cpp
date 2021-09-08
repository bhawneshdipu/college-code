#include<iostream>
#include<bitset>
using namespace std;
int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int a,b;
        cin>>a>>b;
        bitset <32> b1(a);
        bitset<32> b2(b);
        bitset <32> b3=(b1&b2);
        int flag=1;
        for(int i=31;i>=0;i--){
            if(b2.test(i)==1 && b1.test(i)==0 && flag==1){
            flag=0;
            b3.reset(i);
            }else if(flag==0){
                b3.reset(i);
            }
        }
       /* cout<<b1<<endl;
        cout<<b2<<endl;
        cout<<b3<<endl;
        */
        cout<<b3.to_ulong()<<endl;
    }
}
