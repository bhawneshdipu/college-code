// IPG_2013117

#include "bits/stdc++.h"
#define MOD             1000000007
#define MAX             (int)1e9
#define MIN             (int)-1e9
#define PI              (acos(-1.0))
#define linf            (1LL<<62)
#define inf             (0x7f7f7f7f)
#define EPS             1e-9

using namespace std;
typedef double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

#define pb                       push_back
#define fi                       first
#define se                       second
#define tracearr(a,n)            for(int i=0;i<n;i++)  cout<<a[i]<<" ";
#define tracemat(a,n,m)          for(int i=1;i<=n;i++) { for(int j=1;j<=m;j++)  cout<<a[i][j]<<" "; cout<<endl; }
#define tracepair(a,n)           for(int i=0;i<n;i++)  cout<<a[i].first<<" "<<a[i].second<<endl;
#define all(v)                   v.begin(),v.end()
#define uniq(v)                  sort(all(v));  v.erase(unique(all(v)),v.end())
#define foreach(c,itr)           for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mp(v,a,b)                v.push_back(make_pair(a,b))
#define FOR(i,n,m)               for(int i=0;i<n;i+=m)
#define For(i,n,m)               for(int i=1;i<=n;i+=m)
#define countbits(value)         __builtin_popcount(value)
#define countbitsll(value)       __builtin_popcountll(value)
#define trailing0bits(value)     __builtin_parity(value)
#define leading0bits(value)      __builtin_clz(value)
#define max(a,b)                 (a>=b?a:b)
#define min(a,b)                 (a<b?a:b)
#define s(a)                     scanf("%d",&a)
#define p(a)                     printf("%d",a)
#define pln()                    printf("\n")
#define clr(x)                   memset(x,0,sizeof(x))
#define uj()                     int t; scanf("%d",&t); while(t--)

#ifndef ONLINE_JUDGE
	#define endl endl
	#define TRACE
#else
	#define endl '\n'
#endif

#ifdef TRACE
    #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
    #define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
    #define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
    #define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
#else
    #define trace(x)
    #define trace1(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
    #define trace4(a,b,c,d)
    #define trace5(a,b,c,d,e)
    #define trace6(a,b,c,d,e,f)
#endif

template<typename T> T gcd(T a, T b) {if(!b) return a;return gcd(b, a % b);}
template<typename T> T lcm(T a, T b) {return a * b / gcd(a, b);}
int a[1000002];
int solve(int s,int e,int p){
    if(s==e){
        return a[s]*p;
    }
    else{
        return max(solve(s+1,e,p+1) + a[s]*p,solve(s,e-1,p+1)+a[e]*p);
    }
}
int sum[100002];
int dp[2002][2002];
//Main
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","r",stdout);
  //ios_base::sync_with_stdio(false);
      int n;
      cin>>n;
      For(i,n,1){
          cin>>a[i];
      }
      For(i,n,1){
      	sum[i]=sum[i-1]+a[i];
      }
      //tracearr(a,n+1); pln();
      For(i,n,1){
          dp[i][i]=a[i];
      }
      for(int d=1;d<n;d++){
          for(int i=1;i<=n-d;i++){
              int j=i+d;

              //cout<<sum<<endl;
              dp[i][j]=max(dp[i+1][j]+sum[j]-sum[i-1],dp[i][j-1]+sum[j]-sum[i-1]);
          }
      }
      //tracemat(dp,n,n); pln();
      cout<<dp[1][n]<<endl;
      //cout<<solve(0,n-1,1);
return 0;
}

