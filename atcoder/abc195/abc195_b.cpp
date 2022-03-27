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
    ll A, B, W;
    cin >> A >> B >> W;
    W *= 1000;
    ll m = (W + B - 1) / B, M = W / A;
    if (m <= M)
        cout << m << ' ' << M << '\n';
    else
        cout << "UNSATISFIABLE" << '\n';
    return 0;
}