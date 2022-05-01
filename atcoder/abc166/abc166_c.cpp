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
    int N, M;
    cin >> N >> M;
    V<int> H(N);
    rep(i, N) cin >> H[i];
    V<V<int>> G(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;
    rep(i, N) {
        int ok = 1;
        for (auto &v : G[i]) {
            if (H[v] >= H[i]) {
                ok = 0;
            }
        }
        ans += ok;
    }
    cout << ans << '\n';
    return 0;
}
