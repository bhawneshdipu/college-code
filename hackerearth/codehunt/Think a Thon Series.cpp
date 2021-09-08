#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){
        int l,p,c;
        cin>>l>>p>>c;
        int ans=0;
       bool flag=1;
        int s=l;
        while(s*c<p){

        	ans++;
        	s*=c;
        }
        ans++;
        cout<<"tans==>"<<ans<<endl;
        int a=0;
		while((1<<a)<ans){
			a++;

		}

        cout<<"Case #"<<test<<": "<<a<<endl;
    }

}
