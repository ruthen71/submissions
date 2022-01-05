#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

ll dp[1 << 12];

const ll INF = 1ll << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    rep(i, 1 << N) dp[i] = INF;
    dp[0] = 0;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        int bit = 0;
        rep(j, b) {
            int c;
            cin >> c;
            c--;
            bit |= (1 << c);
        }
        rep(j, 1 << N) dp[j | bit] = min(dp[j | bit], dp[j] + a);
    }
    cout << (dp[(1 << N) - 1] == INF ? -1 : dp[(1 << N) - 1]) << '\n';
    return 0;
}

/**
 * bitDPやるだけ
 */
