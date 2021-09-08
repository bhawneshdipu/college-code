#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 3000;
const int SQRT_MAXN = 54;
int MOD = 1000000007;

vector<int> primes;
int f[MAXN + 1], prime2index[MAXN + 1], dp[2][1 << 16];

int main()
{
    memset(f, -1, sizeof(f));
    memset(prime2index, -1, sizeof(prime2index));
    f[1] = 1;
    for (int i = 2; i <= MAXN; ++ i) {
        if (f[i] == -1) {
            for (int j = i; j <= MAXN; j += i) {
                f[j] = i;
            }
            prime2index[i] = primes.size();
            primes.push_back(i);
        }
    }

    int tests, test = 1;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        int n;
        scanf("%d%d", &n, &MOD);
        int sqrt_n = (int)sqrt(n) + 1;
        int smallPrimes = 0;
        for (int i = 2; i <= sqrt_n; ++ i) {
            if (f[i] == i) {
                ++ smallPrimes;
            }
        }
        vector<int> odd(smallPrimes, 0);
        vector< vector<int> > special(primes.size(), vector<int>());
        vector<int> specialCnt(primes.size(), 0);
        vector<int> normal;
        for (int i = 0; i < n; ++ i) {
            int affect = 0, value = i + 1;
            //assert(scanf("%d", &value) == 1);
            assert(value >= 1 && value <= n);
            bool valid = true;
            for (int x = value; x > 1; x /= f[x]) {
                if (f[x] <= sqrt_n) {
                    int id = prime2index[f[x]];
                    assert(id != -1);

                    odd[id] ^= 1;
                    if (affect >> id & 1) {
                        valid = false;
                    }

                    affect ^= 1 << id;
                }
            }
            if (valid) {
                if (f[value] <= sqrt_n) {
                    normal.push_back(affect);
                } else {
                    int id = prime2index[f[value]];
                    assert(prime2index[f[value]] != -1);
                    special[id].push_back(affect);
                }
            }

            if (f[value] > sqrt_n) {
                int id = prime2index[f[value]];
                specialCnt[id] ^= 1;
            }

        }

        int todo = 0;
        for (int i = 0; i < smallPrimes; ++ i) {
            todo ^= odd[i] << i;
        }

        memset(dp, 0, sizeof(dp));
        dp[0][todo] = 1;
        int now = 0, old = 1;
        for (int i = 0; i < normal.size(); ++ i) {
            if ((todo & normal[i]) != normal[i]) {
                continue;
            }
            int item = normal[i];

            now = 1 - now;
            old = 1 - old;
            memcpy(dp[now], dp[old], sizeof(dp[old]));
            for (int mask = 0; mask < 1 << smallPrimes; ++ mask) {
                if ((mask & item) == item) {
                    dp[now][mask ^ item] += dp[old][mask];
                    if (dp[now][mask ^ item] >= MOD) {
                        dp[now][mask ^ item] -= MOD;
                    }
                }
            }
        }

        int counter = 0;
        for (int i = 0; i < special.size(); ++ i) {
            if (specialCnt[i]) {
                ++ counter;
                now = 1 - now;
                old = 1 - old;
                memset(dp[now], 0, sizeof(dp[now]));
                for (int j = 0; j < special[i].size(); ++ j) {
                    int item = special[i][j];
                    if ((item & todo) != item) {
                        continue;
                    }
                    for (int mask = 0; mask < 1 << smallPrimes; ++ mask) {
                        if ((mask & item) == item) {
                            dp[now][mask ^ item] += dp[old][mask];
                            if (dp[now][mask ^ item] >= MOD) {
                                dp[now][mask ^ item] -= MOD;
                            }
                        }
                    }
                }
            }
        }
        cerr << "Debug: counter = " << counter << endl;
        printf("%d\n", dp[now][0]);
    }
    return 0;
}
