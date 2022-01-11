#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int N = 3;

void solve() {
    vector<vector<int>> a(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> a[i][j];
    int ans = 1000;
    rep(b, 1 << 18) {
        int c = 0, cur = 0;
        vector<vector<int>> a2 = a;
        rep(i, N) rep(j, N) {
            int inc = (b >> (2 * c) & 3);
            cur += inc;
            rep(x, N) a2[x][j] += inc;
            rep(y, N) a2[i][y] += inc;
            a2[i][j] -= inc;
            c++;
        }
        int ok = 1;
        rep(i, N) rep(j, N) if (a2[i][j] % 4 != 0) ok = 0;
        if (ok) ans = min(ans, cur);
    }
    cout << (ans == 1000 ? -1 : ans) << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

/**
 * bit全探索
 * 各マスについて0~3回のうちひっくり返す回数を全探索する
 */
