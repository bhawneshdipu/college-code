#include<bits/stdc++.h>
using namespace std;
class CheckFunction{
 private:
    int arr[10]={6,2,5,5,4,5,6,3,7,6};
    public :
        int newFunction(string str){
            int ans=0;
            for(int i=0;i<str.size();i++){
                ans+=(arr[str[i]-'0']);
            }
            return ans;
        }
};
int  main(){
            string str;
            cin>>str;
            CheckFunction obj;
            cout<<obj.newFunction(str)<<endl;
            return 0;
}
