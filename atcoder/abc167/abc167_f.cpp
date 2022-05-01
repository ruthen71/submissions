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
    int N;
    cin >> N;
    V<string> S(N);
    rep(i, N) cin >> S[i];
    int p = 0, m = 0, csum = 0;
    priority_queue<pair<int, int>> que1, que2;
    rep(i, N) {
        int lb = 0, ub = 0, c = 0;
        for (auto si : S[i]) {
            if (si == '(') {
                c++;
            } else {
                c--;
            }
            lb = min(lb, c);
            ub = max(ub, c);
        }
        csum += c;
        if (lb >= 0) {
            p += c;
        } else {
            // lb < 0
            // そもそもlb <= c
            if (lb == c) {
                m += -c;
            }
            // lb < c
            else if (c < 0) {
                que2.push({lb - c, -c});
            } else {
                que1.push({lb, c});
            }
        }
    }
    if (csum != 0) {
        cout << "No" << '\n';
        return 0;
    }
    auto f = [](priority_queue<pair<int, int>> que, int p) -> int {
        while (!que.empty() && que.top().first + p >= 0) {
            p += que.top().second;
            que.pop();
        }
        return que.empty();
    };
    if (f(que1, p) && f(que2, m)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}
/**
 * 括弧列
 * 貪欲法
 */