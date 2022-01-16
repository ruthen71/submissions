#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void solve(int N) {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> G(H, vector<int>(W, 0));
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        G[x][y]++;
    }
    int S, T;
    cin >> S >> T;
    vector<vector<int>> cum(H + 1, vector<int>(W + 1, 0));
    rep(i, H) rep(j, W) { cum[i + 1][j + 1] = cum[i + 1][j] + cum[i][j + 1] - cum[i][j] + G[i][j]; }
    int ans = 0;
    for (int i = 0; i < H - S + 1; i++) {
        for (int j = 0; j < W - T + 1; j++) {
            ans = max(ans, cum[i + S][j + T] - cum[i][j + T] - cum[i + S][j] + cum[i][j]);
        }
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while (cin >> N, N) solve(N);
    return 0;
}

/**
 * 二次元累積和
 */
