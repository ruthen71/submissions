#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int r, d, x;
    cin >> r >> d >> x;
    rep(i, 10) {
        x = r * x - d;
        cout << x << '\n';
    }
    return 0;
}
