#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, K;
    cin >> N >> K;
    vector<pair<int, int>> A(N);
    rep(i, N) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    vector<ll> ans(N, K / N);
    K %= N;
    rep(i, K) { ans[A[i].second]++; }
    rep(i, N) { cout << ans[i] << '\n'; }
    return 0;
}
