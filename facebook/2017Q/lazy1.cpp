#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("A1.txt","r",stdin);
    //freopen("B1.txt","wt",stdout);
    int t,n,i,j;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        int W[n],B[101],Arr[n];
        for(j=0;j<=100;j++)
            B[j]=0;
        for(j=0;j<n;j++)
            {
                cin>>W[j];
                B[W[j]]++;
            }
        for(j=1;j<=100;j++)
            B[j]=B[j]+B[j-1];
        for(j=0;j<n;j++)
        {
            Arr[B[W[j]]-1]=W[j];
            B[W[j]]--;
        }
        //for(j=0;j<n;j++)
            //cout<<Arr[j]<<" ";
        //cout<<endl;

        //The War begins:-

        int first=0,last=n-1,kount=0,k=2;
        while(first<last)
        {
            if(Arr[last]>=50)
            {kount++;last--;}
            else
            {
                if(Arr[last]*k>=50)
                {last--;first++;kount++;k=2;}
                else{k++;first++;}
            }
        }
        if(first==last)
            if(Arr[last]>=50)
                kount++;
        //cout<<"first:"<<first<<" last:"<<last<<endl;
        cout<<"Case #"<<i<<": "<<kount<<endl;
    }
}
