#include<bits/stdc++.h>
using namespace std;

int main(){
int tt;
cin>>tt;
while(tt--){
    int n;
    cin>>n;
    vector <int> v;
    for(int i=1;i<=n;i++){
        v.push_back(i);

    }
    int pos=1;
    while(v.size()>1){
        v.erase(v.begin()+pos);
        //cout<<"pos->"<<pos<<endl;
        pos+=1;
        pos%=(v.size());
       // cout<<"pos->"<<pos<<"     "<<v.size()<<endl;



    }
    cout<<v[0]<<endl;
}
}
