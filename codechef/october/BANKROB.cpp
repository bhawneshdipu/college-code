#include <iostream>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <set>
#include <vector>


using namespace std;
const int NUMBER_OF_TEST_CASES = 100000;
const int maxM = 1000000000;
const int INIT_DOLLARS = 1000000000;

inline void Solve() {
       int M;
       double p;
       cin >> M >> p;
       assert(1 <= M && M <= maxM);
       assert(p > -1e-8 && p < 1 + 1e-8);

       double mul = INIT_DOLLARS;
       for (double _M = M - 1, _p = -p; _M > 0; _p *= _p, _M = (int)_M / 2) {
           if ((int)_M % 2 == 1) {
              mul *= _p;
           }
       }

       double first = (mul * -p - INIT_DOLLARS) / (-p - 1);
       double second = p / (-p - 1) * (mul - INIT_DOLLARS);

       if (abs(first) < 1e-7) first = 0;
       if (abs(second) < 1e-7) second = 0;

       cout.precision(10);
       cout << fixed << first << " " << second << endl;
}
int main() {
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;
    assert(1 <= T && T <= NUMBER_OF_TEST_CASES);
    while (T --> 0) {
          Solve();
    }

    return 0;
}
