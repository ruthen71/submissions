#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll a, s;
        cin >> a >> s;
        ll r = s, b = 1;
        // 実質r=s-2*aじゃん！
        rep(i, 60) {
            if (a >> i & 1) {
                r -= 2 * b;
            }
            b *= 2;
        }
        if (r < 0) {
            cout << "No" << '\n';
            continue;
        }
        // 実質(r&a)==0じゃん！
        for (int i = 59; i >= 0; i--) {
            b /= 2;
            if (a >> i & 1) continue;
            if (r >= b) r -= b;
        }
        cout << (r == 0 ? "Yes" : "No") << '\n';
        assert(b == 1);
    }
    return 0;
}
