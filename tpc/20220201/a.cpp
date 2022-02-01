#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s) {
        int n = s.size();
        for (int d = n - 1; d >= 0; d--) {
            int ok = 1;
            for (int i = 0; i + d <= n; i++) {
                int ok2 = 0;
                for (int j = 0; j + d <= n; j++) {
                    if (i == j) continue;
                    if (s.substr(i, d) == s.substr(j, d)) {
                        ok2 = 1;
                        break;
                    }
                }
                if (ok2 == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                cout << d << '\n';
                break;
            }
        }
    }
    return 0;
}

/**
 * 長さが大きい順にやる
 */
