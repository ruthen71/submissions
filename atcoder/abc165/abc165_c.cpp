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
    V<int> A(Q), B(Q), C(Q), D(Q);
    rep(i, Q) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        A[i]--, B[i]--;
    }
    V<int> a;
    ll ans = 0;
    auto rec = [&](auto f) -> void {
        if (a.size() == N) {
            ll cur = 0;
            rep(i, Q) {
                if (a[B[i]] - a[A[i]] == C[i]) cur += D[i];
            }
            ans = max(ans, cur);
            return;
        }
        int m = (a.size() > 0 ? a.back() : 1);
        for (int i = m; i <= M; i++) {
            a.push_back(i);
            f(f);
            a.pop_back();
        }
        return;
    };
    rec(rec);
    cout << ans << '\n';
    return 0;
}
