#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("in2.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){
        cout<<"Case #"<<test<<": ";
            int n;
            cin>>n;
            string str[2];
            cin>>str[0];
            cin>>str[1];
           // cout<<str[0]<<endl<<str[1]<<endl;
            int ans=0;
            for(int i=0;i<2;i++){
                for(int j=0;j<n;j++){
                        if(i==0)
                        if(str[i][j]=='.' and str[i+1][j]=='.' and str[i+1][j+1]=='.' and str[i][j+1]=='.'){
                                ans++;
                                str[i][j]='G';
                                int k=j;
                                while(k<n and str[i][k]=='.'){
                                    str[i][k++]='*';
                                }
                                str[i+1][j]='*';

                            }else if(str[i][j]=='.' and str[i+1][j]=='.' and str[i][j+1]=='.' and str[i+1][j+1]=='X'){
                                ans++;
                                str[i][j]='G';
                                int k=j;
                                while(k<n and str[i][k]=='.'){
                                    str[i][k++]='*';
                                }
                                str[i+1][j]='*';
                            }else if(str[i][j]=='.' and str[i+1][j]=='X' and str[i][j+1]=='.' and str[i+1][j+1]=='X'){
                                ans++;
                                str[i][j]='G';
                                int k=j;
                                while(k<n and str[i][k]=='.'){
                                    str[i][k++]='*';
                                }


                            }else if(str[i][j]=='.' and str[i+1][j]=='.' and str[i][j+1]=='X' and str[i+1][j+1]=='X'){
                                ans++;
                                str[i][j]='G';
                                str[i+1][j]='*';

                            }else if(str[i][j]=='.' and str[i+1][j]=='X' and str[i][j+1]=='X' and str[i+1][j+1]=='X'){
                                ans++;
                                str[i][j]='G';

                            }else if(str[i][j]=='.' and str[i+1][j]=='.' and str[i][j+1]=='X' and str[i][j-1]=='X'){
                                ans++;
                                str[i+1][j]='G';
                                int k=j;
                                while(k<n and str[i+1][k]=='.'){
                                    str[i+1][k++]='*';
                                }
                                k=j;
                                while(k>=0 and (str[i+1][k]=='.' || str[i+1][k]=='*')){
                                    str[i+1][k--]='*';
                                }
                                str[i][j]='*';
                            }
                        }

                    }
                    cout<<ans<<endl;
                }
            }


