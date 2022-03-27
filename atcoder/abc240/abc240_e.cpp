#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) begin(x), end(x)
template <class T> using V = vector<T>;

const int INF = 1 << 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    V<V<int>> G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    V<int> L(N, INF), R(N, -INF);
    int c = 0;
    auto rec = [&](auto self, int cur, int par) -> int {
        if (G[cur].size() == 1 && cur != 0) {
            L[cur] = R[cur] = c++;
            return 0;
        }
        for (auto &nx : G[cur]) {
            if (nx == par) continue;
            self(self, nx, cur);
            L[cur] = min(L[cur], L[nx]);
            R[cur] = max(R[cur], R[nx]);
        }
        return 0;
    };
    rec(rec, 0, -1);
    rep(i, N) cout << L[i] + 1 << ' ' << R[i] + 1 << '\n';
    return 0;
}

/**
 * DFSやる
 * 問題文が難しいが、根以外の葉に1つの整数の区間を割り当てて、親は子の区間を併合するイメージで良い
 */
