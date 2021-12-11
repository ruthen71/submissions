#include <bits/stdc++.h>
using namespace std;

#include <atcoder/dsu>
using namespace atcoder;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];
    dsu uf(N);
    rep(i, M) {
        A[i]--, B[i]--;
        uf.merge(A[i], B[i]);
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    int ok = 1;
    rep(i, N) if (G[i].size() > 2) ok = 0;
    vector<int> nume(N, 0);
    rep(i, M) { nume[uf.leader(A[i])]++; }
    rep(i, N) {
        if (nume[uf.leader(i)] > uf.size(i) - 1) ok = 0;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}

/**
 * 連結成分ごとにパスグラフか判定できればOK
 * パスグラフの条件
 * 1.次数3の頂点がない
 * 2.閉路がない
 * 1.はN要素の配列を持てばOK
 * 2.は辺の本数=頂点数-1で、UnionFindを使う(実は連結しようとしたときにすでに連結してたらOUTでもOK)
 */
