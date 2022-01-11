#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int INF = 1 << 30;

const int dx[9] = {2, 1, 1, 0, 0, 0, -1, -1, -2};
const int dy[9] = {1, 1, 2, 1, 2, 3, 1, 2, 1};

void solve(int H, int W) {
    vector<vector<int>> cost(H, vector<int>(W));
    vector<pair<int, int>> S, T;
    rep(i, H) rep(j, W) {
        char c;
        cin >> c;
        if ('1' <= c && c <= '9') {
            cost[i][j] = c - '0';
        } else if (c == 'X') {
            cost[i][j] = INF;
        } else if (c == 'S') {
            cost[i][j] = 0;
            S.push_back({i, j});
        } else {
            cost[i][j] = 0;
            T.push_back({i, j});
        }
    }
    vector<vector<vector<int>>> dist(2, vector<vector<int>>(H, vector<int>(W, INF)));
    // dist[i][x][y] = 今(x,y)に左足(i=0),右足(i=1)を置いている
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    for (auto s : S) {
        dist[0][s.first][s.second] = 0;
        dist[1][s.first][s.second] = 0;
        pq.push({0, 0, s.first, s.second});
        pq.push({0, 1, s.first, s.second});
    }
    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        // cout << "v=" << get<0>(v) << "," << get<1>(v) << "," << get<2>(v) << "," << get<3>(v) << '\n';
        int d = get<0>(v), c = (get<1>(v) == 0) ? 1 : -1, cx = get<2>(v), cy = get<3>(v);
        rep(i, 9) {
            int nx = cx + dx[i], ny = cy + c * dy[i];
            if (!(0 <= nx && nx < H && 0 <= ny && ny < W)) continue;
            // cout << "(" << cx << "," << cy << ")->(" << nx << "," << ny << ")\n";
            if (cost[nx][ny] == INF) continue;
            if (dist[1 - get<1>(v)][nx][ny] > d + cost[nx][ny]) {
                dist[1 - get<1>(v)][nx][ny] = d + cost[nx][ny];
                pq.push({d + cost[nx][ny], 1 - get<1>(v), nx, ny});
            }
        }
    }
    int ans = INF;
    for (auto t : T) {
        ans = min(ans, dist[0][t.first][t.second]);
        ans = min(ans, dist[1][t.first][t.second]);
    }
    cout << (ans == INF ? -1 : ans) << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    while (cin >> W >> H, H || W) solve(H, W);
    return 0;
}

/**
 * Dijkstra法
 * (x,y)をどっちの足で踏んでいるかでダイクストラ法する
 */
