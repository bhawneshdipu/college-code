#include <cctype>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>

#define ALL(v) (v).begin(), (v).end()

int main() {
    int T;
    assert(scanf("%d", &T) == 1);
    assert(1 <= T && T <= 10);
    while (T --) {
        int n;
        assert(scanf("%d", &n) == 1);
        assert(1 <= n && n <= 10);
        std::vector<std::string> s;
        for (int i = 0; i < n; ++ i) {
            char buffer[21];
            assert(scanf("%s", buffer) <= 20);
            for (int i = 0; buffer[i]; ++ i) {
                assert(islower(buffer[i]));
            }
            s.push_back(buffer);
        }
        int l = (int)s[0].size();
        std::string result;
        while (l) {
            for (int i = 0; i + l <= (int)s[0].size(); ++ i) {
                std::string substring = s[0].substr(i, l);
                bool common = true;
                for (int j = 0; j < n; ++ j) {
                    common &= s[j].find(substring) != std::string::npos;
                }
                if (common) {
                    if (result.empty()) {
                        result = substring;
                    }
                    result = std::min(result, substring);
                }
            }
            if (!result.empty()) {
                break;
            }
            l --;
        }
        printf("%s\n", result.c_str());
    }
    return 0;
}
