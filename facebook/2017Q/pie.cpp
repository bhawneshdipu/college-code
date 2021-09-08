#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
int main(){
   // freopen("in_pie.txt","r",stdin);
    //freopen("out_pie.txt","w",stdout);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){

        double p,x,y;
        cin>>p>>x>>y;
        double angle= atan2(y-50,x-50)*180.0/PI;
        if(angle>0){
                angle=360.0-angle;
                angle=fmod(angle,360.0);
        }else{
                angle=abs(angle);
        }
        if(angle!=0){
            angle+=90;
            angle=fmod(angle,360.0);
        }
        p=((p)*360.0)/100.0;//from degree to percentage
        double distance=sqrt(pow(abs(50-x),2)+pow(abs(50-y),2));
        //cout<<"dis->"<<distance<<"angle->"<<angle<<"p->"<<p<<endl;
        cout<<"Case #"<<test<<": ";
        if(angle==360)
            angle=0;
        if(p==0)
            cout<<"white"<<endl;
        else if(angle<=p and distance<=50.0){
            cout<<"black"<<endl;
        }else{
            cout<<"white"<<endl;
        }

    }

}
