#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int M = 1 << 9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(j, m) cin >> b[j];
    vector<vector<int>> dp(n + 1, vector<int>(M, 0));
    dp[0][0] = 1;
    rep(i, n) rep(j, m) rep(bb, M) dp[i + 1][bb | (a[i]) & b[j]] |= dp[i][bb];

    rep(i, M) {
        if (dp[n][i]) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}

/**
 * dp
 * 実はdpしなくても良い
 * 答えを決めると(xとする)
 * 全てのiに対し、(Ai&Bj)|x==xとなるjが存在すればOK
 */
