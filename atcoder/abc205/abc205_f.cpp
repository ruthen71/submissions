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

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    int V = H + 2 * N + W + 2;
    ford_fulkerson<int> mf(V);
    for (int i = 1; i <= H; i++) mf.add_edge(0, i, 1);
    for (int j = 1; j <= W; j++) mf.add_edge(H + 2 * N + j, H + 2 * N + W + 1, 1);
    for (int i = 1; i <= N; i++) mf.add_edge(H + i, H + N + i, 1);
    for (int i = 1; i <= N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j <= c; j++) mf.add_edge(j, H + i, 1);
        for (int j = b; j <= d; j++) mf.add_edge(H + N + i, H + 2 * N + j, 1);
    }
    int ans = mf.max_flow(0, V - 1);
    cout << ans << '\n';
    return 0;
}

/**
 * 解説AC
 * 最大流問題
 * マッチング
 * 割と典型
 * まず、簡単な問題を考える
 * グリッドから同じ行と列に置かないようにするだけ(答えはmin{H,W})なら
 * 2部マッチング的に解ける
 * さらに領域の指定が入るので、選んだH,Wの中から高々1つしか流れない条件を
 * HとWの間に流量制限付き頂点を追加することで実現
 * 流量制限付き頂点=頂点倍加(蟻本p192の下のほう)
 */