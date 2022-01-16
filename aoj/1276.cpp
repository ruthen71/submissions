#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M = 1300000;
    vector<int> p(M, 1);
    p[0] = 0;
    p[1] = 0;
    for (int i = 2; i < M; i++) {
        if (p[i]) {
            for (int j = 2 * i; j < M; j += i) p[j] = 0;
        }
    }
    vector<int> L(M), R(M);
    int l = 0;
    for (int i = 0; i < M; i++) {
        if (p[i]) {
            l = i;
        }
        L[i] = l;
    }
    int r = M;
    for (int i = M - 1; i >= 0; i--) {
        if (p[i]) {
            r = i;
        }
        R[i] = r;
    }
    int N;
    while (cin >> N, N) cout << R[N] - L[N] << '\n';
    return 0;
}

/**
 * エラトステネスの篩
 */