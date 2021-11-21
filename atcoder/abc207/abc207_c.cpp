#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll L[2005], R[2005];

int f(int i, int j) {
    if (R[j] < L[i] || R[i] < L[j]) return 0;
    return 1;
}

int main() {
    ll N;
    cin >> N;
    rep(i, N) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) L[i] = 2 * l, R[i] = 2 * r;
        if (t == 2) L[i] = 2 * l, R[i] = 2 * r - 1;
        if (t == 3) L[i] = 2 * l + 1, R[i] = 2 * r;
        if (t == 4) L[i] = 2 * l + 1, R[i] = 2 * r - 1;
    }
    ll ans = 0;
    rep(i, N) {
        rep(j, i) { ans += f(i, j); }
    }
    cout << ans << endl;
    return 0;
}
