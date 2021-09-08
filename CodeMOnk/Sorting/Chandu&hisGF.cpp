#include<bits/stdc++.h>
using namespace std;
#define boost() cin.sync_with_stdio(false);cout.sync_with_stdio(false);
#define test() int tt;cin>>tt;cin.ignore();while(tt--)

int main(){
    test(){
            int n;
            cin>>n;
            vector <int> v;
            while(n--){
                int a;
                cin>>a;
                v.push_back(a);
            }
            sort(v.begin(),v.end(),greater <int>);
            for(int i=0;i<n;i++)
                cout<<v[i]<<" ";
                cout<<endl;
    }

}
