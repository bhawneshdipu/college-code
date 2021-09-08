#include<bits/stdc++.h>
using namespace std;
#define ll long long int
double findDist(pair <int,int> p1,pair <int,int> p2){

        double dis=pow(abs(p2.first-p1.first),2)+pow(abs(p2.second-p1.second),2);
        dis=sqrt(dis);

        return dis;

}
int main(){
    //freopen("in1.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){
        cout<<"Case #"<<test<<": ";
        int n;
        cin>>n;
        vector <pair<int,int> > v;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j and j!=k and k!=i )
                    if(findDist(v[i],v[k])==findDist(v[k],v[j])){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
