#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
// clang-format off
template <class T> using V = vector<T>;
// clang-format on

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    // dp[i][j]=i番目まで見ている、部分和としてjを作れる
    V<int> T(N);
    rep(i, N) cin >> T[i];
    int m = *max_element(ALL(T));
    V<V<int>> dp(N + 1, V<int>(m * N + 1, 0));
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, m * N + 1) {
            if (dp[i][j]) {
                dp[i + 1][j] = 1;
                if (j + T[i] <= m * N) dp[i + 1][j + T[i]] = 1;
            }
        }
    }
    int ans = 1 << 30, s = 0;
    rep(i, N) s += T[i];
    rep(j, m * N + 1) if (dp[N][j]) ans = min(ans, max(j, s - j));
    cout << ans << '\n';
    return 0;
}

/**
 * 部分和問題
 */
