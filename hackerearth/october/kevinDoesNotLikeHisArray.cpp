#include<bits/stdc++.h>
using namespace std;
#define _ ios:: sync_with_stdio(0);
#define __ int tt;cin>>tt;for(int test=1;test<=tt;test++)
bool isLike(vector <int> v){
int n=v.size();
    for(int i=0;i<n-1;i++){
        if(v[i]==v[i+1])
            return 0;
    }
    //cout<<"true"<<endl;
return 1;
}
vector <int> ans;
void  sol(vector <int> v,int a,int n,int x){
//cout<<a<<endl;
    if(a>n*n)
        return;
    else if(ans.size()>n*n)
        return ;
    else if(isLike(v)){
        ans.push_back(a);
  //      cout<<"hiiiiiiii"<<endl;
  /*      for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
            cout<<endl;
    */
        return;
    }else{

        for(int k=x;k>0;k--){
            for(int i=0;i<n-k;i++){
                reverse(v.begin()+i,v.begin()+k);
                sol(v,a+1,n,k-1);

                reverse(v.begin()+i,v.begin()+k);

            }
        }

    }


}
int main(){
_
    int n;
    cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++){
                int a;
                cin>>a;
                v.push_back(a);
    }
    sol(v,0,n,n);

    if(ans.size()>0){
    	sort(ans.begin(),ans.end());
    	cout<<ans[0]<<endl;
    }
    else{
    	cout<<"-1"<<endl;
    }
}
