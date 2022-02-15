#include <bits/stdc++.h>
using namespace std;
// clang-format off
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
template <class T> using V = vector<T>;
// clang-format on
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    V<ll> S(N);
    rep(i, N) cin >> S[i];
    V<ll> A(N + 2, 0);
    V<ll> lb(3, 0), s(3, 0);
    rep(i, N - 1) {
        s[i % 3] += S[i] - S[i + 1];
        lb[i % 3] = max(lb[i % 3], s[i % 3]);
    }
    if (lb[0] + lb[1] + lb[2] > S[0]) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    lb[0] += S[0] - lb[0] - lb[1] - lb[2];
    rep(i, 3) A[i] = lb[i];
    for (int i = 3; i < N + 2; i++) {
        A[i] = A[i - 3] + (S[i - 2] - S[i - 3]);
    }
    rep(i, N + 2) cout << A[i] << (i == N + 1 ? '\n' : ' ');
    return 0;
}
/**
 * 連立一次方程式系
 * こういうのは差分を見ると良い
 */
