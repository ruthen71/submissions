#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ll INF = 1ll << 60;

ll op(ll a, ll b) { return min(a, b); }

ll e() { return INF; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll s, p, m, n;
    cin >> s >> p >> m >> n;
    vector<ll> t(n + 1);
    rep(i, n) cin >> t[i + 1];
    rep(i, n) t[i + 1]++;
    t[0] = 0;
    segtree<ll, op, e> seg(n + 1);
    seg.set(0, 0);
    for (int i = 1; i <= n; i++) {
        // 1回チケット
        seg.set(i, min(seg.get(i), seg.get(i - 1) + s));
        // m日チケット
        int d = t[i] - m + 1;
        int idx = lower_bound(ALL(t), d) - t.begin();
        seg.set(i, min(seg.get(i), seg.prod(max(idx - 1, 0), n + 1) + p));
    }
    ll ans = seg.get(n);
    cout << ans << '\n';
    return 0;
}

/**
 * 難読
 * 1回チケットが「1日チケット」ではない点など、情報が不足しすぎている
 */
