#include <bits/stdc++.h>
using namespace std;

#include <atcoder/convolution>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    string S, T;
    cin >> S >> T;
    int n = S.size(), m = T.size();
    vector<int> a(n), b(m);
    rep(i, n) a[i] = S[i] - '0';
    rep(j, m) b[j] = T[j] - '0';
    reverse(ALL(b));
    vector<int> c = convolution(a, b);  // 一致してる数(1)
    rep(i, n) a[i] = 1 - a[i];
    rep(j, m) b[j] = 1 - b[j];
    vector<int> d = convolution(a, b);  // 一致してる数(0)
    int ans = 1 << 30;
    for (int i = m - 1; i <= n - 1; i++) ans = min(ans, m - c[i] - d[i]);
    cout << ans << '\n';
    return 0;
}

/**
 * 解説AC(公式解説は読んでいないが、畳み込み、というワードをツイートで見た)
 * 畳み込み
 * 掛け算ではなくxorなので上手く変形する
 * s xor t = s*(1-t) + (1-s)*t
 * 自分は1として一致している部分の個数と0として一致している部分の個数を求めた
 */
