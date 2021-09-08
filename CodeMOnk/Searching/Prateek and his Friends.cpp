#include<bits/stdc++.h>
using namespace std;

#define rep(it,container) for(auto it=container.begin();it!=container.end();it++)
#define rev(it,container) for(auto it=container.rbegin();it!=container.rend();it++)
std::cout.sync_with_stdio(false);
std::cin.sync_with_stdio(false);


int main(){

int tt;
cin>>tt;
while(tt--){
    int n,x;
    cin>>n>>x;
    vector <int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int sum=v[0],tsum=0;
    bool flag=0;


    int beg=0;
    for(int i=1;i<n;i++){

    			while(sum>x){
    				sum-=v[beg++];
    			}
    			if(sum==x){
    			flag=1;
    			break;
    			}
    			sum+=v[i];


    }
    	while(sum>x){
    		sum-=v[beg++];
    	}
    	if(sum==x)
    		flag=1;




    (flag)?puts("YES"):puts("NO");

}


return 0;
}
