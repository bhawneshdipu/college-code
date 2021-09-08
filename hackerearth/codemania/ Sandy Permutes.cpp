#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<memory.h>
#include<vector>
#include<set>
#include<list>
#include<sstream>
#include<map>
using namespace std;

int main()
{
int n,k;
cin>>n>>k;

vector <int> v,m;

for(int i=0;i<n;i++)
{
    int a;
    cin>>a;
    v.push_back(a);

}
m=v;
sort(v.begin(),v.end(),greater<int>());

int pos=0;
for(int i=0;i<n;i++)
{
    if(v[i]!=m[i])
    {
        vector <int> ::iterator x=find(m.begin()+i,m.end(),v[i]);

       // cout<<*x<<"mi="<<m[i]<<endl;

        swap(*x,m[i]);
        k--;



    }
    if(k==0)
    {

        break;

    }


}

if(m==v)
swap(m[n-1],m[n-2]);
for(int i=0;i<n;i++)
{
    cout<<m[i]<<" ";
}





return 0;
}
