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
    int N, M, Q;
    cin >> N >> M >> Q;
    V<ll> w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];
    V<ll> X(M);
    rep(i, M) cin >> X[i];
    while (Q--) {
        int L, R;
        cin >> L >> R;
        L--;
        V<ll> xs;
        for (int i = 0; i < L; i++) xs.push_back(X[i]);
        for (int i = R; i < M; i++) xs.push_back(X[i]);
        sort(xs.begin(), xs.end());
        V<int> used(N, 0);
        ll ans = 0;
        for (auto &x : xs) {
            int ind = -1;
            rep(i, N) {
                if (used[i]) continue;
                if (x >= w[i]) {
                    if (ind == -1)
                        ind = i;
                    else if (v[ind] < v[i])
                        ind = i;
                }
            }
            if (ind == -1) continue;
            used[ind] = 1;
            ans += v[ind];
        }
        cout << ans << '\n';
    }
    return 0;
}