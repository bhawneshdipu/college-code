#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int MAX_N = 2000000;
char buf[MAX_N + 1];
int n, l[MAX_N], sz[MAX_N], ex[MAX_N], next[MAX_N];
char s[MAX_N], t[MAX_N];
long long ans;

namespace trie {
    const int MAX_V = MAX_N + 1, MAX_E = 10000000;
    int ecnt, begin[MAX_V], to[MAX_E], next[MAX_E], end[MAX_V], cnt[MAX_V];
    char val[MAX_V];

    int node_idx, root;

    void init() {
        ecnt = 0;
        memset(begin, -1, sizeof(begin));
        node_idx = 0;
        root = node_idx ++;
        val[root] = -1;
        memset(end, 0, sizeof(end));
        memset(cnt, 0, sizeof(cnt));
    }

    void add_edge(int u, int v) {
        next[ecnt] = begin[u];
        begin[u] = ecnt;
        to[ecnt ++] = v;
    }

    void ins(int sz) {
        int pos = root;
        for (int i = 0; i < sz; i ++) {
            int t = s[i] - 'a';
            if (ex[i] == sz - i) cnt[pos] ++;
            bool exi = 0;
            for (int now = begin[pos]; now != -1; now = next[now])
                if (val[to[now]] == t) {
                    exi = 1;
                    pos = to[now];
                }
            if (!exi) {
                int v = node_idx ++;
                add_edge(pos, v);
                val[v] = t;
                pos = v;
            }
        }
        end[pos] ++;
    }

    void go(int sz) {
        int pos = root;
        for (int i = 0; i < sz; i ++) {
            int t = s[i] - 'a';
            bool exi = 0;
            for (int now = begin[pos]; now != -1; now = next[now])
                if (val[to[now]] == t) {
                    exi = 1;
                    pos = to[now];
                }
            if (!exi) return;
            if (end[pos]) {
                 if (i < sz - 1 && ex[i + 1] == sz - i - 1) ans += end[pos];
                 else if (i == sz - 1) ans += end[pos];
            }
        }
        ans += cnt[pos];
    }
}

void ex_kmp(int len) {
    //memset(ex, 0, sizeof(int) * len), memset(next, 0, sizeof(int) * len);
    next[0] = len;
    next[1] = len - 1;
    for (int i = 0; i < len - 1; i ++)
        if (t[i] != t[i + 1]) {
            next[1] = i;
            break;
        }
    int j, k = 1, p, l;
    for (int i = 2; i < len; i ++) {
        p = k + next[k] - 1;
        l = next[i - k];
        if (i + l - 1 < p) next[i] = l;
        else {
            j = std::max(0, p + 1 - i);
            while (i + j < len && t[i + j] == t[j]) j ++;
            next[i] = j, k = i;
        }
    }
    ex[0] = len;
    for (int i = 0; i < len; i ++)
        if (s[i] != t[i]) {
            ex[0] = i;
            break;
        }
    k = 0;
    for (int i = 1; i < len; i ++) {
        p = k + ex[k] - 1;
        l = next[i - k];
        if (i + l - 1 < p) ex[i] = l;
        else {
            j = std::max(0, p + 1 - i);
            while (i + j < len && s[i + j] == t[j]) j ++;
            ex[i] = j, k = i;
        }
    }
}

int main() {
    int T;
    assert(scanf("%d", &T) == 1);
    assert(1 <= T && T <= 5);
    while (T --) {
        assert(scanf("%d", &n) == 1);
        assert(1 <= n && n <= 1000000);
        int tot = 0;
        ans = 0;
        for (int i = 0; i < n; i ++) {
            assert(scanf("%s", buf + tot) == 1);
            for (int j = tot; buf[j]; ++ j) {
                assert(islower(buf[j]));
            }
            sz[i] = strlen(buf + tot);
            bool palin = true;
            for (int j = 0; j < sz[i]; ++ j) {
                palin &= buf[tot + j] == buf[tot + sz[i] - 1 - j];
            }
            l[i] = tot;
            tot += sz[i];
            ans -= palin;
        }
        trie::init();
        for (int it = 0; it < n; it ++) {
            for (int i = 0; i < sz[it]; i ++) s[i] = buf[l[it] + sz[it] - i - 1];
            for (int i = 0; i < sz[it]; i ++) t[i] = buf[l[it] + i];
            ex_kmp(sz[it]);
            trie::ins(sz[it]);
        }
        for (int it = 0; it < n; it ++) {
            for (int i = 0; i < sz[it]; i ++) s[i] = buf[l[it] + i];
            for (int i = 0; i < sz[it]; i ++) t[i] = buf[l[it] + sz[it] - i - 1];
            ex_kmp(sz[it]);
            trie::go(sz[it]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
