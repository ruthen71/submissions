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

const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, T;
    cin >> N >> T;
    V<ll> D(N);
    rep(i, N) cin >> D[i];
    sort(D.begin(), D.end());
    int l = 0;
    ll ans = 1;
    for (int r = 0; r < N; r++) {
        while (l < r && D[l] + T < D[r]) l++;
        ans *= (r - l + 1);
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 挿入DP
 * 新しく要素を追加するときに、その要素の「1つ前におく要素」を考えると
 * 復元していく中で1対1対応が作れる
 */