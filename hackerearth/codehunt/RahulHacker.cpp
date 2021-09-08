#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int tt;
	cin>>tt;
	while(tt--){
		int64_t a,b,s,ans=0;
		cin>>a>>b;
		s=a+b;
		while(s){
            ans*=(10);
            ans+=(s%10);
            s/=10;
		}
		cout<<ans<<endl;

	}

 return 0;
}
