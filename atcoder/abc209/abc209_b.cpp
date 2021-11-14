#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll s = 0;
    rep(i, N) {
        s += A[i];
        s -= (i % 2 == 1);
    }
    if (X >= s)
        puts("Yes");
    else
        puts("No");
    return 0;
}
