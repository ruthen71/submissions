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
    ll A, B, N;
    cin >> A >> B >> N;
    if (B <= N) {
        N = B - 1;
    }
    cout << A * N / B << '\n';
    return 0;
}
