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
    priority_queue<int> que;
    rep(i, N) {
        int a;
        cin >> a;
        que.push(a);
    }
    rep(i, M) {
        int c = que.top();
        que.pop();
        que.push(c / 2);
    }
    ll ans = 0;
    rep(i, N) {
        ans += que.top();
        que.pop();
    }
    cout << ans << '\n';
    return 0;
}
