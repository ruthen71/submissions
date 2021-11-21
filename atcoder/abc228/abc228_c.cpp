#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> P(N, vector<int>(3));
    rep(i, N) cin >> P[i][0] >> P[i][1] >> P[i][2];
    vector<pair<int, int>> Q(N);
    rep(i, N) Q[i] = {P[i][0] + P[i][1] + P[i][2], i};
    sort(ALL(Q));
    reverse(ALL(Q));
    vector<int> ans(N, 0);
    rep(i, K) ans[Q[i].second] = 1;
    rep(i, N - K) {
        if (Q[i + K].first + 300 >= Q[K - 1].first) ans[Q[i + K].second] = 1;
    }
    rep(i, N) { puts(ans[i] ? "Yes" : "No"); }
    return 0;
}
