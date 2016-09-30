#include<bits/stdc++.h>
using namespace std;

#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define pd(a) printf("%lf",a)

typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <vi> vvi;

struct Matrix{
    vvi mat;
    int r,c;


    Matrix(vvi values){
        r=values.size();
        c=values[0].size();
        mat=values;
    }


    static Matrix identityMatrix(int n){
        vvi values(n,vi(n,0));
        for(int i=0;i<n;i++)
            values[i][i]=1;
        return values;
    }


    Matrix operator * (const Matrix &other)const{
        int n=r;
        int m=other.c;
        vvi result(r,vi(c,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<c;k++){
                    result[i][j]=result[i][j]+mat[i][k]*other.mat[k][j];
                }
            }
        }
        return result;
    }


    inline bool  isSquare()const{
        return r==c;
    }

    void print(){
        int n=r;
        int m=c;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

Matrix fastExp(Matrix m,int power){
        assert(m.isSquare());
        Matrix result=Matrix::identityMatrix(m.r);

        while(power){
            if(power&1){
                result=result*m;
            }
            m=m*m;
            power >>=1;
        }
    return result;
}
int main(){
  std::cout.sync_with_stdio(false);
  std::cin.sync_with_stdio(false);
        cout<<"enter matrix"<<endl;
        vvi A(3,vi(3,0));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>A[i][j];
            }
        }
        cout<<"enter another"<<endl;
        vvi B(3,vi(3,0));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>B[i][j];
            }
        }

        Matrix a(A);
        a.print();

        Matrix b(B);
        b.print();
        Matrix c=a*b;
        c.print();
        c=fastExp(a,4);
        c.print();

return 0;
}
