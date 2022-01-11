#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int K = 0;
vector<int> G[100005];
int ans[100005];
map<pair<int, int>, int> id;

void dfs(int cur, int par) {
    int used;
    if (par == -1) {
        used = -1;
    } else {
        used = ans[id[make_pair(min(cur, par), max(cur, par))]];
    }
    int col = 0;
    for (auto nx : G[cur]) {
        if (nx == par) continue;
        if (col == used) col++;
        ans[id[make_pair(min(cur, nx), max(cur, nx))]] = col++;
        dfs(nx, cur);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> deg(N, 0), a(N - 1), b(N - 1);
    rep(i, N - 1) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
        id[make_pair(a[i], b[i])] = i;
        deg[a[i]]++, deg[b[i]]++;
    }
    rep(i, N) K = max(K, deg[i]);
    dfs(0, -1);
    cout << K << '\n';
    rep(i, N - 1) cout << ans[i] + 1 << '\n';
    return 0;
}

/**
 * 必要条件としてK>=次数の最大値
 * だが、DFSで塗っていくことを考えるとこれは十分条件になっている
 */
