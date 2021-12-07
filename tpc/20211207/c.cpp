#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

ll dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
ll dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int dp[100][100][11];
string w = "ICPCASIASG";

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<string> G(N);
    rep(i, N) G[i] = S.substr(N * i, N);
    rep(i, N) rep(j, N) if (G[i][j] == 'I') dp[i][j][0] = 1;
    rep(k, 9) {
        rep(i, N) {
            rep(j, N) {
                if (dp[i][j][k] == 0) continue;
                rep(l, 8) {
                    int nx = i + dx[l], ny = j + dy[l];
                    if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) continue;
                    if (G[nx][ny] == w[k + 1]) dp[nx][ny][k + 1] = 1;
                }
            }
        }
    }
    int ok = 0;
    rep(i, N) rep(j, N) ok = max(ok, dp[i][j][9]);
    puts(ok ? "YES" : "NO");
    return 0;
}
