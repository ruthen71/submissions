#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    cout << sx << " " << sy << '\n';
    cout << 1 << " " << sy << '\n';
    sx--, sy--;
    rep(i, n) {
        if (i % 2 == 0) {
            rep(j, m) {
                if ((i == sx && j == sy) || (i == 0 && j == sy)) continue;
                cout << i + 1 << " " << j + 1 << '\n';
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                if ((i == sx && j == sy) || (i == 0 && j == sy)) continue;
                cout << i + 1 << " " << j + 1 << '\n';
            }
        }
    }
    return 0;
}
