#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

ll dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
ll dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int ans[2];

void solve() {
    int H, W, K;
    cin >> W >> H >> K;
    vector<string> G(H);
    rep(i, H) cin >> G[i];
    // 縦
    rep(i, H - K + 1) {
        rep(j, W) {
            if (G[i][j] == '.') continue;
            int ok = 1;
            rep(k, K) if (G[i][j] != G[i + k][j]) ok = 0;
            if (ok) {
                if (G[i][j] == 'o') {
                    ans[1]++;
                } else {
                    ans[0]++;
                }
                return;
            }
        }
    }
    // 横
    rep(i, H) {
        rep(j, W - K + 1) {
            if (G[i][j] == '.') continue;
            int ok = 1;
            rep(k, K) if (G[i][j] != G[i][j + k]) ok = 0;
            if (ok) {
                if (G[i][j] == 'o') {
                    ans[1]++;
                } else {
                    ans[0]++;
                }
                return;
            }
        }
    }
    // 左上から右下
    rep(i, H - K + 1) {
        rep(j, W - K + 1) {
            if (G[i][j] == '.') continue;
            int ok = 1;
            rep(k, K) if (G[i][j] != G[i + k][j + k]) ok = 0;
            if (ok) {
                if (G[i][j] == 'o') {
                    ans[1]++;
                } else {
                    ans[0]++;
                }
                return;
            }
        }
    }
    rep(i, H) reverse(ALL(G[i]));
    // 右上から左下
    rep(i, H - K + 1) {
        rep(j, W - K + 1) {
            if (G[i][j] == '.') continue;
            int ok = 1;
            rep(k, K) if (G[i][j] != G[i + k][j + k]) ok = 0;
            if (ok) {
                if (G[i][j] == 'o') {
                    ans[1]++;
                } else {
                    ans[0]++;
                }
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    cout << ans[0] << ":" << ans[1] << '\n';
    return 0;
}
