#include<bitset>
#include<iostream>
#include<functional>
#include<utility>
using namespace std;
int main(){
	bitset <8> b1(2);
	cout<<b1<<endl;
	b1=b1<<5;
	cout<<b1<<endl;
	b1=b1>>5;
	cout<<b1<<endl;
	bitset <8> b2(7);
	cout<<b2<<endl;
	b1=b1^b2;
	cout<<b1<<endl;
	b1=b1&b2;
	cout<<b1<<endl;
	b1=b2|b2;
	cout<<b1<<endl;
}
