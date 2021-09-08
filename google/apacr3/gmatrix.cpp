#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);
#define test() int tt;cin>>tt;for(int test=1;test<=tt;test++)
#define vi vector <int>
#define vis vector <pair <int ,vector <string> > >
#define pb push_back

int maxsum(vector <vector <int> > a,int k,int n)
 {
    int s[n][n-k+1];
    for(int i = 0;i<n;i++){
        s[i][0] = 0;
    for(int j = 0;j<k;j++)
    s[i][0]+=  a[i][j];
    }
    for(int i = 0;i<n;i++){
    for(int j = 1;j<n-k+1;j++){
    s[i][j] = s[i][j-1]-a[i][j-1]+a[i][j+k-1];
}
    }

    int s2[n-k+1][n-k+1]; int ma = INT_MIN;

    for(int j = 0;j<n-k+1;j++){
    s2[0][j] = 0;
    for(int l = 0;l<k;l++)
    s2[0][j]+= s[l][j];
    ma = max(ma,s2[0][j]);
    }

    for(int i = 1;i<n-k+1;i++)
    for(int j = 0;j<n-k+1;j++)
    {
        s2[i][j] = s2[i-1][j]-s[i-1][j]+s[i+k-1][j];
        ma = max(ma,s2[i][j]);
    }
    return ma;

}int main(){
_
   // freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    test(){
        cout<<"Case #"<<test<<": ";
        int n,k,c,x;
        cin>>n>>k>>c>>x;
         vector <int> a,b;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            a.pb(temp);
        }
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            b.pb(temp);
        }
        vector <vector <int> > v(n,vector <int> (n,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                v[i-1][j-1]=((a[i-1]*i)+(b[j-1]*j)+(c))%x;
            }
        }
        cout<<endl<<"---matrix---"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<maxsum(v,k,n)<<endl;
    }
}
