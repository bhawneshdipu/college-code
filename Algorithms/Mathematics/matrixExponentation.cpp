#include<bits/stdc++.h>
using namespace std;
vector <vector <int> >  multi(vector <vector <int> > a,vector <vector <int> > b){
    vector <vector <int> > c(a.size(),vector <int>(b[0].size()));

        for(int i=0;i<a.size();i++){
            for(int j=0;j<b[0].size();j++){
              for(int k=0;k<b.size();k++){
                c[i][j]+=(a[i][k]*b[k][j]);
              }
            }
        }
        return c;
}
vector <vector <int> > matrix_power(vector <vector <int> >x,int n){
        if(n==1)
            return x;
        if(n%2==0)
            return matrix_power(multi(x,x),n/2);
        else
            return multi(x,matrix_power(multi(x,x),n/2));
}
int main(){
    vector <vector <int> > a,b,c;
    for(int i=0;i<3;i++){
        vector <int> t;
        for(int j=0;j<3;j++)
            t.push_back(3);
        a.push_back(t);
    }


    c=matrix_power(a,2);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }

}
