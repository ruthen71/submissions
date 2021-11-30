#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    rep(i, n) cnt[s[i] - 'a']++;
    vector<int> cum(27, 0);
    rep(i, 26) cum[i + 1] = cum[i] + cnt[i];
    int idx = upper_bound(ALL(cum), k) - cum.begin();
    idx--;
    int su = k - cum[idx];
    string ans = "";
    rep(i, n) {
        if (s[i] - 'a' < idx)
            continue;
        else if (s[i] - 'a' == idx) {
            if (su <= 0) {
                ans += s[i];
            }
            su--;
        } else {
            ans += s[i];
        }
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 愚直にシミュレーションしても間に合わないが
 * アルファベットごとに取り除ける数を求めておけばよい
 */