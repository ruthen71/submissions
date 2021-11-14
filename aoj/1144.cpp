#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int H, W, ans;

int dfs(vector<vector<int>>& a, int cnt, int cx, int cy) {
    if (ans <= cnt) return 20;
    // 進行方向の決定
    vector<int> vd;
    for (int d = 0; d < 4; d++) {
        int nx = cx + dx[d], ny = cy + dy[d];
        if (!(0 <= nx && nx < H && 0 <= ny && ny < W)) continue;
        if (a[nx][ny] == 1) continue;
        vd.push_back(d);
    }
    int ret = 15;
    for (int d : vd) {
        int nx = cx, ny = cy;
        int ok = 1;
        while (1) {
            if (!(0 <= nx && nx < H && 0 <= ny && ny < W)) {
                // 外に出る
                ok = 0;
                break;
            }
            if (a[nx][ny] == 1) {
                // 障害物にぶつかって止まる
                a[nx][ny] = 0;
                nx -= dx[d], ny -= dy[d];
                break;
            }
            if (a[nx][ny] == 3) {
                return cnt + 1;
            }
            nx += dx[d], ny += dy[d];
        }
        if (ok) {
            int res = dfs(a, cnt + 1, nx, ny);
            ret = min(ret, res);
            a[nx + dx[d]][ny + dy[d]] = 1;
        }
    }
    return ret;
}

void solve(int h, int w) {
    H = h, W = w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> a[i][j];
    int sx, sy, gx, gy;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 2) sx = i, sy = j;
            if (a[i][j] == 3) gx = i, gy = j;
        }
    ans = 10;
    int kai = dfs(a, 0, sx, sy);
    if (kai > 10)
        cout << -1 << endl;
    else
        cout << kai << endl;
    return;
}

int main() {
    int h, w;
    while (cin >> w >> h, h) solve(h, w);
    return 0;
}

/*
最初4^10のbit全探索を書いたらTLEした(テストケースが100個もあった…)
dfsで枝刈すると通る
*/