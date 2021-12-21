#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> cnt(26, 0);
        rep(i, n) cnt[s[i] - 'a']++;
        int od = 0;
        rep(i, 26) od += cnt[i] % 2;
        if (od > 1) {
            cout << "Impossible\n";
            continue;
        }
        // 愚直にそろえていく
        int ans = 0;
        rep(i, n / 2) {
            if (cnt[s[i] - 'a'] == 1) {
                swap(s[i], s[i + 1]);
                ans++;
            }
            // s[n-1-i]をs[i]と一致させる
            for (int j = n - 1 - i; j > i; j--) {
                if (s[i] == s[j]) {
                    for (int k = j; k < n - 1 - i; k++) {
                        swap(s[k], s[k + 1]);
                        ans++;
                    }
                    cnt[s[i] - 'a'] -= 2;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

/**
 * 奇数個の文字が2種類以上あったらアウト
 * それ以外の時は回文にできて、
 * S[0]から順にS[i]とS[N-1-i]を一致させる
 * ラスト1個の文字の扱いが少しめんどくさいが、とりあえずswapして後回しにすればOK
 */