#include<bits/stdc++.h>
using namespace std;

#define rep(it,container) for(auto it=container.begin();it!=container.end();it++)
#define rev(it,container) for(auto it=container.rbegin();it!=container.rend();it++)


int main(){
std::cout.sync_with_stdio(false);
std::cin.sync_with_stdio(false);

int n,q;
cin>>n>>q;
map <int ,bool>m;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    m[a]=true;
}
for(int i=0;i<q;i++){
    int a;
    cin>>a;
    if(m[a]==true)
        puts("YES");
        else
            puts("NO");
}


return 0;
}
