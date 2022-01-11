#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int INF = 1 << 30;

void dfs(vector<vector<int>>& G, int cur, int par, vector<int>& d) {
    for (int& nx : G[cur]) {
        if (par != nx) {
            d[nx] = d[cur] + 1;
            dfs(G, nx, cur, d);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, u, v;
    cin >> N >> u >> v;
    vector<vector<int>> G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> d1(N, INF), d2(N, INF);
    u--, v--;
    d1[u] = 0, d2[v] = 0;
    dfs(G, u, -1, d1);
    dfs(G, v, -1, d2);
    int ans = 0, ans2 = INF;
    rep(i, N) {
        /*
        // これ必要な気がするけどなぜかコメントアウトすると通る
        if (d1[i] == d2[i] + 1) {
            ans = max(ans, d2[i]);
            continue;
        }
        */
        if (d1[i] == d2[i]) {
            ans2 = min(ans2, d2[i]);
            continue;
        }
        if (d1[i] > d2[i]) continue;
        if (G[i].size() == 1) continue;
        ans = max(ans, d2[i]);
    }
    if (ans2 != INF) ans = max(ans, ans2);
    cout << ans << '\n';
    return 0;
}

/**
 * tree
 * after contest
 * DFS
 * BFS
 * 木上の移動
 * 後日に追加されたテストケースに引っかかった
 * 基本的には高橋君が先に到達できる頂点のうち、青木君にとって最も遠いもの
 * ただし、葉以外
 * また、距離が同じものの扱いに気を付ける
 */