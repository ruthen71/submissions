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
    V<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    V<int> p(N);
    iota(p.begin(), p.end(), 0);
    double ans = 0, c = 0;
    do {
        rep(i, N - 1) ans += sqrt((x[p[i + 1]] - x[p[i]]) * (x[p[i + 1]] - x[p[i]]) + (y[p[i + 1]] - y[p[i]]) * (y[p[i + 1]] - y[p[i]]));
        c++;
    } while (next_permutation(p.begin(), p.end()));
    cout << setprecision(15) << ans / c << '\n';
    return 0;
}
