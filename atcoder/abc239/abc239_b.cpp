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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll X;
    cin >> X;
    ll r = (X % 10 + 10) % 10;
    cout << (X - r) / 10 << '\n';
    return 0;
}
