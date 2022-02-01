#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> sx(N), sy(N), tx(N), ty(N);
    rep(i, N) cin >> sx[i] >> sy[i];
    rep(i, N) cin >> tx[i] >> ty[i];
    ll ok = 1ll << 40, ng = -1;
    while (ok - ng > 1) {
        ll K = (ok + ng) / 2;
        ford_fulkerson<int> ff(2 * N + 2);
        rep(i, N) {
            rep(j, N) {
                ll d = abs(sx[i] - tx[j]) + abs(sy[i] - ty[j]);
                if (d <= K) {
                    ff.add_edge(i + 1, j + N + 1, 1);
                }
            }
        }
        rep(i, N) {
            ff.add_edge(0, i + 1, 1);
            ff.add_edge(i + N + 1, 2 * N + 1, 1);
        }
        if (ff.max_flow(0, 2 * N + 1) == N)
            ok = K;
        else
            ng = K;
    }
    cout << ok << '\n';
    return 0;
}

/**
 * 二分探索+二部マッチング
 */