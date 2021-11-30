#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    string A, B;
    cin >> A >> B;
    int ms = max(SZ(A), SZ(B));
    reverse(ALL(A));
    reverse(ALL(B));
    rep(i, ms - SZ(A)) A += '0';
    rep(i, ms - SZ(B)) B += '0';
    int c = 0, ok = 0;
    rep(i, ms) {
        int a = A[i] - '0', b = B[i] - '0';
        int s = a + b + c;
        if (s >= 10) ok = 1;
        c = s / 10;
    }
    puts(ok ? "Hard" : "Easy");
    return 0;
}
