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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    int s = 0, t = 0;
    rep(i, N) {
        if (a[s] > a[i]) s = i;
        if (a[t] < a[i]) t = i;
    }
    ford_fulkerson<ll> ff(N);
    rep(i, N) {
        rep(j, i) {
            ll g = gcd(a[i], a[j]);
            if (g > 1) {
                ff.add_edge(i, j, g);
                ff.add_edge(j, i, g);
            }
        }
    }
    ll ans = ff.max_flow(s, t);
    cout << ans << '\n';
    return 0;
}

/**
 * 最大流
 * gcd(a[i],a[j])>1となるとき、無向辺を追加して最大流を求める
 */
