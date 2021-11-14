#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

ll INF = 1ll << 60;

int N;
int w[305];
int memo[305][305], dp[305][305];

int rec(int i, int j) {
    if (i > j) return 1;
    if (memo[i][j] != -1) return memo[i][j];
    if (abs(i - j) % 2 == 0) return memo[i][j] = 0;
    if (i + 1 == j) {
        return memo[i][i + 1] = (abs(w[i] - w[i + 1]) <= 1);
    }
    int ok = 0;
    for (int x = i + 1; x <= j; x++) {
        if (abs(w[i] - w[x]) <= 1 && rec(i + 1, x - 1) == 1 && rec(x + 1, j) == 1) {
            ok = 1;
            break;
        }
    }
    return memo[i][j] = ok;
}

void solve() {
    rep(i, N) cin >> w[i];
    rep(i, N) rep(j, N) memo[i][j] = -1;
    rep(i, N) rep(j, N) dp[i][j] = rec(i, j);
    vector<pair<int, int>> a;
    rep(i, N) rep(j, i) {
        if (dp[j][i]) a.push_back({j, i});
    }
    sort(a.begin(), a.end(), [&](pair<int, int> s, pair<int, int> t) { return s.second < t.second; });
    // [0, i)のmax
    vector<int> dp(N + 1, 0);
    int idx = 0;
    for (int i = 0; i < N + 1; i++) {
        if (i > 0) dp[i] = dp[i - 1];
        while (idx < a.size() && a[idx].second < i) {
            dp[i] = max(dp[i], dp[a[idx].first] - a[idx].first + a[idx].second + 1);
            idx++;
        }
    }
    cout << dp[N] << endl;
}

int main() {
    while (cin >> N, N) solve();
    return 0;
}

/*
メモ化再帰
dp[i][j]=[i,j]は全部消せるか
で、メモ化再帰
[i,j]を消せるためには
i+1<=x<=jなるxに対して
iとxで消せて、[i+1,x-1]も消せて、[x+1,j]も消せればOK
そのあと消せる区間を全列挙して区間の終わりでソートして動的計画法する
dp[i]=[0,i)での消せる個数の最大値
ラムダ式
lambda式
ソート
*/