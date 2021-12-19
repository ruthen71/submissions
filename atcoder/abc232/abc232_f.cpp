#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ll INF = 1ll << 60;

#define popcnt(x) __builtin_popcountll(x)

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    ll N2 = (1 << N);
    vector<ll> dp(N2, INF);
    dp[0] = 0;
    rep(S, N2) {
        int idx = popcnt(S);
        // A[idx]をBの何かとくっつける
        int cnt = idx;
        rep(j, N) {
            if (S >> j & 1) continue;
            dp[S + (1 << j)] = min(dp[S + (1 << j)], dp[S] + (cnt - idx) * Y + abs(A[idx] - B[j]) * X);
            cnt++;
        }
    }
    cout << dp[N2 - 1] << '\n';
    return 0;
}

/**
 * 順列をbitDPに落とすやつ
 */