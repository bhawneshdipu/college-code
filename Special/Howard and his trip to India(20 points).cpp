#include<bits/stdc++.h>
using namespace std;

#define rep(it,container) for(auto it=container.begin();it!=container.end();it++)
#define rev(it,container) for(auto it=container.rbegin();it!=container.rend();it++)


int main(){
std::cout.sync_with_stdio(false);
std::cin.sync_with_stdio(false);

int tt;
cin>>tt;
while(tt--){
        int n;
        cin>>n;
        priority_queue <int,vector <int> , less <int>  > J,C;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            J.push(a);

        }
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            C.push(a);

        }
        int ans=0;
        for(int i=0;J.size()>0;i++){

            if(J.top()<=C.top()) // cup and jamoon pair  is selected
            {
                ans++;
                J.pop();C.pop();
            }else if(J.top()>C.top()){ // jamoon can't be fit in the max capacity cup available so jamoon Discareded.
                J.pop();
            }
        }
        cout<<ans<<endl;

}
}
