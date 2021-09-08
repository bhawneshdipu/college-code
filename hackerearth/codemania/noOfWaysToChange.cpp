
#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
#define pb push_back
#define all(v) (v).begin(),(v).end()


int count(vector <int> &S, int n, int c )
{
    vector <int> table(c+1,0);
    table[0] = 1;

    for(int i=0; i<n; i++)
        for(int j=S[i]; j<=c; j++)
            table[j] += table[j-S[i]];

    return table[n];
}

int main(){
_
    int c,n;
    cin>>n>>c;
    vector <int> v;
    for(int i=0;i<c;i++){
        int a;
        cin>>a;
        v.pb(a);
    }
    cout<<count(v,c,n)<<endl;
return 0;
}
