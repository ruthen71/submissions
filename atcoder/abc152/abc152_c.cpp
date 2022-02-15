#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int ans = 0, m = 10000000;
    rep(i, N) {
        int p;
        cin >> p;
        if (p <= m) ans++;
        m = min(m, p);
    }
    cout << ans << '\n';
    return 0;
}

/**
 * それまでに出現した値の最小値より小さければ良い
 */
