#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
template <class V>
struct sort_by_val {
  bool operator()(V const& l, V const& r) {
        return 	l<r;
  }
};
template <class V>
struct sort_by_val_pair {
  bool operator()(V const& l, V const& r) {
        return 	l.second<r.second;
  }
};


int main(){
	map <string,int> msi;
	for(int i=0;i<3;i++){
		cout<<" string and integer"<<endl;
		string str;int n;
		cin>>str>>n;
		msi[str]=n;
	}
	
	
	vector <pair <string,int> >vsi(msi.begin(),msi.end());
	//copy(msi.begin(),msi.end(),back_inserter(vsi));  //ok
	
	vector <pair <string,int> > ::iterator it; 
	for(it=vsi.begin();it!=vsi.end();it++){
		cout<<it->first<<"   "<<it->second<<endl;
	}
	sort(vsi.begin(),vsi.end(),sort_by_val_pair<pair <string,int> >());
	
	for(it=vsi.begin();it!=vsi.end();it++){
		cout<<it->first<<"   "<<it->second<<endl;
	
	}	
	
	
	
	
}