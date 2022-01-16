#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> x(Q), k(Q);
    rep(i, Q) cin >> x[i] >> k[i];
    map<int, vector<int>> mp;
    rep(i, N) mp[A[i]].push_back(i);
    rep(i, Q) {
        if (mp[x[i]].size() < k[i]) {
            cout << -1 << '\n';
        } else {
            cout << mp[x[i]][k[i] - 1] + 1 << '\n';
        }
    }
    return 0;
}

/**
 * mapを使えば良い
 */
