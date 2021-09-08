#include<bits/stdc++.h>
using namespace std;
#define i64 long long int
i64 mod(i64 a,i64 b){
    i64 ret=a%b;
    if(ret<0)
        ret+=b;
    return ret;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        i64 n,m,z;
        cin>>n>>m>>z;
        vector <i64> v;
        for(int i=0;i<n;i++){
            i64 temp;
            cin>>temp;
            v.push_back(temp);
        }

        for(int i=n;i<=z;i++){
            int l=v.size();
            i64 ak=0;
            int flag=1;
            for(int j=l-1;j>l-1-n;j--){
                if(flag==0){
                    ak-=v[j];
                    flag=1;
                }else {
                    flag=0;
                    ak+=v[j];
                }


            }
            ak=mod(ak,m);
            v.push_back(ak);
        }
        cout<<v[v.size()-1]<<endl;
    }
}
