#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 10007;

bool rock[110][110];
ll dp[110][110];

int main() {

  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    memset(rock, 0, sizeof(rock));
    memset(dp, 0, sizeof(dp));

    int W, H, R;
    scanf("%d%d%d", &W, &H, &R);

    for(int i=0;i<R;i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      rock[x][y] = true;
    }

    dp[1][1] = 1;
    for (int x = 1; x <= W; x++) {
      for (int y = 1; y <= H; y++) {
        if (rock[x][y]) dp[x][y] = 0;
        else {
          dp[x][y] %= MOD;

          dp[x + 2][y + 1] += dp[x][y];
          dp[x + 1][y + 2] += dp[x][y];
        }
      }
    }

    printf("Case #%d: %d\n", t, dp[W][H]);
  }
  return 0;
}
