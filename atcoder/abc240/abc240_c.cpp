#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) begin(x), end(x)
template <class T> using V = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, X;
    cin >> N >> X;
    V<V<int>> dp(N + 1, V<int>(10005, 0));
    dp[0][0] = 1;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        rep(j, 10005) {
            if (dp[i][j]) {
                if (j + a < 10005) dp[i + 1][j + a] = 1;
                if (j + b < 10005) dp[i + 1][j + b] = 1;
            }
        }
    }
    cout << (dp[N][X] ? "Yes" : "No") << '\n';
    return 0;
}

/**
 * dp[i][j]=i回目の移動後にjにいることができるか
 * でDPする
 */
