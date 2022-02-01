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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N;
    cin >> N >> M;
    vector<string> s(N);
    int id = 0;
    vector<vector<int>> ok(N, vector<int>(M, 0));
    rep(i, N) {
        cin >> s[i];
        int k;
        cin >> k;
        rep(j, k) {
            int d;
            cin >> d;
            d--;
            ok[i][d] = 1;
        }
    }
    // 答えを決め打ち
    for (int x = 1; x <= M; x++) {
        int V = N + M + 2;
        ford_fulkerson<int> ff(V);
        rep(i, N) ff.add_edge(0, 1 + i, x);
        rep(i, N) {
            rep(k, M) {
                if (ok[i][k]) {
                    ff.add_edge(1 + i, N + 1 + k, 1);
                }
            }
        }
        rep(k, M) ff.add_edge(N + 1 + k, V - 1, 2);
        int ans = ff.max_flow(0, V - 1);
        if (ans == 2 * M) {
            vector<vector<int>> ans(M);
            for (int i = 1; i <= N; i++) {
                for (auto &es : ff.G[i]) {
                    if (es.cap == 0 && es.to >= N + 1) {
                        ans[es.to - N - 1].push_back(i - 1);
                    }
                }
            }
            cout << x << '\n';
            rep(i, M) cout << "Day " << i + 1 << ": " << s[ans[i][0]] << " " << s[ans[i][1]] << '\n';
            return 0;
        }
    }
    return 0;
}

/**
 * 最大流
 * マッチング
 * 答えを決め打つと見通しが良くなる
 * x日でできるとすると
 * 始点から人間1~Nまでにそれぞれ容量xの辺を
 * 人間iからその人間ができる仕事jに対して容量1の辺を
 * 仕事jから終点に容量2の辺を張る
 * そして最大流を解いて使われた辺を復元する
 */
