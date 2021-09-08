#include<iostream>
#include<vector>
#include<list>
using namespace std;

list <int> a;
list <int> m;
list <int> e;
list <int> b;
list <int> ::iterator it;

int point=0;
void binary(float f){
	int n=(int)f;
	while(n>0){
		int k=n%2;
		a.push_front(k);
		n/=2;
		point++;
	}
	
	float xyz=f-(int)f;
	//cout<<xyz<<"xyz"<<endl;
	while(xyz<1 && xyz>0 && (b.size()+a.size())<23){
		//cout<<xyz*2<<"   "<<endl;
		if(xyz*2>=1){
			b.push_back(1);
			xyz=xyz*2-1;
		}
		else{ 
			b.push_back(0);
			xyz=xyz*2;
		}
		

	}

}



void binary(int n){
	while(n>0){
		int k=n%2;
		e.push_front(k);
		n/=2;
	}

}

void solve(){
it=a.begin();
int p=0;
if(a.size()>0){	
while(a.size()>0){
	if(*it==1){
		it++;	
		break;	
	}else
		it++;

}


 p=0;
	while(it!=a.end()){
		p++;
		cout<<"m-->"<<endl;
		m.push_back(*it);
		it++;
	}
	it=b.begin();
	while(it!=b.end()){
		m.push_back(*it);
		it++;
	}
	
}
else{
it=b.begin();
if(b.size()>0){	
while(b.size()>0){
	if(*it==1){
		it++;	
		break;	
	}
	it++;

}

 p=0;
while(it!=b.end())
	p++;
	it++;
}

}

int num=p+127;
cout<<"num-->"<<num<<endl;
while(num){
	e.push_front(num%2);
	num/=2;

}
}

int main(){
	float f;
	cout<<"enter float"<<endl;
	cin>>f;
	binary(f);
	solve();
	 it=a.begin();
	cout<<"a"<<endl;
	for(;it!=a.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"b"<<endl;
	it=b.begin();

	
	for(;it!=b.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"e"<<endl;	
	it=e.begin();

	
	for(;it!=e.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;

	it=m.begin();
	cout<<"m"<<endl;
	for(;it!=m.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;



}