#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll mod = 1000000007;

int main() {
    ll N;
    cin >> N;
    vector<ll> C(N);
    rep(i, N) cin >> C[i];
    sort(C.begin(), C.end());
    ll ans = 1;
    rep(i, N) { ans = ans * max(0ll, C[i] - i) % mod; }
    cout << ans << endl;
    return 0;
}
