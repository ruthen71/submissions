#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    vector<ll> cum(N + 1, 0);
    rep(i, N) cum[i + 1] = cum[i] + a[i];
    ll ans = 0;
    rep(i, N + 1) {
        int ind = lower_bound(ALL(cum), cum[i] + K) - cum.begin();
        ans += N + 1 - ind;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 尺取り法や累積和の練習に良い
 */