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
    ll N, K;
    cin >> N >> K;
    V<ll> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    V<V<int>> dp(N, V<int>(2, 0));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < N; i++) {
        if (dp[i - 1][0] && abs(A[i] - A[i - 1]) <= K) dp[i][0] = 1;
        if (dp[i - 1][0] && abs(B[i] - A[i - 1]) <= K) dp[i][1] = 1;
        if (dp[i - 1][1] && abs(A[i] - B[i - 1]) <= K) dp[i][0] = 1;
        if (dp[i - 1][1] && abs(B[i] - B[i - 1]) <= K) dp[i][1] = 1;
    }
    cout << (dp[N - 1][0] || dp[N - 1][1] ? "Yes" : "No") << '\n';
    return 0;
}