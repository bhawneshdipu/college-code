#include<iostream>
#include<map>
#include<vector>
#include<utility>
using namespace std;
int main(){
int n=10;
	map <int,string> mis;
	for(int i=0;i<n;i++){
		mis[i]="hello";
	}

	map  <int,string> :: iterator it1;

	for(it1=mis.begin();it1!=mis.end();it1++){
		cout<<it1->first<<"  "<<it1->second<<endl;
	}

    map <pair <int ,string>, pair<string,vector <int > >  > mssi;

    for(int i=0;i<3;i++){
            cout<<"enter num and string";
            string str;
            cin>>str;
            cout<<"hello enter vector of length 3\n";
            vector <int> v(3,12);
            mssi[make_pair(i,str)]=make_pair("hello",v);
    }
    map < pair < int ,string>,pair<string,vector <int >  > > :: iterator it;
    for(it=mssi.begin();it!=mssi.end();++it){
        cout<<it->first.first<<"   "<<it->first.second<<it->second.first<<"  ";
            vector <int > vt=it->second.second;
            for(vector <int> ::iterator i=vt.begin();i!=vt.end();++i){
                cout<<*i<<endl;
            }
    }

}
