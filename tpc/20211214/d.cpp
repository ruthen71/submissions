#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void solve() {
    int len, nd;
    cin >> len >> nd;
    vector<pair<int, string>> sas(nd);
    rep(i, nd) cin >> sas[i].first >> sas[i].second;
    rep(i, nd) sas[i].first--;
    string ans = "";
    rep(i, len) ans += '-';
    rep(i, nd) {
        int p = sas[i].first;
        int ls = sas[i].second.size();
        rep(j, ls) {
            if (sas[i].second[j] == '*') break;
            if (ans[p + j] == '-') {
                ans[p + j] = sas[i].second[j];
            } else if (ans[p + j] != sas[i].second[j]) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
        reverse(ALL(sas[i].second));
        rep(j, ls) {
            if (sas[i].second[j] == '*') break;
            if (ans[len - 1 - j] == '-') {
                ans[len - 1 - j] = sas[i].second[j];
            } else if (ans[len - 1 - j] != sas[i].second[j]) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }
    rep(i, len) if (ans[i] == '-') {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << ans << '\n';
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

/**
 * 愚直に条件にあうように追加していく
 * 「*」は1回しか出てこないので結局位置pから数文字と最後から数文字が指定されている
 */
