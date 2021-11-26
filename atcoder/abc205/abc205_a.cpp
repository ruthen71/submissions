#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    ld a, b;
    cin >> a >> b;
    ld ans = a * b / 100;
    printf("%.15Lf\n", ans);
    return 0;
}
