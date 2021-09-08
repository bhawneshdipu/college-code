/* closest pair of three points problem */


#include<bits/stdc++.h>
using namespace std;

#define MAX 1007
struct cmpx{
    bool operator ()(pair <double,double>p1,pair <double,double> p2){
        return p1.first<p2.first;
    }
};
struct cmpy{
    bool operator ()(pair <double,double> p1,pair <double,double> p2){
        return p1.second<p2.second;
    }
};

double distance(pair <double,double> p1,pair <double,double> p2){
        //cout<<p1.first<<" "<<p1.second<<"   "<<p2.first<<" "<<p2.second<<endl;
        double res=((pow(abs(p1.first-p2.first)*1LL,2))+pow(abs(p1.second-p2.second)*1LL,2));
        res*=1LL;

return sqrt(res);
}

double distance(pair <double,double> p1,pair <double,double> p2,pair <double,double>p3){

    double res=(distance(p1,p2)+distance(p2,p3)+distance(p1,p3));
    //cout<<"res->"<<res<<fixed<<setprecision(10)<<endl;
return res;
}
double closest(pair <double,double> arr[],int l,int r){
//cout<<l<<" "<<r<<" "<<r-l<<endl;

    if(r-l<6){

        sort(arr+l,arr+r,cmpx());
            double mn=INFINITY;
        for (int i=l;i<r;++i)
        for (int j=i+1;j<r;++j)
                for(int k=j+1;k<r;++k)
                        mn = min(mn, distance(arr[i],arr[j],arr[k]));


        return mn;
    }
    sort(arr+l,arr+r,cmpx());
    int mid=(l+r)/2;
    double d1=closest(arr,l,mid);
    double d2=closest(arr,mid+1,r);
    double dis=min(d1,d2);


    return dis;
    }


int main(){

    int n;
    cin>>n;
    pair <double,double> arr[MAX];
    memset(arr,0,sizeof(pair <double,double>)*MAX);
    for(int i=0;i<n;i++){A
        double x,y;
        cin>>x>>y;
        arr[i].first=x;
        arr[i].second=y;
    }
    int l=0,r=n;
    double dis=closest(arr,l,r);
    cout<<"Closest Dist:"<<dis<<endl;
return 0;
}
