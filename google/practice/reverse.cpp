#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("B-large-practice.in","r",stdin);//input file
    freopen("out.txt","w",stdout);//output file
    int tt;
    cin>>tt;//no. of test cases
    cin.ignore();/* to ignore the '\n' after we enter the number and press enter
    because we need to scan whole sentence and it stops scanning after '\n' so
    in 1st case it will not scan any thing just so to avoid that we use cin.ignore() to ignore '\n' ;*/
        for(int test=1;test<=tt;test++){
                cout<<"Case #"<<test<<": ";//to print the Case #1:
                string str;
                getline(cin,str);
                stringstream ss(str);//it is a buffer which is a string we just scan;
                string s;
                stack <string> st;//stack of string push() pop() and top() are functio of stack
                while(ss>>s){
                    st.push(s);//push to stack
                }
                while(!st.empty()){
                    if(st.size()==1){
                        cout<<st.top()<<endl;//if last word then just print word and endl;
                        st.pop();//pop from stack;
                    }else{
                        cout<<st.top()<<" ";//if not last word then print word and a space " ";
                        st.pop();//pop from stack;
                    }
                }
        }
}
