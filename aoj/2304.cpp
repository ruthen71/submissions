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

map<pair<int, int>, int> id;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> u(M), v(M);
    rep(i, M) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        id[{u[i], v[i]}] = i + 1;
    }
    int s, t;
    cin >> s >> t;
    s--, t--;
    ford_fulkerson<int> ff(N);
    rep(i, M) {
        ff.add_edge(u[i], v[i], 1);
        ff.add_edge(v[i], u[i], 1);
    }
    int ans = ff.max_flow(s, t);
    set<int> S;
    rep(i, N) {
        for (auto &p : ff.G[i]) {
            if (p.cap == 0) {
                // cap=0ということはその辺には流れている
                if (id[{i, p.to}] == 0) {
                    // id[{i, p.to}]=0ということはその辺はもともとの向きではない
                    // そしてid[{p.to, i}]は必ず番号がある
                    S.insert(id[{p.to, i}]);
                }
            }
        }
    }
    cout << ans << '\n';
    cout << S.size() << '\n';
    for (auto &si : S) cout << si << '\n';
    return 0;
}

/**
 * 最大流
 * 復元
 * 双方向に辺を張り、流して、結果のcapを見る
 */
