#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int H, W;
    while (cin >> H >> W) {
        if (H == 0 && W == 0) break;
        vector<string> G(H);
        rep(i, H) cin >> G[i];
        string ans = "";
        rep(x1, H) rep(y1, W) rep(x2, H) rep(y2, W) {
            if (G[x1][y1] != G[x2][y2]) continue;
            rep(k1, 8) rep(k2, 8) {
                if (x1 == x2 && y1 == y2 && k1 == k2) continue;
                int nx1 = (x1 + dx[k1] + H) % H, ny1 = (y1 + dy[k1] + W) % W;
                int nx2 = (x2 + dx[k2] + H) % H, ny2 = (y2 + dy[k2] + W) % W;
                if (G[nx1][ny1] != G[nx2][ny2]) continue;
                string s = "";
                s += G[x1][y1];
                vector<vector<int>> seen1(H, vector<int>(W)), seen2(H, vector<int>(W));
                seen1[x1][y1] = 1;
                seen2[x2][y2] = 1;
                while (G[nx1][ny1] == G[nx2][ny2] && seen1[nx1][ny1] == 0 && seen2[nx2][ny2] == 0) {
                    s += G[nx1][ny1];
                    seen1[nx1][ny1] = 1;
                    seen2[nx2][ny2] = 1;
                    nx1 = (nx1 + dx[k1] + H) % H, ny1 = (ny1 + dy[k1] + W) % W;
                    nx2 = (nx2 + dx[k2] + H) % H, ny2 = (ny2 + dy[k2] + W) % W;
                }
                if (ans.size() == 0)
                    ans = s;
                else if (ans.size() < s.size() || (ans.size() == s.size() && ans > s))
                    ans = s;
            }
        }
        if (ans.size() == 0)
            cout << 0 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}

/**
 * 実装大変系と思いきやそこまで大変でもない
 * 始点のペア全探索かつ方向のペア全探索
 * 読解が一番大変
 */
