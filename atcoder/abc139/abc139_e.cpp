#include <bits/stdc++.h>
using namespace std;

vector<int> topological_sort(vector<vector<int>> &G) {
    int N = (int)G.size();
    vector<int> deg(N, 0);
    // 入次数をメモ
    for (int i = 0; i < N; i++) {
        for (int &v : G[i]) deg[v]++;
    }
    // 入次数0の点の集合を作成
    queue<int> que;
    for (int i = 0; i < N; i++) {
        if (deg[i] == 0) que.push(i);
    }
    vector<int> res;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        res.push_back(v);
        for (int &nx : G[v]) {
            // 入次数を減らす
            deg[nx]--;
            // 新たな入次数0の点を追加
            if (deg[nx] == 0) que.push(nx);
        }
    }
    return res;
}

int dag_longest_path_length(vector<vector<int>> &g, vector<int> &topo) {
    if (topo.size() != g.size()) return -1;
    int n = (int)g.size();
    vector<int> dp(n, 0);
    for (int &v : topo) {
        for (int &nx : g[v]) {
            dp[nx] = max(dp[nx], dp[v] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int V = 0;
    vector<vector<int>> f(N, vector<int>(N, -1));
    rep(i, N) rep(j, i) f[i][j] = f[j][i] = V++;
    assert(V == N * (N - 1) / 2);
    vector<vector<int>> g(V);
    rep(i, N) {
        vector<int> A(N - 1);
        rep(j, N - 1) cin >> A[j];
        rep(j, N - 1) A[j]--;
        rep(j, N - 2) { g[f[i][A[j]]].push_back(f[i][A[j + 1]]); }
    }
    vector<int> topo = topological_sort(g);
    int ans = dag_longest_path_length(g, topo);
    if (ans == -1)
        cout << ans << '\n';
    else
        cout << ans + 1 << '\n';
    return 0;
}

/**
 * トポロジカルソートして、DAG上の最長経路を求める
 */
