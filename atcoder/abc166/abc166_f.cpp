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
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    V<string> S(N);
    rep(i, N) cin >> S[i];
    A = min(A, 3);
    B = min(B, 3);
    C = min(C, 3);
    V<V<V<V<int>>>> dp(N + 1, V<V<V<int>>>(4, V<V<int>>(4, V<int>(4, 0))));
    using tp = tuple<int, int, int>;
    V<V<V<V<tp>>>> cf(N + 1, V<V<V<tp>>>(4, V<V<tp>>(4, V<tp>(4))));
    dp[0][A][B][C] = 1;
    rep(i, N) {
        rep(a, 4) {
            rep(b, 4) {
                rep(c, 4) {
                    if (dp[i][a][b][c] == 0) continue;
                    if (S[i] == "AB") {
                        if (a > 0) {
                            dp[i + 1][a - 1][min(b + 1, 3)][c] = 1;
                            cf[i + 1][a - 1][min(b + 1, 3)][c] = {a, b, c};
                        }
                        if (b > 0) {
                            dp[i + 1][min(a + 1, 3)][b - 1][c] = 1;
                            cf[i + 1][min(a + 1, 3)][b - 1][c] = {a, b, c};
                        }
                    } else if (S[i] == "BC") {
                        if (b > 0) {
                            dp[i + 1][a][b - 1][min(c + 1, 3)] = 1;
                            cf[i + 1][a][b - 1][min(c + 1, 3)] = {a, b, c};
                        }
                        if (c > 0) {
                            dp[i + 1][a][min(b + 1, 3)][c - 1] = 1;
                            cf[i + 1][a][min(b + 1, 3)][c - 1] = {a, b, c};
                        }
                    } else {
                        if (a > 0) {
                            dp[i + 1][a - 1][b][min(c + 1, 3)] = 1;
                            cf[i + 1][a - 1][b][min(c + 1, 3)] = {a, b, c};
                        }
                        if (c > 0) {
                            dp[i + 1][min(a + 1, 3)][b][c - 1] = 1;
                            cf[i + 1][min(a + 1, 3)][b][c - 1] = {a, b, c};
                        }
                    }
                }
            }
        }
    }
    int sa = -1, sb = -1, sc = -1;
    rep(a, 4) rep(b, 4) rep(c, 4) {
        if (dp[N][a][b][c]) {
            sa = a, sb = b, sc = c;
        }
    }
    if (sa == -1) {
        cout << "No" << '\n';
        return 0;
    }
    V<char> ans;
    for (int i = N; i > 0; i--) {
        auto [na, nb, nc] = cf[i][sa][sb][sc];
        if (S[i - 1] == "AB") {
            if (na == sa + 1) {
                ans.push_back('B');
            } else {
                ans.push_back('A');
            }
        } else if (S[i - 1] == "BC") {
            if (nb == sb + 1) {
                ans.push_back('C');
            } else {
                ans.push_back('B');
            }
        } else {
            if (na == sa + 1) {
                ans.push_back('C');
            } else {
                ans.push_back('A');
            }
        }
        sa = na, sb = nb, sc = nc;
    }
    reverse(ans.begin(), ans.end());
    cout << "Yes" << '\n';
    rep(i, N) cout << ans[i] << '\n';
    return 0;
}

/**
 * 多すぎたら適当に上限を定めることでDPできる
 * 1,1,1あれば確実に終わらせられるので各山に3つまでとして良いのでdp[N][4][4][4]になった
 * しかし実は1,1,0でも良いらしい
 */
