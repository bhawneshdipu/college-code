#include<iostream>
#include<sstream>
#include<stack>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    stringstream tempstr(str);
    string s;
    stack <string> st;
    int c=0;
    for(int i=0;i<str.size();i++){
        if(str[i]==' ')
            c++;

    }
    c++;
    while(c--){
        tempstr>>s;
      //  cout<<s<<endl;
        st.push(s);
    }
    while(st.empty()==0){

        cout<<st.top()<<" ";
        st.pop();
    }
}
