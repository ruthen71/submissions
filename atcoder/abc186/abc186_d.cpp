#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll INF = 1ll << 60;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll ans = 0;
    sort(ALL(A));
    ll s = A[0];
    for (int i = 1; i < N; i++) {
        ans += A[i] * i - s;
        s += A[i];
    }
    cout << ans << endl;
    return 0;
}

/*
絶対値をソートすることで外す
各要素の右からと左からの寄与を考えるのも一手
(ans+=A[i]*i+A[i]*(N-1-i)をi=0...N-1についてやる)
*/