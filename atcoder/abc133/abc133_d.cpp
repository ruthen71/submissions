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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll s = 0;
    rep(i, N) {
        if (i % 2 == 0)
            s += A[i];
        else
            s -= A[i];
    }
    vector<ll> ans(N);
    ans[0] = s;
    rep(i, N - 1) ans[i + 1] = 2 * (A[i] - ans[i] / 2);
    rep(i, N) {
        if (i == N - 1)
            cout << ans[i] << '\n';
        else
            cout << ans[i] << ' ';
    }
    return 0;
}

/**
 * Nが奇数なので
 * 交代和を取るとans[0]が求められて、あとは1つずつやる
 */