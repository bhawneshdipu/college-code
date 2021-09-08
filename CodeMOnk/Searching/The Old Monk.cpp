#include<bits/stdc++.h>
using namespace std;

#define rep(it,container) for(auto it=container.begin();it!=container.end();it++)
#define rev(it,container) for(auto it=container.rbegin();it!=container.rend();it++)


int main(){
std::cout.sync_with_stdio(false);
std::cin.sync_with_stdio(false);

int tt;
cin>>tt;
while(tt--){
    int n;
    cin>>n;
    vector <long long int> a;
    vector <long long int> b;
    for(int i=0;i<n;i++){
        long long int item;
        cin>>item;
        a.push_back(item);
    }
    for(int i=0;i<n;i++){
        long long int item;
        cin>>item;
        b.push_back(item);
    }
    int ans=0;
    for(int i=0;i<n;i++){
       int f = 0 , l = n-1 , m;
			int pos = -1;
			while(f <= l)
			{
				m = (f+l)/2;
				if(b[m] >= a[i])
				{
					pos = m;
					f = m + 1;
				}
				else
				{
					l= m - 1;
				}
			}
			ans = max(ans,pos - i);

        }

    cout<<ans<<endl;
}

return 0;
}

