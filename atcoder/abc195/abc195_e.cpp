#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    string S, X;
    cin >> N >> S >> X;
    V<V<int>> dp(N + 1, V<int>(7, 0));
    dp[N][0] = 1;
    // 1...Takahashi君の勝ち
    // 0...Aoki君の勝ち
    for (int i = N - 1; i >= 0; i--) {
        // calc dp[i]
        if (X[i] == 'T') {
            // Takahashi
            rep(j, 7) {
                if (dp[i + 1][(10 * j + S[i] - '0') % 7] || dp[i + 1][(10 * j) % 7]) dp[i][j] = 1;
            }
        } else {
            // Aoki
            rep(j, 7) {
                if (dp[i + 1][(10 * j + S[i] - '0') % 7] && dp[i + 1][(10 * j) % 7]) dp[i][j] = 1;
            }
        }
    }
    cout << (dp[0][0] ? "Takahashi" : "Aoki") << '\n';
    return 0;
}