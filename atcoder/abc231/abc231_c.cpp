#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N), x(Q);
    rep(i, N) cin >> A[i];
    rep(i, Q) cin >> x[i];
    sort(ALL(A));
    vector<ll> ans(Q);
    rep(i, Q) { ans[i] = N - (lower_bound(ALL(A), x[i]) - A.begin()); }
    rep(i, Q) cout << ans[i] << '\n';
    return 0;
}

/**
 * ソートして二分探索する
 */