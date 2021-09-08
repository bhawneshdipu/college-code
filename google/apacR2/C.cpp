
#include<bits/stdc++.h>
using namespace std;
int countprime(int n){
int l=sqrt(n);
int ans=0;
if(n>3)
for(int i=2;i<=l;i++){
if(n%i==0){
  while(n%i==0)
        n/=i;
}
ans++;
}
return ans;
}


int main(){
//freopen("C-small-attempt0.in","r",stdin);
//freopen("C-small-attempt0.out","w",stdout);
int tt;
cin>>tt;
for(int test=1;test<=tt;test++){
cout<<"Case #"<<test<<": ";
int n;
cin>>n;
int ans=countprime(n);
if(ans%2==1)
cout<<"Laurence\n";
else
cout<<"Seymour\n";


}

}
