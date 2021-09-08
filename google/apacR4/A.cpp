#include<iostream>
#include<memory.h>
using namespace std;
#define MAX 107
const int dx[] = {+1, 0, -1, 0};
const int dy[] = {0, +1, 0, -1};

int row_count;
int col_count;

int m[MAX][MAX];

int label[MAX][MAX];

void dfs(int x, int y, int current_label) {
  if (x < 0 || x == row_count) return;
  if (y < 0 || y == col_count) return;
  if (label[x][y] || !m[x][y]) return;

  label[x][y] = current_label;

  for (int direction = 0; direction < 4; ++direction)
    dfs(x + dx[direction], y + dy[direction], current_label);
}

int find_components() {
  int component = 0;
  for (int i = 0; i < row_count; ++i)
    for (int j = 0; j < col_count; ++j)
      if (!label[i][j] && m[i][j]) dfs(i, j, ++component);

      return component;
}
void clear(){
    memset(label,0,sizeof(label));
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int tt;
    cin>>tt;
    for(int test=1;test<=tt;test++){
            cout<<"Case #"<<test<<":"<<endl;
        cin>>row_count>>col_count;
        for(int i=0;i<row_count;i++){
            for(int j=0;j<col_count;j++){
                    char ch;
                    cin>>ch;
                m[i][j]=(ch-'0');

            }

        }
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            char ch;
            cin>>ch;
            if(ch=='M'){
                int a,b,c;
                cin>>a>>b>>c;
                m[a][b]=c;

            }else if(ch=='Q'){
                clear();
                cout<<find_components()<<endl;;
            }

        }


    }

}
