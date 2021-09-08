include<iostream>
#include<bits/stdc++.h>

using namespace std;
int getmid(int s,int e)
{
    return (s+(e-s)/2);
}
int fun(int x)
{
    if(x%2)
        return 2;
    else
        return 1;
}
int makeSTUtil(int a[],int *st,int si,int ss,int se)
{
    if(ss==se)
    {
        st[si]=a[ss];
        return st[si];
    }
    int m=getmid(ss,se);
    st[si]=(makeSTUtil(a,st,2*si+1,ss,m)*fun(se-m)+makeSTUtil(a,st,2*si+2,m+1,se))%3;
    return  st[si];
}
int *makeST(int a[],int n)
{
    int h= (int)ceil(log2(n));
    int N= 2*(int)pow(2,h)-1;
    int *st = new int[N];
    makeSTUtil(a,st,0,0,n-1);
    return st;
}

int rmq(int *st,int si,int ss,int se,int qs,int qe)
{
   if(qs<=ss && se<=qe)
        return st[si];
   if(se<qs || ss>qe)
        return INT_MAX;
    int m =getmid(ss,se);
   return min(rmq(st,2*si+1,ss,m,qs,qe),rmq(st,2*si+2,m+1,se,qs,qe));
}
int qry(int *st,int si,int ss,int se,int qs,int qe)
{
    if(qs<=ss && se<=qe)
        return st[si];
//   if(se<qs || ss>qe)
//        return 0;
int m =getmid(ss,se);
    if(qe<=m)
        return qry(st,2*si+1,ss,m,qs,qe);
    if(qs>m)
        return qry(st,2*si+2,m+1,se,qs,qe);

   return (qry(st,2*si+1,ss,m,qs,m)*fun(qe-m)+qry(st,2*si+2,m+1,se,m+1,qe))%3;
}
void update(int *st,int si,int ss,int se, int i)
{
    if(i==ss && i==se)
        st[si]=1;
    else
    {
        if(ss<=i && i<=se)
        {
            st[si] = (st[si]+fun(se-i))%3;
            int m=getmid(ss,se);
            update(st,2*si+1,ss,m,i);
            update(st,2*si+2,m+1,se,i);
        }
    }
}
int main()
{
    int n,q,i,t,l,r;
    char b;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>b;
        a[i]=b-'0';
    }
    int *st = makeST(a,n);
//    for(int i=0;i<15;i++)
//        cout<<st[i]<<" ";
//    cout<<endl;
    cin>>q;
    while(q--)
    {
        cin>>t;
        if(!t)
        {   cin>>l>>r;
            cout<<qry(st,0,0,n-1,l,r)<<endl;
        }
        else
        {
            cin>>l;
            if(!a[l])
            {update(st,0,0,n-1,l);
            a[l]=1;
            }
        }
    }
}
