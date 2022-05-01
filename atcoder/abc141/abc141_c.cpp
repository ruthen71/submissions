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
    int N, K, Q;
    cin >> N >> K >> Q;
    V<int> cnt(N, 0);
    rep(i, Q) {
        int a;
        cin >> a;
        cnt[a - 1]++;
    }
    rep(i, N) cout << (K - Q + cnt[i] > 0 ? "Yes" : "No") << '\n';
    return 0;
}
