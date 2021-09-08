#include<bits/stdc++.h>
using namespace std;
int main(){
string str="hello i am code";
string str1="hello-i-am-code";
string str2="hello.i.am.code";
stringstream s1(str);
string t;
while(s1){
    s1>>t;
    cout<<t<<endl;
}
stringstream s(str1);
while(s){
    s>>t;
    cout<<t<<endl;
}
stringstream s2(str2);
while(s2){
    s2>>t;
    cout<<t<<endl;
}
}
