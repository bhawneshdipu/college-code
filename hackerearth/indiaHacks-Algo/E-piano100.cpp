#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int BIT1[MAX],n;
int BIT2[MAX];
int flag1=0;
int flag2=0;
vector <int> A2(1,0),A1(1,0);
int query1(int x){
    int sum=0;
    while(x>0){
        sum+=BIT1[x];
        x-=(x&-x);
    }
    return sum;
}
int query1(int left,int right){
    return query1(right)-query1(left-1);
}
void update1(int idx,int val){
    while(idx<=n){
    BIT1[idx]+=val;
    idx+=(idx & -idx);
    }
}
void update1(int l, int r, int val) {
        update1(l, val);
        update1(r + 1, -val);
}

int query2(int x){
    int sum=0;
    while(x>0){
        sum+=BIT2[x];
        x-=(x&-x);
    }
    return sum;
}
int query2(int left,int right){
    return query2(right)-query2(left-1);
}
void update2(int idx,int val){
    while(idx<=n){
    BIT2[idx]+=val;
    idx+=(idx & -idx);
    }
}
void update2(int l, int r, int val) {
        update2(l, val);
        update2(r + 1, -val);
}

#define i64 long long int
i64 mod(i64 a,i64 b){
    i64 ret=a%b;
    if(ret<0)
        ret+=b;
    return ret;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        memset(BIT1,0,sizeof(int)*MAX);
        memset(BIT2,0,sizeof(int)*MAX);
        int m,z;
        cin>>n>>m>>z;
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            if(flag1==0){
                A1.push_back(-val);
                flag1=1;
                A2.push_back(val);
                flag2=0;
            }else {
                A1.push_back(val);
                flag1=0;
                A2.push_back(-val);
                flag2=1;
            }

        }
        for(int i=1;i<A1.size();i++){
            update1(i,A1[i]);
            update2(i,A2[i]);
        }
        int k=A1.size();
        for(int i=1;i<A1.size();i++){
            cout<<A1[i]<<" ";
        }

        for(int i=1;i<A2.size();i++){
            cout<<A2[i]<<" ";
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<i<<" "<<j<<" "<<query1(i,j)<<" "<<query2(i,j)<<endl;
            }
        }



        for(int i=n;i<=z;i++){
            int l=A1.size();
            i64 ak=0;
            if(flag1==0){
                ak=query1(l-1-n,l-1);
                cout<<"akq1->"<<ak<<endl;
            }else{
                ak=query2(l-1-n,l-1);
                cout<<"akq2->"<<ak<<endl;
            }
            cout<<"ak-->"<<ak<<endl;
            ak=mod(ak,m);
            cout<<"ak=="<<ak<<endl;
            if(flag1==0){
                A1.push_back(-ak);
                A2.push_back(ak);
                update1(k,-ak);
                update2(k,ak);
                k++;
                flag1=1;
                flag2=0;
            }else {
                A1.push_back(ak);
                A2.push_back(-ak);
                update1(k,ak);
                update2(k,-ak);
                flag1=0;
                flag2=1;
            }

        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                cout<<i<<" "<<j<<" "<<query1(i,j)<<" "<<query2(i,j)<<endl;
            }
        }



            cout<<abs(A1[A1.size()-1])<<endl;

        }

    }

}
