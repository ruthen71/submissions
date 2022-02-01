#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

bool dp[370][3][3][7][7][7][7][16];
bool a[370][4][4];
bool ok[3][3];

const int dx[9] = {2, 1, -1, -2, 0, 0, 0, 0, 0};
const int dy[9] = {0, 0, 0, 0, 0, 2, 1, -1, -2};

void solve(int N) {
    rep(i, N) rep(x, 3) rep(y, 3) rep(a1, 7) rep(a2, 7) rep(a3, 7) rep(a4, 7) rep(k, 16) dp[i][x][y][a1][a2][a3][a4][k] = false;
    rep(i, N) rep(x, 4) rep(y, 4) cin >> a[i][x][y];
    if (a[0][1][1] == true || a[0][1][2] == true || a[0][2][1] == true || a[0][2][2] == true) {
        cout << 0 << '\n';
        return;
    }
    dp[0][1][1][1][1][1][1][0] = true;
    for (int i = 1; i < N; i++) {
        rep(cx, 3) rep(cy, 3) {
            if (a[i][cx][cy] == true || a[i][cx][cy + 1] == true || a[i][cx + 1][cy] == true || a[i][cx + 1][cy + 1] == true)
                ok[cx][cy] = false;
            else
                ok[cx][cy] = true;
        }
        rep(cx, 3) rep(cy, 3) rep(a1, 7) rep(a2, 7) rep(a3, 7) rep(a4, 7) rep(b, 16) {
            if (dp[i - 1][cx][cy][a1][a2][a3][a4][b] == false) continue;
            // 遷移
            rep(k, 9) {
                int nx = cx + dx[k], ny = cy + dy[k];
                if (!(0 <= nx && nx < 3 && 0 <= ny && ny < 3)) continue;
                if (ok[nx][ny] == false) continue;
                int na1 = a1 + 1, na2 = a2 + 1, na3 = a3 + 1, na4 = a4 + 1, nb = b;
                if (nx == 0 && ny == 0) na1 = 0, nb |= 1;
                if (nx == 0 && ny == 2) na2 = 0, nb |= 2;
                if (nx == 2 && ny == 0) na3 = 0, nb |= 4;
                if (nx == 2 && ny == 2) na4 = 0, nb |= 8;
                if (na1 > 6) continue;
                if (na2 > 6) continue;
                if (na3 > 6) continue;
                if (na4 > 6) continue;
                dp[i][nx][ny][na1][na2][na3][na4][nb] = true;
            }
        }
    }
    rep(cx, 3) rep(cy, 3) rep(a1, 7) rep(a2, 7) rep(a3, 7) rep(a4, 7) {
        if (dp[N - 1][cx][cy][a1][a2][a3][a4][15] == true) {
            cout << 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while (cin >> N, N) solve(N);
    return 0;
}

/**
 * 重実装
 * 実は角4マスが干からびていないことが必要十分条件であることが分かるので
 * 16マス全てについて「最後に水をあげてから何日経ったか」を持てばよい
 */
