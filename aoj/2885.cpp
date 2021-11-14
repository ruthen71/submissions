#include <bits/stdc++.h>
using namespace std;

int ok;

void dfs(vector<vector<int>>& g, vector<int>& col, int cur, int par, int c) {
    if (col[cur] != -1 && col[cur] != c) {
        ok = 0;
        return;
    }
    if (col[cur] != -1) return;
    col[cur] = c;
    for (auto& nx : g[cur]) {
        if (nx == par) continue;
        dfs(g, col, nx, cur, 1 - c);
    }
    return;
}

void solve(int N, int M) {
    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> col(N, -1);
    ok = 1;
    dfs(g, col, 0, -1, 0);
    if (ok == 0) {
        cout << "0\n";
        return;
    }
    vector<int> cnt(2, 0);
    for (int i = 0; i < N; i++) cnt[col[i]]++;
    vector<int> ans;
    for (int i = 0; i < 2; i++) {
        if (cnt[i] % 2 == 0) {
            ans.push_back(cnt[i] / 2);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for (auto ansi : ans) {
        cout << ansi << '\n';
    }
    return;
}

int main() {
    int N, M;
    while (cin >> N >> M, N) solve(N, M);
    return 0;
}

/*
太郎、花子、次郎について、隣接してOKな関係を図に書いてみると
太郎と花子をまとめて考えた二部グラフ塗り分け問題になる
*/
