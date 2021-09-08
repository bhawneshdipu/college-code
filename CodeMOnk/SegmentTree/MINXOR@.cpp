#ifdef ssu1
#define _GLIBCXX_DEBUG
#endif
#undef NDEBUG

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>

using namespace std;

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename T> T abs(T a) { return a < 0 ? -a : a; }
template<typename T> T sqr(T a) { return a*a; }

const int INF = (int)1e9;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

/*
    This is just to check correctness of input

*/
void ensure(bool value){
    if(!value){
        fprintf(stderr, "Assertion failed");
        throw;
    }
}
void ensure(bool value, string message){
    if(!value){
        fprintf(stderr, "Assertion failed. Message = %s", message.c_str());
        throw;
    }
}
int readInt(int l, int r){
    int x;
    if(scanf("%d", &x) != 1){
        fprintf(stderr, "Expected int in range [%d, %d], but haven't found!", l, r);
        throw;
    }
    if(!(l <= x && x <= r)){
        fprintf(stderr, "Expected int in range [%d, %d], but found %d!", l, r, x);
        throw;
    }
    return x;
}
int readInt(int l, int r, string name){
    int x;
    if(scanf("%d", &x) != 1){
        fprintf(stderr, "Expected int %s in range [%d, %d], but haven't found!", name.c_str(), l, r);
        throw;
    }
    if(!(l <= x && x <= r)){
        fprintf(stderr, "Expected int %s in range [%d, %d], but found %d!", name.c_str(), l, r, x);
        throw;
    }
    return x;
}
li readLong(li l, li r){
    li x;
    if(scanf(LLD, &x) != 1){
        fprintf(stderr, "Expected long long in range ["LLD", "LLD"], but haven't found!", l, r);
        throw;
    }
    if(!(l <= x && x <= r)){
        fprintf(stderr, "Expected long long in range ["LLD", "LLD"], but found "LLD"!", l, r, x);
        throw;
    }
    return x;
}
li readLong(li l, li r, string name){
    li x;
    if(scanf(LLD, &x) != 1){
        fprintf(stderr, "Expected long long %s in range ["LLD", "LLD"], but haven't found!", name.c_str(), l, r);
        throw;
    }
    if(!(l <= x && x <= r)){
        fprintf(stderr, "Expected long long %s in range ["LLD", "LLD"], but found "LLD"!", name.c_str(), l, r, x);
        throw;
    }
    return x;
}
const ld __EPS__ = 1e-15;
ld readDouble(double l, double r){
    double x;
    if(scanf("%lf", &x) != 1){
        fprintf(stderr, "Expected double in range [%lf, %lf], but haven't found!", l, r);
        throw;
    }
    if(!(l <= x + __EPS__ && x <= r + __EPS__)){
        fprintf(stderr, "Expected double in range [%lf, %lf], but found %lf!", l, r, x);
        throw;
    }
    return x;
}
ld readDouble(double l, double r, string name){
    double x;
    if(scanf("%lf", &x) != 1){
        fprintf(stderr, "Expected double %s in range [%lf, %lf], but haven't found!", name.c_str(), l, r);
        throw;
    }
    if(!(l <= x + __EPS__ && x <= r + __EPS__)){
        fprintf(stderr, "Expected double %s in range [%lf, %lf], but found %lf!", name.c_str(), l, r, x);
        throw;
    }
    return x;
}
const int __MAXBUF__ = (int)1e7;
char __buf__[__MAXBUF__];
string readString(char lfc, char rgc, int lfn, int rgn){
    ensure(scanf(" %s ", __buf__) == 1, "Expected string, haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "String have incorrect length");
    forn(i, sz(ans))
        ensure(lfc <= ans[i] && ans[i] <= rgc, "String contains incorrect characters");
    return ans;
}
string readString(string pat, int lfn, int rgn){
    ensure(scanf(" %s ", __buf__) == 1, "Expected string, haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "String have incorrect length");
    forn(i, sz(ans))
        ensure(find(all(pat), ans[i]) != pat.end(), "String contains incorrect characters");
    return ans;
}
string readString(char lfc, char rgc, int lfn, int rgn, string name){
    ensure(scanf(" %s ", __buf__) == 1, "Expected string " + name + ", haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "String " + name + " have incorrect length");
    forn(i, sz(ans))
        ensure(lfc <= ans[i] && ans[i] <= rgc, "String " + name + " contains incorrect characters");
    return ans;
}
string readString(string pat, int lfn, int rgn, string name){
    ensure(scanf(" %s ", __buf__) == 1, "Expected string " + name + ", haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "String " + name + " have incorrect length");
    forn(i, sz(ans))
        ensure(find(all(pat), ans[i]) != pat.end(), "String " + name + " contains incorrect characters");
    return ans;
}
string readLine(char lfc, char rgc, int lfn, int rgn){
    ensure(gets(__buf__) != NULL, "Line expected, haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "Line have incorrect length");
    forn(i, sz(ans))
        ensure(lfc <= ans[i] && ans[i] <= rgc, "Line contains incorrect characters");
    return ans;
}
string readLine(string pat, int lfn, int rgn){
    ensure(gets(__buf__) != NULL, "Line expected, haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "Line have incorrect length");
    forn(i, sz(ans))
        ensure(find(all(pat), ans[i]) != pat.end(), "Line contains incorrect characters");
    return ans;
}
string readLine(){
    ensure(gets(__buf__) != NULL, "Line expected, haven't found");
    string ans = __buf__;
    return ans;
}
char readChar(){
    char c;
    ensure(scanf(" %c ", &c) == 1, "Non-whitespace character expected");
    return c;
}
char readWChar(){
    int ans = getchar();
    ensure(ans != EOF, "Character expected");
    return (char)ans;
}

const int LOG = 16;
const int NMAX = 260000;
const int BMAX = 500;

inline int bit(int value, int idx){
    return (value >> idx) & 1;
}

struct trie{
    vector<int> nx[2], cnt;
    int xored;

    trie(){
        xored = 0;
    }

    void rebuild(){
        xored = 0;
        cnt.assign(1, 0);
        nx[0].assign(1, -1);
        nx[1].assign(1, -1);
        assert(sz(cnt) == 1 && nx[0][0] == -1);
    }

    void add(int numb){
        int v = 0;
        forn(i, LOG){
            int c = bit(numb, LOG - i - 1);
            int nv = nx[c][v];
//            cout << v << " " << i << " " << c << " " << nv << endl;
            if(nv == -1){
                nv = sz(cnt);
                cnt.pb(0), nx[0].pb(-1), nx[1].pb(-1);
                nx[c][v] = nv;
            }
//            cout << nv << endl;
            v = nx[c][v];
        }
        cnt[v]++;
    }

    pt getmin(){
        if(sz(cnt) == 1)
            return mp(INF, 0);
        int ans = 0, v = 0;
        forn(i, LOG){
            forn(b, 2){
                if(nx[b ^ bit(xored, LOG - i - 1)][v] != -1){
                    ans |= b << (LOG - i - 1);
                    v = nx[b ^ bit(xored, LOG - i - 1)][v];
                    break;
                }
            }
        }
        assert(cnt[v] > 0);
        return mp(ans, cnt[v]);
    }
};

trie t[NMAX / BMAX];
int a[NMAX], add[NMAX / BMAX], n, q;

inline void relax(int id){
    if(add[id]){
        fore(i, BMAX * id, min(n, BMAX * (id + 1)))
            a[i] ^= add[id];
        add[id] = 0;
    }
}

inline void rebuild(int id){
    t[id].rebuild();
    add[id] = 0;

//    cout << id << endl;
    fore(i, BMAX * id, min(n, BMAX * (id + 1))){
        t[id].add(a[i]);
//        cout << " + " << a[i] << " " <<  t[id].getmin().X << " " << t[id].getmin().Y << endl;
    }
}

inline void upd(pt& mine, const pt& value){
    if(value.X <= mine.X){
        if(value.X < mine.X)
            mine.X = value.X, mine.Y = 0;
        mine.Y += value.Y;
    }
}

int main(){
#ifdef ssu1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif

    n = readInt(1, 250000, "n"), q = readInt(0, 50000, "q");
    forn(i, n){
        a[i] = readInt(0, (1 << 16) - 1);
    }

    for(int l = 0, i = 0; l < n; l += BMAX, i++){
//        cout << i << endl;
        rebuild(i);
    }
//    cout << '+' << endl;

    int q1 = 0, q2 = 0;
    forn(qi, q){
        int type = readInt(1, 2, "type");
        if(type == 1){
            q1++;
            int l = readInt(1, n);
            int r = readInt(l, n);
            l--, r--;

            relax(l / BMAX);
            relax(r / BMAX);

            pt e(INF, 0);
            for(int pos = l; pos <= r;){
                if(pos % BMAX == 0 && pos + BMAX - 1 <= r){
                    pt cur = t[pos / BMAX].getmin();
//                    cerr << qi << " " << cur.X << " " << cur.Y << endl;
                    upd(e, cur);
                    pos += BMAX;
                }else{
                    upd(e, mp(a[pos], 1));
                    pos++;
                }
            }

            printf("%d %d\n", e.X, e.Y);
        }else{
            q2++;
            int l = readInt(1, n);
            int r = readInt(l, n);
            int k = readInt(0, (1 << 16) - 1);
            l--, r--;

            relax(l / BMAX);
            relax(r / BMAX);

            for(int pos = l; pos <= r;){
                if(pos % BMAX == 0 && pos + BMAX - 1 <= r){
                    int id = pos / BMAX;
                    t[id].xored ^= k;
                    add[id] ^= k;
                    pos += BMAX;
                }else{
                    a[pos] ^= k;
                    pos++;
                }
            }

            relax(l / BMAX);
            relax(r / BMAX);

            rebuild(l / BMAX);
            if(l / BMAX != r / BMAX)
                rebuild(r / BMAX);
        }
    }

    ensure(q1 <= 40000, "q1");
    ensure(q2 <= 10000, "q2");
    return 0;
}
