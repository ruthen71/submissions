#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    int cnt = 0, ans = 0;
    int n = S.size();
    rep(i, n) {
        if (S[i] == 'R') {
            cnt++;
            if (cnt == 4) ans++, cnt = 0;
        } else {
            cnt--;
            if (cnt == -4) cnt = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 前から見ていき、1回転したらリセット
 */
