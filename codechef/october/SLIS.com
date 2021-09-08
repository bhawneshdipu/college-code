#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <utility>
#include <vector>

#define ALL(v) (v).begin(), (v).end()

const int N = 100000;
const int MOD = (int)1e9 + 7;

int a[N];

void update(int &x, int a) {
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

std::map<int, int> b[N];

void update_with(std::map<int, int> &m, const std::map<int, int> &o) {
    for (const auto &it : o) {
        ::update(m[it.first], it.second);
    }
    while ((int)m.size() > 2) {
        m.erase(m.begin());
    }
}

void debug(const std::map<int, int> &m) {
    printf("{");
    for (const auto &it : m) {
        printf("(%d, %d), ", it.first, it.second);
    }
    printf("}\n");
}

int main() {
    int T;
    assert(scanf("%d", &T) == 1);
    assert(1 <= T && T <= 10);
    for (int _ = 0; _ < T; ++ _) {
        int n;
        assert(scanf("%d", &n) == 1);
        assert(1 <= n && n <= N);
        std::vector<int> values;
        for (int i = 0; i < n; ++ i) {
            assert(scanf("%d", a + i) == 1);
            assert(1 <= a[i] && a[i] <= 1000000000);
            values.push_back(a[i]);
        }
        std::sort(ALL(values));
        values.erase(std::unique(ALL(values)), values.end());
        for (int i = 0; i < n; ++ i) {
            a[i] = std::lower_bound(ALL(values), a[i]) - values.begin();
            b[i].clear();
        }
        std::map<int, int> result;
        for (int i = 0; i < n; ++ i) {
            std::map<int, int> f;
            f[1] = 1;
            for (int j = a[i] - 1; j >= 0; j -= ~j & j + 1) {
                update_with(f, b[j]);
            }
            update_with(result, f);
            std::map<int, int> g;
            for (const auto &it : f) {
                g[it.first + 1] = it.second;
            }
            for (int j = a[i]; j < n; j += ~j & j + 1) {
                update_with(b[j], g);
            }
        }
        printf("%d\n", result.begin()->second);
    }
    return 0;
}
