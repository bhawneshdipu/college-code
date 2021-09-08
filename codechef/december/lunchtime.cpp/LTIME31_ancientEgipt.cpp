#include<bits/stdc++.h>
using namespace std;

void _union(int *Arr, int N, int A, int B)
{
    int TEMP = Arr[ A ];
    for(int i = 1; i <= N;i++)
    {
    if(Arr[ i ] == TEMP)
    Arr[ i ] = Arr[ B ];
    }
}
void build(int *arr,int n,set <pair<int,int> > ss){
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    //cout<<"build"<<endl;
    //cout<<ss.size()<<endl;
    for(auto  it=ss.begin();it!=ss.end();it++){
        int a=it->first;
        int b=it->second;
      //  cout<<a<<"hello"<<b<<endl;
        _union(arr,n,a,b);
    }
}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    int arrn[500000+7];
    int arrc[500000+7];
    arrn[0]=0;
    arrc[0]=0;

    for(int i=1;i<=n;i++){
        arrn[i]=0;
        cin>>arrn[i];
        arrc[i]=i;
    }
    set <pair <int,int> >st;
    vector <pair <int,int> > v(500000+7);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        _union(arrc,n,a,b);
        v[i]=make_pair(a,b);
        st.insert(make_pair(a,b));
    }
    for(int i=0;i<q;i++){
        char ch;
        cin>>ch;
        if(ch=='P'){
            int x,y;
            cin>>x>>y;
            arrn[x]=y;
        //    cout<<"P "<<x<<" "<<y<<endl;

        }else{
            int x;
            cin>>x;
          //  cout<<"size of set"<<st.size();
            st.erase(v[x]);
            //cout<<"size of set"<<st.size();
            build(arrc,n,st);
            //cout<<"remove"<<x<<endl;
        }
        int64_t ans[500000+7];
        //cout<<"array"<<endl;
        for(int i=1;i<=n;i++){
            ans[i]=0;
          //  cout<<arrn[i]<<' ';
        }
        //cout<<endl<<"root"<<endl;;
        for(int i=1;i<=n;i++){
          //  cout<<arrc[i]<<' ';
        }
        //cout<<endl<<"population of each region"<<endl;;

        for(int i=1;i<=n;i++){
            {
                ans[arrc[i]]+=(arrn[i]);
            }
        }

         for(int i=1;i<=n;i++){
          //  cout<<ans[i]<<' ';
        }
        //cout<<endl;

        for(int i=1;i<=n;i++){
          //  cout<<arrn[i]<<' ';
        }
        //cout<<endl;

        int64_t fans=0;
        fans=*max_element(ans+1,ans+n+1);



        cout<<fans<<endl;

    }

}
