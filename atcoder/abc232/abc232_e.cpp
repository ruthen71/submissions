#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

using mint = modint998244353;

mint dp[1000005][5][5];

int main() {
    ll H, W, K;
    cin >> H >> W >> K;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    // x1<=x2, y1<=y2が保証
    vector<ll> a = {x1, 1};
    ll sx = 1, sy = 1, gx, gy;
    if (x1 == x2) {
        gx = 1;
    } else {
        gx = 3;
        a.push_back(x2 - x1 - 1);
        a.push_back(1);
    }
    a.push_back(H - x2 - 1);
    vector<ll> b = {y1, 1};
    if (y1 == y2) {
        gy = 1;
    } else {
        gy = 3;
        b.push_back(y2 - y1 - 1);
        b.push_back(1);
    }
    b.push_back(W - y2 - 1);
    int h = a.size(), w = b.size();
    dp[0][sx][sy] = 1;
    rep(k, K) {
        rep(i, h) {
            rep(j, w) {
                rep(ii, h) {
                    if (i == ii) {
                        dp[k + 1][ii][j] += max(0ll, a[ii] - 1) * dp[k][i][j];
                    } else {
                        dp[k + 1][ii][j] += a[ii] * dp[k][i][j];
                    }
                }
                rep(jj, w) {
                    if (j == jj) {
                        dp[k + 1][i][jj] += max(0ll, b[jj] - 1) * dp[k][i][j];
                    } else {
                        dp[k + 1][i][jj] += b[jj] * dp[k][i][j];
                    }
                    if (j == jj) continue;
                }
            }
        }
    }
    cout << dp[K][gx][gy].val() << '\n';
    return 0;
}

/**
 * dp
 * DP
 * 実は状態は4つにまとめられる(上記のコードは最大25状態)
 * 終点から見ると何が同じ状態なのか、みたいな話になって、4状態になるというのが思いつくかも
 * そこまで遷移を簡単にできるので行列累乗も見えてくる
 */