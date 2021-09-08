/* Integer Partition problem
1 = 1
2 = 1 + 1
3 = 2 + 1 = 1 + 1 + 1
4 = 3 + 1 = 2 + 2 = 2 + 1 + 1 = 1 + 1 + 1 + 1
5 = 4 + 1 = 3 + 2 = 3 + 1 + 1 = 2 + 2 + 1 = 2 + 1 + 1 + 1 = 1 + 1 + 1 + 1 + 1

*/

#include<bits/stdc++.h>
using namespace std;

#define test() int tt;cin>>tt;for(int test=1;test<=tt;test++)
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define gcd __gcd
#define  i64 int64_t
#define pb push_back
#define mp make_pair
#define _F first
#define _S second
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for(auto i=a;i<n;i++)
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)

#define dbg(x) cerr<<"debug: "<<x<<endl

typedef vector <int> vi;
typedef vector <string> vs;
typedef vector <vector <int> > vvi;
typedef map <string,int> msi;
typedef map <int,int> mii;
typedef pair <int,int> pii;
typedef pair <string,int> psi;


int  partition(vvi &table,int sum, int largestNumber){
    int i,j;

    /*initialize table with base cases*/
    for (i=0;i<=sum;i++)
        table[i][0]=0;
    for (i=1;i<=largestNumber;i++)
        table[0][i]=1;


    for (i=1;i<=sum;i++){
        for (j=1;j<=largestNumber;j++){
            if (i-j<0){
                table[i][j]=table[i][j-1];
                continue;
            }
            table[i][j]=table[i][j-1]+table[i-j][j];
        }
    }

    return table[sum][largestNumber];
}


int main(){
_
    test(){
        int sum;
        cin>>sum;
        int largestNumber = sum-1;
        vvi table(sum+1,vi(largestNumber+1,-1));


        printf("%d\n",partition(table,sum,largestNumber));
/*
        rep(i,0,sum+1){
            rep(j,0,largestNumber+1)
                cout<<table[i][j]<<" ";
                cout<<endl;
        }
*/

    }





return 0;
}
