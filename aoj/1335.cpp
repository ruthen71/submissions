#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int MAX = 20;
    int N2 = 1 << MAX;
    vector<vector<int>> g(160);
    rep(b, N2) {
        int s = 0;
        rep(i, MAX) {
            if (b >> i & 1) s += i + 1;
        }
        if (s >= 160) continue;
        g[s].push_back(b);
    }
    int N, K, S;
    while (cin >> N >> K >> S, N) {
        int ans = 0;
        int b2 = 0;
        rep(i, MAX - N) b2 += (1 << (N + i));
        for (auto &b : g[S]) {
            if (b & b2) continue;
            if (__builtin_popcount(b) != K) continue;
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}

/**
 * あらかじめ
 * bit全探索して集合に対する要素の総和ごとに分けておく
 */
