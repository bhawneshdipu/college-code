#include<bits/stdc++.h>
using namespace std;
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
#define boost() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
boost();

    int n;
    cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++){
    	int a;
    	cin>>a;
    	v.push_back(a);

    }

	int ans=0;
		do{
			for(int i=0;i<n;i++){
                int ans1=accumulate(v.begin(),v.begin()+i,0,bit_xor <int> ());
                int ans2=accumulate(v.begin()+i,v.end(),0,bit_xor <int> ());
              //  cout<<ans1<<"   "<<ans2<<endl;
                int ans3=max(ans1,ans2);
                ans=max(ans,ans3);
                cout<<ans<<endl;
			}

		}while(next_permutation(v.begin(),v.end()));

		cout<<ans<<endl;
}
