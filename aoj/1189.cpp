#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

vector<bool> Era(int n) {
    vector<bool> isprime(n + 1, 1);
    isprime[0] = 0;
    isprime[1] = 0;
    for (int i = 2; i < n + 1; i++) {
        if (isprime[i]) {
            for (int j = 2 * i; j < n + 1; j += i) isprime[j] = 0;
        }
    }
    return isprime;
}

int M = 1005;

void solve(vector<bool>& era, ll m, ll n) {
    vector<vector<int>> p(M, vector<int>(M, -1));
    int cx = M / 2, cy = M / 2, s = 2;
    p[cx][cy] = 1;
    for (int k = 1; k < M; k++) {
        if (k % 2 == 1) {
            rep(i, k) {
                cx += dx[0];
                cy += dy[0];
                p[cx][cy] = s++;
            }
            rep(i, k) {
                cx += dx[1];
                cy += dy[1];
                p[cx][cy] = s++;
            }
        } else {
            rep(i, k) {
                cx += dx[2];
                cy += dy[2];
                p[cx][cy] = s++;
            }
            rep(i, k) {
                cx += dx[3];
                cy += dy[3];
                p[cx][cy] = s++;
            }
        }
        if (s > m) break;
    }

    vector<vector<int>> isp(M, vector<int>(M, 0));
    int sx, sy;
    rep(i, M) rep(j, M) {
        if (p[i][j] == n) sx = i, sy = j;
        if (p[i][j] > m) p[i][j] = -1;
        if (p[i][j] != -1) isp[i][j] = era[p[i][j]];
    }

    vector<vector<int>> dp(M, vector<int>(M, 0)), go(M, vector<int>(M, 0));
    dp[sx][sy] = isp[sx][sy];
    go[sx][sy] = 1;
    rep(i, M) {
        rep(j, M) {
            if (go[i][j] == 0) continue;
            if (p[i + 1][j - 1] != -1) dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + isp[i + 1][j - 1]), go[i + 1][j - 1] = 1;
            if (p[i + 1][j + 0] != -1) dp[i + 1][j + 0] = max(dp[i + 1][j + 0], dp[i][j] + isp[i + 1][j + 0]), go[i + 1][j + 0] = 1;
            if (p[i + 1][j + 1] != -1) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + isp[i + 1][j + 1]), go[i + 1][j + 1] = 1;
        }
    }
    int ans = 0;
    rep(i, M) rep(j, M) {
        if (go[i][j]) ans = max(ans, dp[i][j]);
    }
    if (ans == 0) {
        cout << "0 0\n";
        return;
    }
    int arg = 0;
    rep(i, M) rep(j, M) {
        if (ans == dp[i][j] && isp[i][j]) arg = max(arg, p[i][j]);
    }
    cout << ans << " " << arg << endl;
    return;
}

int main() {
    vector<bool> era = Era(1000005);
    ll m, n;
    while (cin >> m >> n, m) solve(era, m, n);
    return 0;
}

/*
盤面を構築すれば、あとはdpをしていくだけ
復元はans=dp[i][j]かつ(i,j)に書かれた数が素数で最も小さい
でできる
*/