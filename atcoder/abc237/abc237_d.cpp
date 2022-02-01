#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    string S;
    cin >> N >> S;
    deque<int> que;
    que.push_back(N);
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == 'R')
            que.push_front(i);
        else
            que.push_back(i);
    }
    rep(i, N + 1) cout << que[i] << (i == N ? '\n' : ' ');
    return 0;
}

/**
 * 逆から見るとdequeが使える
 */
