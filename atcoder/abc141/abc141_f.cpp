#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    V<ll> A(N);
    rep(i, N) cin >> A[i];
    ll s = 0;
    rep(i, N) s ^= A[i];
    // 全てのXORが1のビットについて、A[i]が1なら0にする
    rep(i, N) A[i] &= ~s;
    ll ans = s;
    // XOR 基底を計算する
    V<ll> base;
    for (auto &ai : A) {
        for (auto b : base) {
            ai = min(ai, ai ^ b);
        }
        if (ai) base.push_back(ai);
    }
    // 上位ビットから貪欲に決めていくので降順ソート
    sort(base.rbegin(), base.rend());
    ll x = 0;
    for (auto b : base) x = max(x, x ^ b);
    show(x);
    cout << s + 2 * x << '\n';
    return 0;
}

/**
 * XOR基底
 * noshi基底
 * 掃き出し法
 */
