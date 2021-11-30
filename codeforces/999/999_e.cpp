#include <bits/stdc++.h>
using namespace std;

#include <atcoder/scc>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

void dfs(vector<vector<int>> &g, int cur, vector<int> &seen) {
    seen[cur] = 1;
    for (auto &nx : g[cur]) {
        if (seen[nx]) continue;
        dfs(g, nx, seen);
    }
    return;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vector<int>> g(n);
    scc_graph g2(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g2.add_edge(a, b);
    }
    vector<vector<int>> sccres = g2.scc();
    vector<int> id(n);
    rep(i, sccres.size()) {
        for (auto p : sccres[i]) id[p] = i;
    }
    vector<int> seen(n, 0);
    dfs(g, s, seen);
    int ans = 0;
    rep(i, sccres.size()) {
        if (seen[sccres[i][0]]) continue;
        ans++;
        dfs(g, sccres[i][0], seen);
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 強連結成分分解
 * DAG
 * トポロジカルソート
 * 強連結成分分解をし、まず始点sからいけるところを消す
 * その後、DAGで前にある点集合から順に、ans++し、
 * 「その点集合に行けるようにしたときにいけるところを消す」を繰り返す
 */