#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    V<int> A(N);
    rep(i, N) cin >> A[i];
    V<V<int>> G(N);
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    V<int> dp(N, 1 << 30), ans(N, -1);
    auto dfs = [&](auto f, int cur, int par) -> void {
        int ind = lower_bound(dp.begin(), dp.end(), A[cur]) - dp.begin();
        int a = dp[ind];
        dp[ind] = A[cur];
        ans[cur] = lower_bound(dp.begin(), dp.end(), 1 << 30) - dp.begin();
        for (auto &nex : G[cur]) {
            if (nex == par) continue;
            f(f, nex, cur);
        }
        dp[ind] = a;
        return;
    };
    dfs(dfs, 0, -1);
    rep(i, N) cout << ans[i] << '\n';
    return 0;
}
