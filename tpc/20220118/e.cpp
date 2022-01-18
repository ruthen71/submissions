#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int M = 400;

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

void solve() {
    int S;
    cin >> S;
    vector<vector<int>> G(M), Gb(M);
    vector<int> end(M, 0);
    rep(i, S) {
        int v;
        cin >> v;
        v--;
        string s;
        cin >> s;
        if (s == "favourably") {
            end[v] = 1;
        } else if (s == "catastrophically") {
            end[v] = 2;
        } else {
            int u1 = stoi(s);
            int u2, u3;
            cin >> u2 >> u3;
            u1--, u2--, u3--;
            G[v].push_back(u1);
            G[v].push_back(u2);
            G[v].push_back(u3);
            Gb[u1].push_back(v);
            Gb[u2].push_back(v);
            Gb[u3].push_back(v);
        }
    }
    vector<int> tsort = topological_sort(G);
    vector<ll> dp(M, 0);
    for (int i = M - 1; i >= 0; i--) {
        int v = tsort[i];
        if (end[v] == 2) continue;
        if (end[v] == 1) {
            dp[v] = 1;
        }
        for (auto &pre : Gb[v]) dp[pre] += dp[v];
    }
    cout << dp[0] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}

/**
 * トポロジカルソートして終わりの方からDPする
 */
