#include<bitset>
#include<iostream>
#include<vector>
using namespace std;
int main(){
	string str="ABC abc 0123 ";
	for(int i=0;i<str.size();i++){
		cout<<str[i]<<" : "<<bitset<8>(str[i])<<endl;
	}

	bitset <8> b('A');
	cout<<"bitset of 1 :"<<bitset <8> (1)<<endl;
	cout<<"bitset of -1 :"<<bitset <8> (-1)<<endl;
	cout<<"bitset of 1.25 :"<<bitset <8> (1.25)<<endl;
	cout<<"bitset of 'A' :"<<b<<endl;
	cout<<"size of bitset :"<<b.size()<<endl;
	cout<<"count of set bits:"<<b.count()<<endl;
	cout<<"after fliping bits:"<<b.flip()<<endl;
	cout<<"set bit LSB:"<<b.set(0)<<endl;
}
