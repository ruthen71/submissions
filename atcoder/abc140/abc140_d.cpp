#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    string t = "";
    t += S[0];
    rep(i, N - 1) {
        if (S[i + 1] != S[i]) t += S[i + 1];
    }
    int ans = N - (int)t.size();
    // あえて操作をL...LかR...Rにしか適用できないとする
    // |t|-1:変わり目の個数
    // 1回の操作で変わり目が2つ消える(そして答えが+2される)
    ans += min(2 * K, (int)t.size() - 1);
    cout << ans << '\n';
    return 0;
}

/**
 * 操作に制限を加えてみる系
 * できることが自由すぎるとき->あえて制約を課した設定で考察する
 */
