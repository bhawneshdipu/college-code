#include <bits/stdc++.h>
using namespace std;
int main() {
	long long tt;
	cin>>tt;
	while(tt--)
	{
		long long int n;
	    cin>>n;
	    long long count=0;
	    for(int i=2;i*i<=n;i++)
	    {
	        if(n%i==0 && n/i!=i)
	        {
	            count=count+2;
	        }
	        else if(n%i==0)
	        {
	            count=count+1;
	        }
	    }
	    cout<<count+1<<endl;
	}
	return 0;
}
