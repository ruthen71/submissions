#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void dfs(int cur, int par, vector<int> &per, vector<int> &d, vector<vector<int>> &G) {
    if (par != -1) d[cur] = d[par] + 1;
    per.push_back(cur);
    for (auto &nx : G[cur]) dfs(nx, cur, per, d, G);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<string> S(N);
    rep(i, N) {
        int k;
        cin >> k >> S[i];
        k--;
        if (k == -1) continue;
        G[k].push_back(i);
    }
    vector<int> per, d(N, 0);
    dfs(0, -1, per, d, G);
    for (auto &pi : per) {
        rep(i, d[pi]) cout << ".";
        cout << S[pi] << '\n';
    }
    return 0;
}

/**
 * DFSで頑張る
 * perに保存しなくてもdfs()内で出力すればOK
 */
