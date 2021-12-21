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
    vector<int> sum(26, 0);
    int n = S.size();
    rep(i, n) sum[S[i] - 'a']++;
    vector<int> csum(26, 0);
    for (int d = 1; d < n; d++) {
        csum[S[d - 1] - 'a']++;
        if (n % d != 0) continue;
        int ok = 1;
        rep(j, 26) if (sum[j] != csum[j] * n / d) ok = 0;
        if (ok) {
            cout << S.substr(0, d) << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}

/**
 * S[0]からどこかまでの種類ごとの文字数が
 * 全体のx倍になってるかを判定する
 * O(σN)(σ=文字の種類で今回は26)
 */
