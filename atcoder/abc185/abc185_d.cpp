#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll INF = 1ll << 60;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M + 2);
    rep(i, M) cin >> A[i + 1];
    A[0] = 0;
    A[M + 1] = N + 1;
    sort(A.begin(), A.end());
    ll ub = INF;
    rep(i, M + 1) {
        if (A[i + 1] - A[i] - 1 != 0) ub = min(ub, A[i + 1] - A[i] - 1);
    }
    if (ub == INF) {
        cout << 0 << endl;
        return 0;
    }
    ll cnt = 0;
    rep(i, M + 1) cnt += (A[i + 1] - A[i] - 1 + ub - 1) / ub;
    cout << cnt << endl;
    return 0;
}
