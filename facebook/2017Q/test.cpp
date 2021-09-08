#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){

        double p=100,x,y;
        cin>>x>>y;

        double angle= atan2(y-50,x-50)*180.0/PI;
        cout<<"angle->"<<angle<<endl;
        if(angle>=0){
                angle=360.0-angle;
                angle=fmod(angle,360.0);


        }else{
                angle=abs(angle);
        }

        cout<<"clock_wise->"<<angle<<endl;

        angle+=90;
        angle=fmod(angle,360.0);
        cout<<"clock_wise__y->"<<angle<<endl;


    }

}
