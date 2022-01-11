#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int INF = 1 << 30;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int dist[4][4][1000][1000];

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    int sx, sy, gx, gy;
    rep(i, H) rep(j, W) {
        if (S[i][j] == 'R') sx = i, sy = j, S[i][j] = '.';
        if (S[i][j] == 'D') gx = i, gy = j, S[i][j] = '.';
    }
    rep(i, H) rep(j, W) rep(k1, 4) rep(k2, 4) dist[k1][k2][i][j] = INF;
    queue<tuple<int, int, int, int>> que;
    rep(k1, 4) rep(k2, 4) {
        dist[k1][k2][sx][sy] = 0;
        que.push({k1, k2, sx, sy});
    }
    while (!que.empty()) {
        auto tup = que.front();
        que.pop();
        int k1 = get<0>(tup), k2 = get<1>(tup), cx = get<2>(tup), cy = get<3>(tup);
        rep(k, 4) {
            if (k == (k2 + 2) % 4) continue;
            if (k1 == k2 && k == k1) continue;
            int nx = cx + dx[k], ny = cy + dy[k];
            if (!(0 <= nx && nx < H && 0 <= ny && ny < W)) continue;
            if (S[nx][ny] == 'B') continue;
            if (dist[k2][k][nx][ny] != INF) continue;
            dist[k2][k][nx][ny] = dist[k1][k2][cx][cy] + 1;
            que.push({k2, k, nx, ny});
        }
    }
    int ans = INF;
    rep(k1, 4) rep(k2, 4) ans = min(ans, dist[k1][k2][gx][gy]);
    cout << (ans == INF ? -1 : ans) << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}

/**
 * 直近2回分の移動履歴を持ってBFSする
 */
