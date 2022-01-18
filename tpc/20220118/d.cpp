#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ll INF = 1ll << 60;
ll C, n1, n5, n10, S;

ll memo[51][151][701];

ll rec(ll a, ll b, ll c) {
    if (S - (10 * a + 5 * b + c) == 8 * C) return 0;
    if (memo[a][b][c] != -1) return memo[a][b][c];
    ll ret = INF;
    // (0,0,8)
    if (c >= 8) ret = min(ret, rec(a, b, c - 8) + 8);
    // (0,1,3)
    if (b >= 1 && c >= 3) ret = min(ret, rec(a, b - 1, c - 3) + 4);
    // (0,2,0)->(0,0,2)
    if (b >= 2) ret = min(ret, rec(a, b - 2, c + 2) + 2);
    // (1,0,0)->(0,0,2)
    if (a >= 1) ret = min(ret, rec(a - 1, b, c + 2) + 1);
    // (1,0,3)->(0,1,0)
    if (a >= 1 && c >= 3) ret = min(ret, rec(a - 1, b + 1, c - 3) + 4);
    return memo[a][b][c] = ret;
}

void solve() {
    cin >> C >> n1 >> n5 >> n10;
    assert(C <= n1 + 5 * n5 + 10 * n10);
    rep(i, 51) rep(j, 151) rep(k, 701) memo[i][j][k] = -1;
    // メモ化再帰
    S = n1 + 5 * n5 + 10 * n10;
    ll ans = rec(n10, n5, n1);
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // 支払う可能性のある組み合わせを調べる
    /*
    for (int n10 = 0; n10 <= 1; n10++) {
        for (int n5 = 0; n5 <= 2; n5++) {
            for (int n1 = 0; n1 <= 8; n1++) {
                if (n1 + 5 * n5 + 10 * n10 < 8) continue;
                int m = 0;
                if (n1) m = 1;
                if (n5) m = 5;
                if (n10) m = 10;
                if (n1 + 5 * n5 + 10 * n10 - m < 8) printf("n10=%d,n5=%d,n1=%d\n", n10, n5, n1);
            }
        }
    }
    */
    // さらに支払いと返金に同じ小銭が入っているやつは除外すると
    // 払い方は(n10,n5,n1)=(0,0,8),(0,1,3),(0,2,0),(1,0,0),(1,0,3)があることが判明
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}

/**
 * メモ化再帰
 * 13円払って5円玉を貰うというパターンに気づくのが難しい
 */
