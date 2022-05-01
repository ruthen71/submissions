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
    cin >> N;
    string S;
    cin >> S;
    V<V<int>> dp(N + 1, V<int>(N + 1, 0));
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (S[i] == S[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
        }
    }
    int ans = 0;
    rep(i, N) rep(j, i) ans = max(ans, min(dp[i][j], i - j));
    cout << ans << '\n';
    return 0;
}
/**
 * DP配列の持ち方がLCSっぽい
 */