#include<iostream>
#include<vector>
#include<functional>
#include<numeric>
#include<list>
#include<algorithm>
using namespace std;

int main(){

	cout<<"enter length "<<endl;
	int n;
	cin>>n;
	vector <int> v;
	for(int i=0;i<n;i++){	
		int k;
		cin>>k;
		v.push_back(k);
	}
	list <int> l(v.begin(),v.end());
	for(int i=0;i<n;i++){
		cout<<"enter index to remove"<<endl;
		int k;
		cin>>k;
		v.erase(v.begin()+k);
		for(vector <int> :: iterator it=v.begin();it!=v.end();it++){
			cout<<*it<<" ";
		}
	}

	for(int i=0;i<n;i++){
		cout<<"enter value to remove"<<endl;
		int k;
		cin>>k;
		l.remove(k);
		for(list <int> :: iterator it=l.begin();it!=l.end();it++){
			cout<<*it<<" ";
		}
	}
} 
