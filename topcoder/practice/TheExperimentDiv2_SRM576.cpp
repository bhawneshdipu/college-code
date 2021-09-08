#include<bits/stdc++.h>
using namespace std;
class TheExperimentDiv2{
public:
        vector <int> determineHumidity(vector <int> v1,int l,vector <int> v2){
        vector <bool> flag(v1.size(),true);
        vector <int> ans(v2.size(),0);
        for(int i=0;i<v2.size();i++){
            int an=0;
            for(int j=v2[i];j-v2[i]<l;j++){
                if(flag[j]){
                    an+=(v1[j]);
                    flag[j]=0;

                }else{
                	break;
                	}


            }
            ans[i]=an;

        }
        return ans;


        }
};
