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
    vector<ll> cum(N + 1, 0);
    rep(i, N) cum[i + 1] = cum[i] + A[i];
    // cum[j]-cum[i]=K(i<j)
    // cum[j]=cum[i]+K
    ll ans = 0;
    map<ll, ll> mp;
    rep(i, N + 1) {
        ans += mp[cum[i]];
        mp[cum[i] + K]++;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * Zero-Sum-Ranges 系
 */