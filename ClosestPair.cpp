/* closest pair problem */


#include<bits/stdc++.h>
using namespace std;

#define MAX 10007
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

        double res=((pow(abs(p1.first-p2.first),2))+pow(abs(p1.second-p2.second),2));
return sqrt(res*1LL);
}
double closestPair(pair <double,double> arr[],int l,int r){

    if(r-l<=3){
        double mn=INFINITY;
        for(int i=l;i<r;i++){
            for(int j=i+1;j<r;j++){
                mn=min(mn,distance(arr[i],arr[j]));
            }
        }
        return mn;
    }

    sort(arr+l,arr+r,cmpx());
    int mid=(l+r)/2;
    double d1=closestPair(arr,l,mid);
    double d2=closestPair(arr,mid+1,r);
    double dis=min(d1,d2);
    pair <double,double> temp[MAX],p;
    memset(temp,0,sizeof(pair <double,double>)*MAX);
    p=arr[mid];
    int k=0;
    for(int i=0;i<r;i++){
        if(arr[i].first<(p.first-dis) || arr[i].first>(p.first+dis)){
            continue;
        }
        temp[k++]=arr[i];
    }
    sort(temp,temp+k,cmpy());
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            dis=min(dis,distance(temp[i],temp[j]));
        }
    }
return dis;
}
int main(){

    int n;
    cin>>n;
    pair <double,double> arr[MAX];
    memset(arr,0,sizeof(pair <double,double>)*MAX);
    for(int i=0;i<n;i++){
        double x,y;
        cin>>x>>y;
        arr[i].first=x;
        arr[i].second=y;
    }
    int l=0,r=n;
    double dis=closestPair(arr,l,r);
    cout<<"Closest Dist:"<<dis<<endl;
return 0;
}
