#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ll W, H, x, y;
    cin >> W >> H >> x >> y;
    ld S = (ld)W * H / 2;
    int ok = (W % 2 == 0 && H % 2 == 0 && W / 2 == x && H / 2 == y);
    cout << S << ' ' << ok << '\n';
    return 0;
}
