#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ll INF = 1ll << 60;

ll dp[205][205][4];

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

void solve(int N, int K) {
    vector<vector<ll>> A(N, vector<ll>(2));
    rep(i, N) rep(j, 2) cin >> A[i][j];
    rep(i, N + 1) rep(j, N + 1) rep(k, 4) dp[i][j][k] = INF;
    ll s = 0;
    rep(i, N) rep(j, 2) s += A[i][j];
    dp[0][0][0] = 0;
    rep(i, N) {
        for (int j = 0; j <= N; j++) {
            chmin(dp[i + 1][j][0], dp[i][j][0]);
            chmin(dp[i + 1][j][0], dp[i][j][1]);
            chmin(dp[i + 1][j][0], dp[i][j][2]);
            chmin(dp[i + 1][j + 1][2], dp[i][j][0] + A[i][0]);
            chmin(dp[i + 1][j + 1][2], dp[i][j][2] + A[i][0]);
            chmin(dp[i + 1][j + 1][1], dp[i][j][0] + A[i][1]);
            chmin(dp[i + 1][j + 1][1], dp[i][j][1] + A[i][1]);
        }
    }
    ll ans = INF;
    rep(k, 4) ans = min(ans, dp[N][K][k]);
    assert(ans != INF);
    cout << s - ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    while (cin >> N >> K, N != 0) solve(N, K);
    return 0;
}

/**
 * DPやるだけだがなぜかwhile(cin >> N >> K, N != 0 && K != 0)
 * としており無限ペナ出した
 * 今までこういうコード書きまくってたので危険に気づけた点では良問
 */
