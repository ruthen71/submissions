#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

vector<vector<int>> prod(vector<vector<int>> &mat, vector<vector<int>> &op) {
    int N = mat.size();
    vector<vector<int>> mat2(N, vector<int>(N));
    rep(i, N) rep(j, N) mat2[i][j] = mat[op[i][j] / N][op[i][j] % N];
    return mat2;
}

vector<vector<int>> matpow(vector<vector<int>> &A, ll k) {
    int N = A.size();
    vector<vector<int>> E(N, vector<int>(N));
    rep(i, N) rep(j, N) E[i][j] = i * N + j;
    while (k) {
        if (k & 1) E = prod(E, A);
        A = prod(A, A);
        k >>= 1;
    }
    return E;
}

vector<vector<int>> rec(string &S, int l, int &r, int N) {
    int L = S.size();
    if (S[l] == 'L' || S[l] == 'R' || S[l] == 'U' || S[l] == 'D') {
        int d = 0, idx = l + 1;
        while ('0' <= S[idx] && S[idx] <= '9') d = 10 * d + S[idx++] - '0';
        r = idx;
        d--;
        vector<vector<int>> ret(N, vector<int>(N));
        rep(i, N) rep(j, N) ret[i][j] = i * N + j;
        if (S[l] == 'L') {
            rep(j, N) ret[d][j] = d * N + (j + 1) % N;
        } else if (S[l] == 'R') {
            rep(j, N) ret[d][j] = d * N + (j - 1 + N) % N;
        } else if (S[l] == 'U') {
            rep(i, N) ret[i][d] = (i + 1) % N * N + d;
        } else {
            rep(i, N) ret[i][d] = (i - 1 + N) % N * N + d;
        }
        return ret;
    } else if (S[l] == '(') {
        vector<vector<int>> E(N, vector<int>(N));
        rep(i, N) rep(j, N) E[i][j] = i * N + j;
        l++;
        while (S[r] != ')') {
            vector<vector<int>> op = rec(S, l, r, N);
            l = r;
            E = prod(E, op);
        }
        ll d = 0, idx = r + 1;
        while ('0' <= S[idx] && S[idx] <= '9') d = 10 * d + S[idx++] - '0';
        r = idx;
        return matpow(E, d);
    } else {
        assert(0);
    }
}

vector<vector<int>> rec1(string &S, int l, int &r, int N) {
    int L = S.size();
    vector<vector<int>> E(N, vector<int>(N));
    rep(i, N) rep(j, N) E[i][j] = i * N + j;
    while (r < L) {
        vector<vector<int>> op = rec(S, l, r, N);
        l = r;
        E = prod(E, op);
    }
    return E;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, L;
    cin >> N >> L;
    string S;
    cin >> S;
    int l = 0, r = 0;
    vector<vector<int>> mat = rec1(S, l, r, N);
    rep(i, N) {
        rep(j, N) {
            if (j != N - 1)
                cout << mat[i][j] + 1 << " ";
            else
                cout << mat[i][j] + 1 << "\n";
        }
    }
    return 0;
}

/**
 * 構文解析典型：1文字目で場合分けする
 * 繰り返し二乗法
 * mat[i][j]=今(i,j)にある要素の移動先
 * とすると、行列累乗のイメージで、操作回数を高速化できる
 * 構文解析パートは意外にバグらなかった(が、一通り書き上げるまでに時間がかかった)
 */
