#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int N = 3;

const int dx[5] = {0, 1, 0, -1, 0};
const int dy[5] = {0, 0, 1, 0, -1};

void solve() {
    vector<string> s(N);
    rep(i, N) cin >> s[i];
    vector<vector<int>> a(N, vector<int>(N));
    rep(i, N) rep(j, N) a[i][j] = (s[i][j] == '*' ? 1 : 0);
    int ans = 10;
    rep(b, 1 << 9) {
        int c = 0;
        vector<vector<int>> a2 = a;
        rep(i, N) rep(j, N) {
            if (b >> c & 1) {
                rep(k, 5) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) continue;
                    a2[nx][ny] ^= 1;
                }
            }
            c++;
        }
        int ok = 1;
        rep(i, N) rep(j, N) if (a2[i][j]) ok = 0;
        if (ok) ans = min(ans, __builtin_popcount(b));
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int P;
    cin >> P;
    rep(i, P) solve();
    return 0;
}

/**
 * bit全探索
 * 各マスを中心に反転させるかbit全探索する
 * 反転回数は0か1
 */
