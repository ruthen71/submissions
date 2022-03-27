#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    V<int> A(N), B(N), C(M), D(M);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, M) cin >> C[i];
    rep(i, M) cin >> D[i];
    V<pair<int, int>> AB, CD;
    rep(i, N) AB.push_back({A[i], B[i]});
    rep(j, M) CD.push_back({C[j], D[j]});
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    int cnt = 0, ind = 0;
    multiset<int> S;
    rep(i, M) {
        auto [c, d] = CD[i];
        while (ind < N && AB[ind].first <= c) {
            S.insert(AB[ind++].second);
        }
        auto it = S.upper_bound(d);
        if (it == S.begin()) continue;
        it--;
        S.erase(it);
        cnt++;
    }
    cout << (cnt == N ? "Yes" : "No") << '\n';
    return 0;
}