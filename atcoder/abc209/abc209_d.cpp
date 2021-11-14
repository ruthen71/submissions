#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

void dfs(vector<vector<int>>& G, vector<int>& dst, int cur, int par) {
    for (auto& nx : G[cur]) {
        if (nx == par) continue;
        dst[nx] = dst[cur] + 1;
        dfs(G, dst, nx, cur);
    }
    return;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dst(N);
    dst[0] = 0;
    dfs(G, dst, 0, -1);
    while (Q--) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        cout << (((dst[c] + dst[d]) % 2 == 1) ? "Road" : "Town") << endl;
    }
    return 0;
}
