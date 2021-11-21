#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

using mint = modint1000000007;

int N;
vector<int> G[2005];
mint dp[3][2005][2005];
int deg[2005];

void dfs(int cur, int par) {
    dp[0][cur][1] = 1;
    dp[2][cur][0] = 1;
    deg[cur] = 1;
    for (auto &nx : G[cur]) {
        if (nx == par) continue;
        dfs(nx, cur);
        int Msz = deg[cur] + deg[nx];
        vector<vector<mint>> dpn(3, vector<mint>(Msz + 2, 0));
        for (int i = 0; i <= deg[cur]; i++) {
            for (int j = 0; j <= deg[nx]; j++) {
                dpn[0][i + j] += dp[0][cur][i] * dp[0][nx][j];
                dpn[0][i + j] += dp[0][cur][i] * dp[1][nx][j];
                dpn[0][i + j + 1] += dp[0][cur][i] * dp[2][nx][j];
                dpn[1][i + j] += dp[1][cur][i] * dp[0][nx][j];
                dpn[1][i + j] += dp[1][cur][i] * dp[1][nx][j];
                dpn[1][i + j] += dp[1][cur][i] * dp[2][nx][j];
                dpn[1][i + j + 1] += dp[2][cur][i] * dp[0][nx][j];
                dpn[2][i + j] += dp[2][cur][i] * dp[1][nx][j];
                dpn[2][i + j] += dp[2][cur][i] * dp[2][nx][j];
            }
        }
        for (int i = 0; i <= Msz; i++) dp[0][cur][i] = dpn[0][i], dp[1][cur][i] = dpn[1][i], dp[2][cur][i] = dpn[2][i];
        deg[cur] += deg[nx];
    }
    return;
}

int main() {
    cin >> N;
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    for (int i = 0; i <= N; i++) {
        mint ans = dp[0][0][i] + dp[1][0][i] + dp[2][0][i];
        cout << ans.val() << "\n";
    }
    return 0;
}

/*
解説AC
2乗の木DP
木DP
自力でO(N^3)は書けたが、O(N^3)からO(N^2)に落とせないな～とかやっていた
実は枝刈りするとオーダーが落ちる
*/