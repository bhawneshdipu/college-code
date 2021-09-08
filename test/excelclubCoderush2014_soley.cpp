#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
int main(){
_
    test(){
        int n;
        cin>>n;
        vector <string> v;

            for(int i=0;i<n;i++){
                       string c;
                        cin>>c;
                        v.push_back(c);
            }
            vector <vector <int> > sol(n,vector<int> (n,0));
    int q;
    cin>>q;
    while(q--){
        int a,b;
        int ans=-1,flag=0;
        cin>>a>>b;
        int k=1;
            vector <int> st;
            st.push_back(a);
            while(st.size()>0 and flag==0){
                a=st[st.size()-1];
                st.pop_back();
                for(int j=0;j<n;j++){
                    if(v[a][j]=='Y'){
                        sol[a][j]=k;
                        st.push_back(j);
                        if(j==b){
                            ans=k;
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag)break;
                 k++;
            }
        cout<<ans<<endl;

    }
}
return 0;
}
