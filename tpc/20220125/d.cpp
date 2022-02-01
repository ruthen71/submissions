#include <bits/stdc++.h>
using namespace std;

template <class Cap>
struct ford_fulkerson {
    struct edge {
        int to;
        Cap cap;
        int rev;
    };

    int V;
    vector<vector<edge>> G;
    int timestamp;
    vector<int> used;
    ford_fulkerson(int V) : V(V), G(V), timestamp(0), used(V, -1) {}

    void add_edge(int from, int to, Cap cap) {
        G[from].push_back((edge){to, cap, (int)G[to].size()});
        G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
    }

    Cap max_flow(int s, int t) { return max_flow(s, t, numeric_limits<Cap>::max()); }
    Cap max_flow(int s, int t, Cap flow_limit) {
        Cap flow = 0;
        while (1) {
            Cap f = dfs(s, t, flow_limit);
            if (f == 0) return flow;
            flow += f;
            timestamp++;
        }
    }

    Cap dfs(int v, int t, Cap f) {
        if (v == t) return f;
        used[v] = timestamp;  // seen
        for (auto &e : G[v]) {
            if (e.cap > 0 && used[e.to] != timestamp) {
                Cap d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
};

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const ll INF = 1ll << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<vector<ll>> c(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin >> c[i][j];
    int sx, sy;
    cin >> sx >> sy;
    // グリッドグラフの最小カット<=>最大流
    int V = 2 * H * W;
    int X = V / 2;
    ford_fulkerson<ll> ff(V + 1);
    rep(i, H) {
        rep(j, W) {
            // 頂点のコストを頂点数を倍にして表現する
            ff.add_edge(i * W + j, i * W + j + X, c[i][j]);
            // INFの辺(グリッドグラフ間はいくらでも流せる)
            rep(k, 4) {
                int nx = i + dx[k], ny = j + dy[k];
                if (!(0 <= nx && nx < H && 0 <= ny && ny < W)) continue;
                ff.add_edge(i * W + j + X, nx * W + ny, INF);
            }
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) ff.add_edge(i * W + j + X, V, INF);
        }
    }
    int s = sx * W + sy;
    ll ans = ff.max_flow(s, V);
    cout << ans << '\n';
    return 0;
}

/**
 * 最大流
 * 最小カット
 * (sx,sy)が決められており、いくつかの座標を選んで(sx,sy)を含む領域/含まない領域に分割する
 * 座標にコストが与えられているので、その最小コストを求める
 * 頂点にコストがあるのを頂点倍加して辺にコストがあるとみなし
 * 外の領域をまとめた点(V)を考え、その点と始点とのカットが最小になれば良い
 * グリッドグラフの頂点間は自由に移動できる<=>流量INF
 */
