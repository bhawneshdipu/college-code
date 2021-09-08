#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int mod = (1e9) + 7;
// LL pw[3e6];
LL sq(int d, int n) {
    int carry = 0;
    vector<int> vec;
    int dp = d * d;
    vec.resize(2*n - 1);
    for (int i = 0; i < n; i++) {
        int v = (i + 1) * dp + carry;
        vec[i] = (v % 10);
        carry = v / 10;
    }
    for (int i = n - 1; i >= 1; i--) {
        int v = i * dp + carry;
        vec[2*n - i - 1] = v % 10;
        carry = v / 10;
    }
    while (carry) {
        vec.push_back(carry % 10);
        carry /= 10;
    }
      LL ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        ans = (vec[i] + 23 * ans) % mod;
    }
    return ans;
}

int main() {

    int t, d, n;


    for (cin >> t; t--;) {
        cin >> n >> d;
        cout << sq(d, n) << endl;
    }
    return 0;
}
