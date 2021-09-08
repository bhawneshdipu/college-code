#include<bits/stdc++.h>
using namespace std;
string hex(char ch){
    stringstream ans;
    ans<<hex<<(int)ch;
    string a;
    ans>>a;
    return a;
}
char tochar(string str){
    //cout<<"---------"<<str<<endl;
    int ans=0;;
    for(int i=0;i<str.size();i++){
            if(str[i]>='A' and str[i]<='Z')
                ans+=(pow(16,str.size()-i-1))*((str[i]-'A')+10);
            else{
                ans+=(pow(16,str.size()-i-1))*(str[i]-'0');
            }
    }
    //cout<<">"<<ans<<endl;
    char ch=ans;
    //cout<<"->"<<ch<<endl;
    return ch;
}
int main(){
    char ch;
    cin>>ch;
    cin.ignore();
    if(ch=='E'){
        string str;
        getline(cin,str);
        string num;
        cin>>num;
        //cout<<str<<" "<<num<<endl;
        string ans;
        ans+=to_string((int)num.size());

        ans+='-';
        ans+=num;
        for(int i=0;i<str.size();i++){
            ans+='-';
            string tt=hex(str[i]);
            reverse(tt.begin(),tt.end());
            ans+=tt;

        }
        //cout<<ans<<endl;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>='a' and ans[i]<='z'){
                ans[i]=toupper(ans[i]);
            }
        }
        cout<<ans<<endl;

    }else{
        string str;
        getline(cin,str);
      //  cout<<str<<endl;
        string num,ans;
        int flag=0;
        for(int i=0;i<str.size();){
            if(flag==0 and str[i]=='-'){
                    flag=1;
                while(str[++i]!='-'){
                    num+=str[i];
                }
                //cout<<"-->"<<num<<endl;
            }else if(flag==0)
                i++;
            if(str[i]=='-' and flag){
                string tt;
                while(flag==1 and str[++i]!='-' and i<str.size()){
                    tt+=str[i];
                }
                reverse(tt.begin(),tt.end());
                //cout<<"---->"<<tt<<endl;
                ans+=tochar(tt);


            }

        }
        cout<<num<<endl<<ans<<endl;
    }

}
