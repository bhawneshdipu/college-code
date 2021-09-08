#include <bits/stdc++.h>
using namespace std;

int A[100005], tmp[100005];

long long mergex(int left, int mid, int right)
{
    int i=left, j=mid+1, k=left;
    long long countx = 0;

    while(i<=mid && j<=right)
    {
        if(A[i]<=A[j])
            tmp[k++] = A[i++];
        else
        {
            tmp[k++] = A[j++];

            countx+= mid-i+1;
        }
    }

    while(i<=mid)
        tmp[k++] = A[i++];

    while(j<=right)
        tmp[k++] = A[j++];

    for(k=left; k<=right; k++)
        A[k] = tmp[k];

    return countx;
}

long long sortx(int left, int right)
{
    int mid = (left+right)/2;

    long long countx = 0;

    if(left<right)
    {
        countx+= sortx(left, mid);
        countx+= sortx(mid+1, right);

        countx+= mergex(left, mid, right);
    }

    return countx;
}

int main() {

	int T;
	scanf("%d", &T);

	for(int j=1; j<=T; j++)
	{
	    printf("Case %d: ", j);

	    int N;
	    long long K;
	    scanf("%d %lld", &N, &K);

	    for(int i=0; i<N; i++)
	        scanf("%d", &A[i]);

	    long long inv = sortx(0, N-1);

	    int flag = 0;

	    for(int i=1; i<N; i++)
	        if(A[i]==A[i-1])
	        {
	            flag = 1;
	            break;

	        }

	    if(K<=inv)
	        printf("%lld\n", inv-K);

	    else
	    {
	        if(flag || (K-inv)%2==0)
	            printf("0\n");
	        else
	            printf("1\n");
	    }
	}

	return 0;
}
