#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    if (C % 2 == 0) {
        A = abs(A);
        B = abs(B);
    }
    if (A < B)
        puts("<");
    else if (A == B)
        puts("=");
    else
        puts(">");
    return 0;
}
