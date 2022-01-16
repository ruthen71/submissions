#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    int ans = 0;
    rep(sx, H) {
        rep(sy, W) {
            if (S[sx][sy] == '#') continue;
            vector<vector<int>> d(H, vector<int>(W, 1000));
            d[sx][sy] = 0;
            queue<pair<int, int>> que;
            que.push({sx, sy});
            while (!que.empty()) {
                auto p = que.front();
                que.pop();
                rep(k, 4) {
                    int nx = p.first + dx[k], ny = p.second + dy[k];
                    if (!(0 <= nx && nx < H && 0 <= ny && ny < W)) continue;
                    if (S[nx][ny] == '#') continue;
                    if (d[nx][ny] != 1000) continue;
                    d[nx][ny] = d[p.first][p.second] + 1;
                    que.push({nx, ny});
                }
            }
            rep(i, H) rep(j, W) if (d[i][j] != 1000) ans = max(ans, d[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 全点からBFSする
 */
