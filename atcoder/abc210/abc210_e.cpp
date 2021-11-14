#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll INF = 1ll << 60;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), C(M);
    rep(i, M) cin >> A[i] >> C[i];
    vector<ll> div;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            div.push_back(i);
            if (i * i != N) div.push_back(N / i);
        }
    }
    sort(div.begin(), div.end());
    int len = div.size();
    vector<ll> dp(len, INF);
    dp[len - 1] = 0;
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            ll g = gcd(div[i], A[j]);
            int nex = lower_bound(div.begin(), div.end(), g) - div.begin();
            if (dp[nex] > dp[i] + C[j] * (div[i] - g)) {
                dp[nex] = dp[i] + C[j] * (div[i] - g);
            }
        }
    }
    cout << (dp[0] == INF ? -1 : dp[0]) << endl;
    return 0;
}

/*
バチャ終了後自力AC
最大公約数、DAG、動的計画法
まずどの操作によってもNの約数個の連結成分数にしかならないことに気づく
すると、各約数について、この約数からこの約数にするときのコスト、が計算できる
しかもDAGなのでdpできる
解説資料ではCの小さい順にソートすることで、かなり速くしていた
（最小全域木の発想）
*/