#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long int calcMin(vector<int> &vect)
{
	sort(vect.begin(), vect.end());
	for(int i=1;i<vect.size();i++)
		vect[i]-=vect[0];
	long long int ret = 0;

	for(int i=1;i<vect.size();i++)
	{
		if(vect[i]/5>0)
		{
			ret=ret+vect[i]/5;
			vect[i]%=5;
		}
		if(vect[i]/2>0)
		{
			ret=ret+vect[i]/2;
			vect[i]%=2;
		}
		if(vect[i]>0)
		{
			ret=ret+vect[i]/1;
			vect[i]%=1;
		}
	}
	return ret;
}

int main()
{
	int t,n, i, j, temp;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		vector<int> vect;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>temp;
			vect.push_back(temp);
		}
		cout<<calcMin(vect)<<endl;
	}
	return 0;
}
