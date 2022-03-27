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

using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ld H;
    cin >> H;
    ld ans = sqrt(H * (H + 12800000));
    cout << setprecision(15) << ans << '\n';
    return 0;
}
