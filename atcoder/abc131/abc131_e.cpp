#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int N, K;
    cin >> N >> K;
    if ((N - 1) * (N - 2) / 2 < K) return puts("-1") & 0;
    vector<pair<int, int>> ans;
    for (int i = 2; i <= N; i++) {
        ans.push_back({1, i});
    }
    int cur = (N - 1) * (N - 2) / 2;
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j < i; j++) {
            if (cur == K) goto f;
            ans.push_back({j, i});
            cur--;
        }
    }
f:
    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.first << " " << p.second << '\n';
    }
    return 0;
}

/**
 * 構築
 * スターグラフを作り、最短距離のペアを減らしていく
 */