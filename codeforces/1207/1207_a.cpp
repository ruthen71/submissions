#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

void solve() {
    ll b, p, f, h, c;
    cin >> b >> p >> f >> h >> c;
    ll ans = 0;
    for (int i = 0; i <= p; i++) {
        ll bf = b - 2 * i;
        if (bf < 0) continue;
        ans = max(ans, h * i + c * min(bf / 2, f));
    }
    cout << ans << '\n';
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

/*
ECR071
Educational Codeforces Round 071
Div2
*/