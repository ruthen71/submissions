#include <bits/stdc++.h>
using namespace std;

#include <atcoder/twosat>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int M = 2000005;

vector<ll> prime_list(ll n) {
    vector<ll> res;
    for (ll x = 2; x * x <= n; x++) {
        if (n % x == 0) {
            res.push_back(x);
            while (n % x == 0) n /= x;
        }
    }
    if (n != 1ll) res.push_back(n);
    return res;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    vector<vector<int>> G(M);
    rep(i, N) {
        vector<ll> Ap = prime_list(A[i]);
        for (auto Api : Ap) G[Api].push_back(i);
    }
    rep(i, N) {
        vector<ll> Bp = prime_list(B[i]);
        for (auto Bpi : Bp) G[Bpi].push_back(i + N);
    }
    // 新しいリテラルの数
    ll K = 0;
    rep(i, M) K += G[i].size();
    two_sat ts(2 * N + K);
    rep(i, N) ts.add_clause(i, true, i + N, true);
    ll K2 = 0;
    for (auto &Gi : G) {
        // 0<=Gi[i]<2*Nが元のリテラル
        // 2*N+K2 ~ 2*N+K2+Gi.size()-1が補助のリテラル
        rep(i, Gi.size()) ts.add_clause(Gi[i], false, 2 * N + K2 + i, true);
        rep(i, (int)Gi.size() - 1) {
            ts.add_clause(2 * N + K2 + i, false, 2 * N + K2 + i + 1, true);
            ts.add_clause(2 * N + K2 + i, false, Gi[i + 1], false);
        }
        K2 += Gi.size();
    }
    cout << (ts.satisfiable() ? "Yes" : "No") << endl;
    return 0;
}

/*
解説AC
2-SATはわかったが、各i,jについてAiとAj、AiとBj、BiとAj、BiとBj
を一緒に入れられるか、だとO(N^2log(max(A,B)))になって間に合わないところから改善できなかった
素因数分解すると、各素因数について、その素因数を含む数の集合に対し、高々1つだけ真(含む)という条件になる
高々1つのときはKを種類数としてO(K^2)をO(K)に落とせるので、その技術を使う
具体的には、P1,P2,...,PNのうち高々1つが真のとき
Qi=Qi-1orPi(Q1=P1)として、(notPi or Qi)と(notQi-1 or Qi)と(not Qi-1 or not Pi)を追加
(後半2つはi>1の時)
これで条件リテラル数が減ったので、2-SATを解くことができる
*/
