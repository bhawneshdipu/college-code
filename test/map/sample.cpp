#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;
int main(){
    int n;
    cout<<"enter number of nodes"<<endl;
    cin>>n;
    vector <int > v;
    for(auto i=0,x=0;(i<n)&&(cin>>x);i++,v.push_back(x),cout<<"x"<<endl);

    for(int i=0;(i<n)&&(cout<<v[i]<<" ");i++);


}

