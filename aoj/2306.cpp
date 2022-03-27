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
    V<V<int>> G(N, V<int>(N, 0));
    rep(i, M) {
        int u, v, f;
        cin >> u >> v >> f;
        u--, v--;
        G[u][v] = G[v][u] = f;
    }
    V<int> S;
    int ans = 0;
    auto rec = [&](auto self, int id) -> void {
        if (S.size() >= 2) {
            int res = 0;
            rep(i, S.size()) {
                int c = 1 << 30;
                rep(j, S.size()) if (i != j) c = min(c, G[S[i]][S[j]]);
                res += c;
            }
            ans = max(ans, res);
        }
        // 次に追加する点を探す
        for (int i = id; i < N; i++) {
            int ok = 1;
            for (auto &si : S) {
                if (G[i][si] == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                S.push_back(i);
                self(self, i + 1);
                S.pop_back();
            }
        }
        return;
    };
    rec(rec, 0);
    cout << ans << '\n';
    return 0;
}

/**
 * 解説AC(2022/02/26)
 * 最大クリーク
 * クリーク全列挙
 * 全探索
 */
