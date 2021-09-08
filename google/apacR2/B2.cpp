#include<bits/stdc++.h>
using namespace std;
int main(){

freopen("B-large.in","r",stdin);
//freopen("B-large.out","w",stdout);

	int tt;
	cin>>tt;
	for(int test=1;test<=tt;test++){
			cout<<"Case #"<<test<<": \n";
			int p,t,e;
			cin>>p>>e>>t;
			vector <long long int> np,nt,ne;
			for(int i=0;i<p;i++){
				long long int a;
				cin>>a;
				np.push_back(a);
			}

			for(int i=0;i<e;i++){
				long long int a;
				cin>>a;
				ne.push_back(a);
			}
			for(int i=0;i<t;i++){
				long long int a;
				cin>>a;
				nt.push_back(a);
			}


set <pair<long long int,long long int> > s;
long long int tp,tt,te1,te2;
		for(int i=0;i<p;i++){
			for(int j=0;j<t;j++){
				for(int k1=0;k1<e;k1++){
					for(int k2=0;k2<e;k2++){
						if(k1!=k2){
							tp=np[i];
							te1=ne[k1];
							te2=ne[k2];
							tt=nt[j];
					//	cout<<tp<<"*"<<te1<<"   "<<te2<<"*"<<tt<<endl;
					//	cout<<i<<"  "<<k1<<"  "<<k2<<"  "<<j<<endl;
						long long int P=tp*te1;
						long long int Q=tt*te2;
						long long int L=(int)sqrt(100000000);
					//	cout<<"P--->"<<P<<" Q-->"<<Q<<endl;
					//	cout<<"p--> "<<p<<" q-->"<<q<<endl;
                    s.insert(make_pair(P,Q));
						for(int x=2;x<Q && P>x && x<=L;x++){
							while(P%x==0 && Q%x==0){

								P/=x;
								Q/=x;

								//cout<<"P-in-->"<<P<<" Q-in--->"<<Q<<endl;
							//	cout<<"p--> "<<p<<" q-->"<<q<<endl;
							s.insert(make_pair(P,Q));

							}

						}
						}

					}
				}
			}
		}









		int m;
		cin>>m;
		while(m--){
		int flag=0;
			long long int pp,qq;
			cin>>pp>>qq;

            auto it=s.find(make_pair(pp,qq));
            if(it!=s.end())
                    flag=1;

		if(flag==1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}

	}



}
