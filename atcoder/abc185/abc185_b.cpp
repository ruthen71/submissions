#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, M, T;
    cin >> N >> M >> T;
    int ok = 1;
    ll cur = 0;
    ll mN = N;
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        N -= a - cur;
        if (N <= 0) ok = 0;
        N += b - a;
        N = min(N, mN);
        cur = b;
    }
    N -= T - cur;
    if (N <= 0) ok = 0;
    if (ok)
        puts("Yes");
    else
        puts("No");

    return 0;
}
