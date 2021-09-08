#include<bits/stdc++.h>
using namespace std;
int64_t toValue(vector <int64_t > &v){
    int64_t ans=0;
    for(int i=0;i<v.size();i++){
        ans*=10;
        ans+=(v[i]);
    }
    //cout<<"ans="<<ans<<endl;
    return ans;
}
int main(){
    int tt;
    cin>>tt;
    cin.get();
    while(tt--){
        string str;
        getline(cin,str);
        stringstream s(str);
        vector <int64_t> v;
        int64_t temp;
        while(s>>temp){

            v.push_back(temp);
        }
        int64_t x;
        cin>>x;
        int ans1=0,ans2=0;
        do{

               int64_t a=toValue(v);
                for(int i=1;i<=a/x;i++){
                    if(a==x*i){
                        ans1=i;
                        ans2=a;
         //               cout<<"ans1="<<ans1<<"ans2="<<ans2<<endl;
                        break;
                    }
                }
                if(ans1!=0)break;

        }
        while(next_permutation(v.begin(),v.end()));
        if(ans1!=0)
        cout<<ans2<<" ="<<" "<<x<<" "<<"*"<<" "<<ans1<<endl;
        else{
            cout<<"Impossible"<<endl;
        }
    }

}
