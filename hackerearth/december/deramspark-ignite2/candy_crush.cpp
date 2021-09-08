#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tt;
	cin>>tt;
	for(int t=1;t<=tt;t++){
        cout<<"Case #"<<t<<": ";
		int n;
			cin>>n;
			int arr[n+7];
			memset(arr,0,sizeof(arr));
			for(int i=0;i<n;i++){
				cin>>arr[i];
			}
			int ans=0;
			for(int x:arr){
				ans^=x;
			}
			if(ans!=0){
				cout<<"NO"<<endl;
			}else{
				cout<<accumulate(arr,arr+n,0)-*min_element(arr,arr+n);
			}

	}

    return 0;
}
