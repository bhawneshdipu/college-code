#include<iostream>
#include<map>
#include<vector>
#include<cmath>
using namespace std;

int findDist(int n,pair <int,int> &p1,pair <int,int> &p2 ){
        int dist=0;

        dist=abs(p1.first-p2.first)+(abs(p1.second-p2.second));
return dist;
}
int main(){
    int tt;
    scanf("%d",&tt);
    while(tt--){
        int n;
        scanf("%d",&n);
        map <int,pair<int,int> > m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int a;
                scanf("%d",&a);
                m[a]=make_pair(i,j);
            }
        }
        long long int ans=0;
        for(int i=1;i<n*n;i++){
            int a;
            a=(findDist(i,m[i],m[i+1]));
            //cout<<a<<endl;
            ans+=a;
        }
        cout<<ans<<endl;


    }


}
