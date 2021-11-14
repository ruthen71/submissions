#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

ll INF = 1ll << 60;

map<ll, ll> dp[20][2][2][2];

int main() {
    string s;
    ll K;
    cin >> s >> K;
    dp[0][0][0][0][1] = 1;
    int n = s.size();
    rep(i, n) {
        rep(j, 2) {
            rep(k, 2) {
                rep(l, 2) {
                    for (auto p : dp[i][j][k][l]) {
                        ll c = (k ? p.first : 1ll);
                        rep(d, (j ? 9 : s[i] - '0') + 1) {
                            if (l == 0 && c * d <= K) {
                                dp[i + 1][j | (d < s[i] - '0')][k | (d > 0)][0][c * d] += p.second;
                            } else {
                                dp[i + 1][j | (d < s[i] - '0')][k | (d > 0)][1][((c == 0 || d == 0) ? 0 : INF)] += p.second;
                            }
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(j, 2) {
        rep(k, 2) {
            rep(l, 2) {
                for (auto p : dp[n][j][k][l]) {
                    if (p.first <= K) ans += p.second;
                }
            }
        }
    }
    cout << ans - 1 << endl;
    return 0;
}

/*
桁dp、digit DP、桁DP、digit dp
dp[i][j][k][l]=i-1桁目まで見ている、j=0のとき、ぴったり、j=1のときNより小さい
k=0のとき、0以外の数を含まない、k=1のとき、0以外の数を含む
l=0のとき、積がK以下、l=1のとき、積がKより大きい
となるような{積の値,個数}のペア(map)
(一度積がKより大きくなっても、あとの桁で0を使って0にできるので、捨ててはいけない)

追記：lはいらないことに気づいた

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

map<ll, ll> dp[20][2][2];

int main() {
    string s;
    ll K;
    cin >> s >> K;
    dp[0][0][0][1] = 1;
    int n = s.size();
    rep(i, n) {
        rep(j, 2) {
            rep(k, 2) {
                for (auto p : dp[i][j][k]) {
                    ll c = (k ? p.first : 1ll);
                    rep(d, (j ? 9 : s[i] - '0') + 1) {
                        ll nx = -1;
                        if (c > K && d != 0) nx = K + 1;
                        if (c <= K && c * d > K) nx = K + 1;
                        if (nx == -1) nx = c * d;
                        dp[i + 1][j | (d < s[i] - '0')][k | (d > 0)][nx] += p.second;
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(j, 2) rep(k, 2) for (auto p : dp[n][j][k]) if (p.first <= K) ans += p.second;
    cout << ans - 1 << endl;
    return 0;
}


*/
