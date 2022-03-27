#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) begin(x), end(x)
template <class T> using V = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    V<int> A(N);
    rep(i, N) cin >> A[i];
    V<pair<int, int>> B;
    int s = 0;
    rep(i, N) {
        if (B.size() == 0) {
            if (A[i] == 1) continue;
            B.push_back({A[i], 1});
            s++;
        } else {
            auto v = B.back();
            B.pop_back();
            if (v.first == A[i]) {
                if (v.second + 1 == A[i]) {
                    s -= v.second;
                } else {
                    B.push_back({A[i], v.second + 1});
                    s++;
                }
            } else {
                B.push_back(v);
                B.push_back({A[i], 1});
                s++;
            }
        }
        cout << s << '\n';
        show(B);
    }
    return 0;
}

/**
 * {値,個数}で圧縮してスタックに入れる
 * バグらせやすいかも
 */
