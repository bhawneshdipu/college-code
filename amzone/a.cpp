#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;

    int arr[str.size()][str.size()];
    int arrn[str.size()];
    for(int i=0;i<str.size();i++){
        arrn[i]=str[i]-'0';

    }
    for(int i=0;i<str.size();i++){
            int sum=0;
        for(int j=i;j<str.size();j++){
            sum*=10;
            sum+=arrn[j];
            arr[i][j]=sum;
        }
    }


    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=arr[l-1][r-1];
        cout<<ans<<endl;
        if(ans%7==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }


}
