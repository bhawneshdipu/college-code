#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin>>tt;
    cin.get();
    while(tt--){
        string str;
        getline(cin,str);
        stringstream s(str);
        set <int64_t> st;
        int64_t temp;
        while(s>>temp){

            st.insert(temp);
        }
        int64_t x;
        cin>>x;
        int64_t y=0,n=0;
        bool flag=0;
        for(int i=1;i<1000;i++){
            int64_t a=i*x;
            set <int64_t> ss;
            while(a){
            	int64_t tem=a%10;
            	if(st.find(tem)!=st.end()){
                ss.insert(tem);
                a/=10;
            	}
            	else {
            		flag=1;

            		break;
                }
            }
            if(ss.size()==st.size()){
                y=i*x;
                n=i;
            break;
            }
            }


        if(y!=0)
        cout<<y<<" ="<<" "<<x<<" "<<"*"<<" "<<n<<endl;
        else{
            cout<<"Impossible"<<endl;
        }
    }

}
