#include <bits/stdc++.h>
using namespace std;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ll INF = 1ll << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll s = 0;
    rep(i, N) s += A[i];
    vector<ll> div = divisor(s);
    reverse(ALL(div));
    for (auto &d : div) {
        vector<ll> B(N);
        rep(i, N) B[i] = A[i] % d;
        sort(ALL(B));
        ll s2 = 0;
        rep(i, N) s2 += B[i];
        ll c = 0, anc = s2;
        for (int i = N - 1; i >= 0; i--) {
            c += B[i];
            s2 -= B[i];
            anc = min(anc, max(s2, d * (N - i) - c));
        }
        if (anc <= K) {
            cout << d << '\n';
            return 0;
        }
    }
    return 0;
}

/**
 * 操作
 * 不変量を探す系
 * https://takahero2016.hatenablog.com/entry/2020/09/01/030508
 * 上記コードを書いたのは2022/01/02
 * 自分でブログ書いたのは2020/09/01
 * 1年以上経ってからやり直したら、Aの総和の約数が答えの候補というのは
 * すぐだったが、判定パートがわからない
 * 結局計算量的にソートするくらいしかやることないだろという読みで解いてしまった
 * ちなみに未だにソートの正当性を理解していない
 * (2020年の自分に教えてほしい……)
 * 追記：理解しました(ref:https://algo-logic.info/abc136e/)
 * +の回数と-の回数の差がどのrをd-rにしても-dされるので
 * 最初のsumから-dを何回か行うとして、残りを最小化するには大きいほうからやれば良いという感じか
 */
