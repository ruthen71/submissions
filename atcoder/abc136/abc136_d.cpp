#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    int N = S.size();
    int LOG = 60;
    // db[b][i] = 最初iにいた子供が2^b回の移動後にいるマス
    vector<vector<int>> db(LOG, vector<int>(N));
    rep(i, N) {
        if (S[i] == 'L')
            db[0][i] = max(0, i - 1);
        else
            db[0][i] = min(N - 1, i + 1);
    }
    rep(b, LOG - 1) rep(i, N) db[b + 1][i] = db[b][db[b][i]];
    vector<int> ans(N, 0);
    rep(i, N) ans[db[LOG - 1][i]]++;
    rep(i, N) {
        if (i == 0)
            cout << ans[i];
        else
            cout << " " << ans[i];
    }
    cout << '\n';
    return 0;
}

/**
 * ダブリングをやる
 * 場合分けで通していた頃を思い出して懐かしくなった
 */
