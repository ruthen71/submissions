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
    V<int> A(N);
    rep(i, N) cin >> A[i];
    V<int> seen(2005, 0);
    rep(i, N) seen[A[i]] = 1;
    rep(i, 2005) {
        if (seen[i] == 0) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}