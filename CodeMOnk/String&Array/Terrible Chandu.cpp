#include<bits/stdc++.h>
using namespace std;

#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define pd(a) printf("%lf",a)


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
    for(int i=l-1;i>-1;--i)
    {
        cout<<str[i];
    }
    cout<<endl;
}


return 0;
}
