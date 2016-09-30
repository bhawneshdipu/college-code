#include<bits/stdc++.h>
using namespace std;
int A[100001];
typedef long long ll;
ll merge(int *A,int i,int mid,int j)
{
	int pos1=i,pos2=mid+1;
	int temp[j-i+1];
	ll c=0;
	for(;pos1<=mid&&pos2<=j;)
	{
		if(A[pos1]<=A[pos2])
		{
			temp[pos1+pos2-i-mid-1]=A[pos1];
			pos1++;
		}
		else
		{
			temp[pos1+pos2-i-mid-1]=A[pos2];
			pos2++;
			c+=mid-pos1+1; // Main line
		}
	}
	while (pos1<=mid)
	{
			temp[pos1+pos2-i-mid-1]=A[pos1];
			pos1++;
	}
	while (pos2<=j)
	{
			temp[pos1+pos2-i-mid-1]=A[pos2];
			pos2++;
	}
	for (pos1=i;pos1<=j;pos1++)
		A[pos1]=temp[pos1-i];

	return c;

}

ll msort(int *A,int i,int j)
{
	if (i>=j)
	{
		return 0;
	}
	int mid=(i+j)/2;
	ll c=0;
	c+=msort(A,i,mid);
	c+=msort(A,mid+1,j);
	c+=merge(A,i,mid,j);
	return c;

}
int main()
{
	int t,ass;
	scanf("%d",&t);
	for (ass=1;ass<=t;ass++)
	{
		int n,k,i;
		scanf("%d%d",&n,&k);
		for (i=0;i<n;i++)
			scanf("%d",A+i);
		ll ans=msort(A,0,n-1);
		if (ans>=k)
		{
			printf("Case %d: %lld\n",ass,(ll)ans-k);
		}
		else
		{
			int f=0;
			printf("Case %d: ",ass);int last=A[0];
			if ((k-ans)%2==0)
			{
				printf("0\n");
				continue;
			}
			for (i=1;i<n;i++)
			{
				if (A[i]==last)
				{
					f=1;
					break;
				}
				else
					last=A[i];
			}
			if (f)
			{
				printf("0\n");
			}
			else
			{
				printf("1\n");
			}
		}
	}
	return 0;
}
