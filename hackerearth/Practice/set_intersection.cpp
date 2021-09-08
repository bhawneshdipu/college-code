#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int tt;cin>>tt;cin.get();for(int test=1;test<=tt;test++)
int main(){
_
	test(){

		string str1,str2;
		cin>>str1>>str2;
		stringstream s1(str1);
		stringstream s2(str2);
		set  <char> v1;
		set   <char> v2;
		set <char> v3;
		char ch;
		while(s1>>ch){
			v1.insert(ch);
			v3.insert(ch);
            //cout<<ch<<endl;
		}while(s2>>ch){
			v2.insert(ch);
			v3.insert(ch);
          //  cout<<ch<<endl;
		}
		int l1=v1.size();
		int l2=v2.size();
		int l3=v3.size();
		if(l3==(l1+l2)){
            cout<<"No"<<endl;
		}else{
            cout<<"Yes"<<endl;
		}

	}


return 0;
}
