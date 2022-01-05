#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<ll> P(N);
    rep(i, N) cin >> P[i];
    vector<ll> id(N + 1, -1);
    rep(i, N) id[P[i]] = i;
    multiset<ll> s = {-1, -1, N, N, id[N]};
    ll ans = 0;
    for (ll p = N - 1; p >= 1; p--) {
        auto it = s.lower_bound(id[p]);
        it--;
        ll v1 = *it--;
        ll v2 = *it++;
        it++;
        ll p1 = *it++;
        ll p2 = *it;
        ans += p * (v1 - v2) * (p1 - id[p]);
        ans += p * (p2 - p1) * (id[p] - v1);
        s.insert(id[p]);
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 寄与を考える(典型考察)
 * だいたい「全てのf(x)についての総和」系で出てくる
 * 境界条件は番兵を2つ入れて簡潔に
 */
