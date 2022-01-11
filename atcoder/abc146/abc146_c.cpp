#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

ll A, B, X;

ll d(ll N) {
    ll ret = 0;
    while (N) {
        ret++;
        N /= 10;
    }
    return ret;
}

ll f(ll N) { return A * N + B * d(N); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> A >> B >> X;
    ll ok = 0, ng = 1000000001;
    while (ng - ok > 1) {
        ll md = (ok + ng) / 2;
        if (f(md) <= X)
            ok = md;
        else
            ng = md;
    }
    cout << ok << '\n';
    return 0;
}

/**
 * Nに単調性があるので二分探索する
 * 当時解けなくて悔しかったのを思い出した
 * 懐かしい
 */
