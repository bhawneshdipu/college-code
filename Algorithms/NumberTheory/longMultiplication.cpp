#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
void print(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    cout<<endl;
}
vector <int>  multiply(vector <int> a,vector <int> b,int base){
    int p=a.size();
    int q=b.size();
    vector <int> m(p+q,0);

    for(int i=p-1;i>=0;i--){
        int k=i+q;
        int carry=0;
        for(int j=q-1;j>=0;j--,k--){
                int pro=a[i]*b[j]+carry+m[k];
                carry=pro/base;
                m[k]=(pro%base);

        }
        m[k]+=carry;
    }
return m;
}
string multiply(string a,string b,int base){
    int p=a.size();
    int q=b.size();
    string m(p+q,'0');
    for(int i=p-1;i>=0;i--){
        int k=i+q;
        int carry=0;
        for(int j=q-1;j>=0;j--,k--){
                int pro=(a[i]-'0')*(b[j]-'0')+carry+(m[k]-'0');
                carry=pro/base;
                m[k]=(pro%base)+'0';
        }
        m[k]+=carry;
    }
    int k=0;
    while(m[k]=='0'){
        k++;
    }
    return(m.substr(k));
}

int main(){

        int tt;
        cin>>tt;
        while(tt--){
            string a,b;
            cin>>a>>b;
            cout<<"string multiply="<<multiply(a,b,10)<<endl;;
            vector <int> v1,v2;
            for(int i=0;i<a.size();i++){
                v1.push_back(a[i]-'0');
            }
            for(int i=0;i<b.size();i++){
                v2.push_back(b[i]-'0');
            }
            for(int i=0;i<a.size();i++){
                cout<<v1[i];
            }
            cout<<endl;
            for(int i=0;i<b.size();i++){
                cout<<v2[i];
            }
            cout<<endl;

            vector <int> v3(multiply(v1,v2,10));
            cout<<"vector multiply=";
            for(int i=0;i<v3.size();i++){
                cout<<v3[i];
            }
            cout<<endl;
        }

}
