#include<bits/stdc++.h>
using namespace std;
int find_len(vector<int> v,int j){
    int ans=0;
    for(int i=2;i<=50;i++){
        if((v[j]*i)>=50)
            return i;
    }
    return -1;
}
void print(vector<int> v){
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int main(){
    //freopen("lazy_load.txt","r",stdin);
    //freopen("laxyyy.txt","w",stdout);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){
        int n;
        cin>>n;
        //cout<<"n--->"<<n<<endl;
        vector <int> v;
        int ans=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;

            if(a>=50)
                ans++;
            else
                v.push_back(a);
        }
        vector <int> check(v.size(),0);
        int chk=0;
        sort(v.begin(),v.end());
        int j=v.size()-1;
        int i=0;
        while(chk<=v.size() and v.size()>0){
                if(check[i]==0 and check[j]==0 and (i!=j)){
                    int k=find_len(v,j);
                    //cout<<"k->"<<k<<"i->"<<i<<"j->"<<j<<"ans->"<<ans<<endl;
                    if(k!=-1){
                        chk+=k;
                        int pre_i=i;
                        for(;i<pre_i+k-1 and (i<v.size());i++)
                            check[i]=1;
                        check[j]=1;
                            j--;
                        ans++;
                    //cout<<"k->"<<k<<"i->"<<i<<"j->"<<j<<"ans->"<<ans<<endl;
                    //print(check);
                    }else{
                       // cout<<"break1"<<endl;
                        break;
                    }
                }else{
                    //cout<<"break2"<<endl;
                    break;
                }
        }
        cout<<"Case #"<<test<<": "<<ans<<endl;



    }

}
