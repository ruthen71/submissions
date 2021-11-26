#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> K(Q);
    rep(i, Q) cin >> K[i];
    rep(i, Q) {
        ll ok = N, ng = -1;
        while (ok - ng > 1) {
            ll md = (ok + ng) / 2;
            ll cnt = upper_bound(ALL(A), K[i] + md) - A.begin();
            if (md >= cnt)
                ok = md;
            else
                ng = md;
        }
        cout << K[i] + ok << '\n';
    }
    return 0;
}

/*
クエリ問題
多分自分がコンテスト中に投げた解法は(通ったけど)最悪計算量がO(QNlog(N))なので落ちる
答えansはKi<=ans<=Ki+Nである
Ki+Nは絶対にOK
Ki-1は絶対にNG
で、その間はAにおけるx番目とするとxは広義単調増加
よって、x>=kiとなる最小のxを二分探索する
*/