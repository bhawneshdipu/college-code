#include <bits/stdc++.h>
using namespace std;

int isPalin(string a){
	int l=a.size();
	int flag=1;
	for(int i=0;i<l/2;i++){
		if(a[i]!=a[l-1-i]){
			flag=0;
			break;
		}


	}

	return flag;
}
int main()
{
	int tt;
	cin>>tt;
	while(tt--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		int l=a.size();
		for(int i=0;i<l;i++){
			string test=a.substr(0,i);
			string test2=a.substr(i);
			string final=test+b+test2;
			if(isPalin(final)){
				ans+=1;

			}


		}
		cout<<ans<<endl;
	}
    return 0;
}
