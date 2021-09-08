#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tt;
	cin>>tt;
	while(tt--){
			int m,n;
			cin>>m>>n;
			int larr[50007];
			int rarr[50007];
			for(int i=0;i<m;i++){
				cin>>larr[i];
			}
			larr[m]=INFINITY;
			for(int j=0;j<n;j++){
				cin>>rarr[j];

			}
			rarr[n]=INFINITY;
			int arr[100050];
			memset(arr,0,sizeof(arr));
			int l=0,r=0;
			for(int k=0;k<m+n;k++){
					if(larr[l]<=rarr[r])
						arr[k]=larr[l++];
					else
						arr[k]=rarr[r++];
			}
			for(int i=0;i<m+n;i++){
					cout<<arr[i]<<" ";

			}
			cout<<endl;

	}
    return 0;
}
