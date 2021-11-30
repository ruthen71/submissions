#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

const ll INF = 1ll << 60;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    vector<vector<ll>> dp1(N, vector<ll>(2, INF));
    dp1[0][0] = 0;
    for (int i = 1; i < N; i++) {
        // dp[i][0]
        dp1[i][0] = min(dp1[i - 1][0] + B[i - 1], dp1[i - 1][1]);
        // dp[i][1]
        dp1[i][1] = min(dp1[i - 1][0] + A[i], dp1[i - 1][1] + A[i] + B[i - 1]);
    }
    ll ans1 = min(dp1[N - 1][0] + B[N - 1], dp1[N - 1][1]);
    vector<vector<ll>> dp2(N, vector<ll>(2, INF));
    dp2[0][1] = A[0];
    for (int i = 1; i < N; i++) {
        // dp[i][0]
        dp2[i][0] = min(dp2[i - 1][0] + B[i - 1], dp2[i - 1][1]);
        // dp[i][1]
        dp2[i][1] = min(dp2[i - 1][0] + A[i], dp2[i - 1][1] + A[i] + B[i - 1]);
    }
    ll ans2 = min(dp2[N - 1][0], dp2[N - 1][1] + B[N - 1]);
    ll ans = min(ans1, ans2);
    cout << ans << '\n';
    return 0;
}

/**
 * 円環上のDP
 * とりあえず色の塗り方を全部試すのは無理
 * ->順番に決めてみる->同じ構造が繰り返されるのでDPできそう
 * 円環上のDPは初期状態も持っておく
 */