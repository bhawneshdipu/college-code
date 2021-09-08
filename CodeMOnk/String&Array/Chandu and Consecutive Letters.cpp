#include<bits/stdc++.h>
using namespace std;

#define rep(it,container) for(auto it=container.begin();it!=container.end();it++)
#define rev(it,container) for(auto it=container.rbegin();it!=container.rend();it++)

typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <vi> vii;
int main(){
std::cout.sync_with_stdio(false);
std::cin.sync_with_stdio(false);
int tt;
cin>>tt;
cin.ignore();
while(tt--){
    string str;
    cin>>str;
    int l=str.size();
    string ans;
    for(int i=0;i<l;i++){
        if(i==0)
            ans+=str[0];
            else{
                if(str[i]==ans[ans.size()-1])
                    continue;
                    else
                        ans+=str[i];

            }
    }
    cout<<ans<<endl;

}


return 0;
}
