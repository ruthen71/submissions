#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }
    int ans = N;
    rep(i, N) {
        queue<int> que;
        que.push(i);
        vector<int> seen(N, 0);
        seen[i] = 1;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &nx : G[v]) {
                if (seen[nx] == 0) {
                    seen[nx] = 1;
                    que.push(nx);
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

/**
 * BFSの例題
 */