#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> c(N + 1, 0);
    rep(i, N) c[i + 1] = (c[i] + A[i]) % K;
    map<ll, ll> mp;
    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        if (i - K >= 0) mp[(c[i - K] - (i - K) % K + K) % K]--;
        ans += mp[(c[i] - i % K + K) % K];
        mp[(c[i] - i % K + K) % K]++;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * Zero-Sum ranges 系
 * (cum[j]-cum[i])%K == j-i
 * から、考察を進めて0<=j-i<Kのみ考えれば良いと気づくと
 * cum[j]-j=cum[i]-i(mod K)
 * になり、いつもの、になる
 */
