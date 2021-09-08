#include <bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main()
{
_
 	int tt;
 	cin>>tt;
 	while(tt--){
 		int n;
 		cin>>n;
 		vector <pair <int,int > > v;
 		for(int i=0;i<n;i++){
 			int a;
 			cin>>a;
 			v.push_back(make_pair(a,0));;

 		}

 		map <int,int> m1,m2;
 		for(int i=0;i<n;i++){
            int a;
            cin>>a;
            m1[i]=a;
            m2[a]=i;
 		}

 		for(int i=0;i<n;i++){
                v[i].second=m2[v[i].first];
            }
            for(int i=0;i<n;i++)
 			for(int j=0;j<n-1-i;j++){
 				if(v[j].second>v[j+1].second){
 				//cout<<v[j].first<<"  "<<v[j+1].first<<endl;
 					pair <int,int>  t=v[j];
 					v[j]=v[j+1];
 					v[j+1]=t;
 					ans++;
 				}
 			}

 		cout<<ans<<endl;

 	}
 return 0;
}
