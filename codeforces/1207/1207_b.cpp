#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m, 0));
    rep(i, n) rep(j, m) cin >> a[i][j];
    vector<pair<int, int>> ans;
    int ok = 1;
    rep(i, n - 1) rep(j, m - 1) {
        if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1) {
            ans.push_back({i + 1, j + 1});
            b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
        }
    }
    rep(i, n) rep(j, m) {
        if (a[i][j] != b[i][j]) ok = 0;
    }
    if (ok) {
        cout << ans.size() << '\n';
        for (auto p : ans) {
            cout << p.first << " " << p.second << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
