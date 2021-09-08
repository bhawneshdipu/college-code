#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int editDistance(string str1,string str2){
        int l1=str1.size();
        int l2=str2.size();

        vector <vector <int> >  sol(l1+1,vector <int> (l2+1,0));


        for(int i=0;i<=l2;i++)
            sol[0][i]=i;
        for(int i=0;i<=l1;i++)
            sol[i][0]=i;

        for(int i=1;i<=l1;i++)
        {

            for(int j=1;j<=l2;j++)
            {

                if(str1[i-1]==str2[j-1])
                sol[i][j]=sol[i-1][j-1];
                else if(str1[i-1]!=str2[j-1])
                {

                    sol[i][j]=min(min(sol[i-1][j-1]+1,sol[i][j-1]+1),sol[i-1][j]+1);
                }
            }
        }
        /*
        for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++)
            cout<<sol[i][j]<<" ";

            cout<<endl;
        }*/
        return sol[l1][l2];
}


int main(){
_
    int tt;
    cin>>tt;
    cin.ignore();
    while(tt--)
    {
        string str1,str2;
        cin>>str1>>str2;
        int l1=str1.size();
        int l2=str2.size();
        int ans=l1;
        string a=str1,b=str2;
        int sl=l2,ll=l1;
        if(l1>l2){
            a=str1;
            b=str2;
            sl=l2;
            ll=l1;
        }else{
            a=str2;
            b=str1;
            sl=l1;
            ll=l2;
        }

        for(int i=0;i<=ll-sl;i++)
        ans=min(editDistance(a.substr(i,sl),b),ans);
        cout<<ans<<endl;
    }
    return 0;
}
