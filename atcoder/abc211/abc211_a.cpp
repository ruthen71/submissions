#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ld a, b;
    cin >> a >> b;
    printf("%.15Lf\n", (a - b) / 3 + b);
    return 0;
}
