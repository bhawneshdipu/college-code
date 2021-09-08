#include<iostream>
#include<sstream>
#include<stack>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int count=0;
    for(int i=0;i<str.size();i++)
        if(str[i]==' ')
            count++;
            count++;
    stringstream tempstr(str);
    stack <string> s;
    while(count--){
    tempstr>>str;
    s.push(str);
    }
    while(s.empty()==0){

        cout<<s.top()<<"  ";
        s.pop();
    }
}
