#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1ll << 60;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve(ll w, ll h) {
    vector<string> g(h);
    for (int i = 0; i < h; i++) cin >> g[i];
    ll c = 0, sx, sy;
    vector<vector<ll>> pol(h, vector<ll>(w, -1));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] == '*') pol[i][j] = c++;
            if (g[i][j] == 'o') sx = i, sy = j;
        }
    }
    ll c2 = (1 << c);
    vector<vector<vector<ll>>> dist(h, vector<vector<ll>>(w, vector<ll>(c2, INF)));
    dist[sx][sy][0] = 0;
    queue<ll> que;
    que.push((sx * w + sy) * c2);
    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        ll coo = v / c2, bit = v % c2;
        ll cx = coo / w, cy = coo % w;
        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (!(0 <= nx && nx < h && 0 <= ny && ny < w)) continue;
            if (g[nx][ny] == 'x') continue;
            ll nbit = bit;
            if (g[nx][ny] == '*') {
                int id = pol[nx][ny];
                nbit |= (1 << id);
            }
            if (dist[nx][ny][nbit] > dist[cx][cy][bit] + 1) {
                dist[nx][ny][nbit] = dist[cx][cy][bit] + 1;
                que.push((nx * w + ny) * c2 + nbit);
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans = min(ans, dist[i][j][c2 - 1]);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return;
}

int main() {
    ll w, h;
    while (cin >> w >> h, w) solve(w, h);
}

/*
bitDP+BFSしたが、実際にはnext_permutationで良かった
*/
