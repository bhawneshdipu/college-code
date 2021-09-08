#include<iostream>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<cstdlib>
using namespace std;
int  flag=1;
int gox=0;
stack < int > si,sj;
string a[10+5];
int  visited[10+5][10+6];
int nn,tt;
int len=0;
int flagx=0;
void fillstack(char &ch,int &nn)
{
    for(int i=nn-1;i>=0;i--)
    {
        for(int j=nn-1;j>=0;j--)
        {
            if(ch==a[i][j])
            {
               si.push(i);
               sj.push(j);
            }
        }
    }

}
void free()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            visited[i][j]=0;
        }
    }
gox=0;
flagx=0;
}
void solve(int next,string &b,int &nn,int ii,int jj,int go)
{
        char ch=b[next];
        stack <int> ni,nj,ns;
        stack <char> nc;
        if(ii-1>=0&&jj-1>=0&&ch==a[ii-1][jj-1]&&visited[ii-1][jj-1]==0)
        {
            if(next==len-1&&go==1&&ch==b[next])
            {
                flagx=1;
            }
            ni.push(ii-1);nj.push(jj-1);
            go=1;
        }
        if(ii-1>=0&&jj<nn&&ch==a[ii-1][jj]&&visited[ii-1][jj]==0)
        {
            if(next==len-1&&go==1&&ch==b[next])
            {
             flagx=1;
            }
            ni.push(ii-1);
            nj.push(jj);
            go=1;
        }
        if(ii-1>=0&&jj+1<nn&&ch==a[ii-1][jj+1]&&visited[ii-1][jj+1]==0)
        {
            if(next==len-1&&go==1&&ch==b[next])
            {
             flagx=1;
             }
             ni.push(ii-1);
            nj.push(jj+1);
            go=1;
        }
        if(ii>=0&&jj+1<nn&&ch==a[ii][jj+1]&&visited[ii][jj+1]==0)
        {
            if(next==len-1&&go==1&&ch==b[next])
            {
             flagx=1;
             }
            ni.push(ii);
            nj.push(jj+1);
            go=1;
        }
        if(ii+1<nn&&jj+1<nn&&ch==a[ii+1][jj+1]&&visited[ii+1][jj+1]==0)
        {
            if(next==len-1&&go==1&&ch==b[next])
            {
             flagx=1;
            }
            ni.push(ii+1);
            nj.push(jj+1);
            go=1;
        }
        if(ii+1<nn&&jj>=0&&ch==a[ii+1][jj]&&visited[ii+1][jj]==0)
        {
            if(next==len-1&&go==1&&ch==b[next])
            {
             flagx=1;
            }
            ni.push(ii+1);
            nj.push(jj);
            go=1;
        }
        if(ii+1<nn&&jj-1>=0&&ch==a[ii+1][jj-1]&&visited[ii+1][jj-1]==0)
        {
            if(next==len-1&&go==1&&ch==b[next])
            {
             flagx=1;
            }
            ni.push(ii+1);
            nj.push(jj-1);
            go=1;
        }
        if(ii<nn&&jj-1>=0&&ch==a[ii][jj-1]&&visited[ii][jj-1]==0)
        {
            if(next==len-1&&go==1&&ch==b[next])
            {
             flagx=1;
            }
            ni.push(ii);
            nj.push(jj-1);
            go=1;
        }
/*--------------------------------------------------------------------*/
        if(ni.empty()&&nj.empty()&&next!=len-1&&flagx==0)
        {
            flagx=0;
            go=0;
        }
        while(!ni.empty()&&!ni.empty())
        {
            ii=ni.top();
            jj=nj.top();
            ni.pop();nj.pop();
            visited[ii][jj]=1;
            solve(next+1,b,nn,ii,jj,go);
            visited[ii][jj]=0;
        }
}
int main()
{
    cin>>tt>>nn;
    for(int i=0;i<nn;i++)
    {
        cin.ignore();
        cin>>a[i];
    }
    for(int i=0;i<tt;i++)
    {
        string b;
        cin>>b;
        int l=b.size();
            len=l;
        char ch=b[0];
        fillstack(ch,nn);
        free();
        while(!si.empty()&&!sj.empty())
        {
            int ii=si.top();
        	int jj=sj.top();
        	si.pop();sj.pop();
            visited[ii][jj]=1;
            if(len==1)
            {
                flagx=1;
            }
            else
            {
            solve(1,b,nn,ii,jj,1);
            }
            visited[ii][jj]=0;

        }
		if(nn==0)
            cout<<"NO\n";
        else if(flagx==1)cout<<"YES\n";
		else
			cout<<"NO\n";
    }
}

