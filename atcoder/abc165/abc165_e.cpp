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
    V<int> A, B;
    deque<int> que;
    rep(i, N) que.push_back(i);
    int c = (N + 1) / 2 - 1;
    rep(i, (c + 1) / 2) {
        A.push_back(que.front());
        B.push_back(que.back());
        que.pop_front();
        que.pop_back();
    }
    if (N % 2 == 0) que.pop_back();
    rep(i, c / 2) {
        A.push_back(que.front());
        B.push_back(que.back());
        que.pop_front();
        que.pop_back();
    }
    rep(i, M) cout << A[i] + 1 << ' ' << B[i] + 1 << '\n';
    return 0;
}
