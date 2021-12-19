#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), C(M), D(M);
    rep(i, M) cin >> A[i] >> B[i];
    rep(i, M) cin >> C[i] >> D[i];
    rep(i, M) A[i]--, B[i]--, C[i]--, D[i]--;
    vector<int> r(N);
    iota(ALL(r), 0);
    vector<vector<int>> con(N, vector<int>(N, 0));
    rep(i, M) con[A[i]][B[i]] = con[B[i]][A[i]] = 1;
    int ok = 0;
    do {
        vector<vector<int>> con2(N, vector<int>(N, 0));
        int ok2 = 1;
        rep(i, M) con2[r[C[i]]][r[D[i]]] = con2[r[D[i]]][r[C[i]]] = 1;
        rep(i, N) rep(j, N) if (con[i][j] != con2[i][j]) ok2 = 0;
        ok = max(ok, ok2);
    } while (next_permutation(ALL(r)));
    puts(ok ? "Yes" : "No");
    return 0;
}

/**
 * グラフの同形判定
 */