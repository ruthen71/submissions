#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

using mint = modint1000000007;

mint ans;
int N, K;
vector<int> g[100005];

void dfs(int cur, int par) {
    int rem = K - 2;
    if (par == -1) rem++;
    for (auto &nx : g[cur]) {
        if (nx != par) {
            ans *= max(0, rem);
            rem--;
            dfs(nx, cur);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans = K;
    dfs(0, -1);
    cout << ans.val() << '\n';
    return 0;
}

/**
 * 帰りがけではなく、行きがけに色を塗っていく
 */
