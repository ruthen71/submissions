#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int INF = 1 << 30;

void solve(int w, int h) {
    vector<vector<int>> s(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> s[i][j];
    vector<int> c(4);
    cin >> c[0] >> c[1] >> c[2] >> c[3];
    int V = h * w * 4;
    vector<vector<pair<int, int>>> g(V);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < 4; k++) {
                // 点(i,j)にいて、kの方向を向いている
                for (int l = 0; l < 4; l++) {
                    // l=0:直進,l=1:右折,l=2:反転,l=3:左折
                    int cost = c[l];
                    if (s[i][j] == l) cost = 0;
                    int nx = i + dx[(k + l) % 4], ny = j + dy[(k + l) % 4];
                    if (0 <= nx && nx < h && 0 <= ny && ny < w) {
                        g[i * w * 4 + j * 4 + k].push_back({nx * w * 4 + ny * 4 + (k + l) % 4, cost});
                    }
                }
            }
        }
    }
    vector<int> dist(V, INF);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, 0});
    while (!que.empty()) {
        int v = que.top().second, d = que.top().first;
        que.pop();
        if (dist[v] < d) continue;
        for (auto &e : g[v]) {
            if (dist[e.first] > dist[v] + e.second) {
                dist[e.first] = dist[v] + e.second;
                que.push({dist[e.first], e.first});
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, dist[(h - 1) * w * 4 + (w - 1) * 4 + i]);
    }
    cout << ans << endl;
    return;
}

int main() {
    int w, h;
    while (cin >> w >> h, w) solve(w, h);
    return 0;
}

/*
(i,j)にいてkの方向を向いている、とすると、同じ頂点に来る必要はないのでダイクストラできる
(方向も持たない場合、同じ頂点に来た方が良いこともある)
各頂点から生えている辺を前計算したが、別にしなくても良かった
*/
