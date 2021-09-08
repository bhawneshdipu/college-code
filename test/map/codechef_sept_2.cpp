#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vector <int> v;
        int count=0;
        for(int i=0;i<m;i++){
            int a;
            cin>>a;
            if(a==1)
                count++;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int ans=m-1;
        ans-=count;
        cout<<ans<<endl;
    }

}
