#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> B(N + 1, 0);
    rep(i, N) B[i + 1] = (B[i] + A[i]) % 360;
    sort(ALL(B));
    int m = (B[0] + 360 - B[N]) % 360;
    rep(i, N) m = max(m, (B[i + 1] - B[i]) % 360);
    cout << m << '\n';
    return 0;
}

/**
 * なんでBでmod360を計算させられているんだ
 */