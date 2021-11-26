#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(ALL(A));
    int ok = 1;
    rep(i, N) {
        if (A[i] != i + 1) ok = 0;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}
