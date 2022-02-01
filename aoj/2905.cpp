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
    vector<string> S(N);
    vector<int> d1(N);
    rep(i, N) cin >> S[i] >> d1[i];
    int M;
    cin >> M;
    vector<string> T(M);
    rep(i, M) cin >> T[i];
    map<string, int> mp;
    int cnt = 1;
    rep(i, N) if (mp[S[i]] == 0) mp[S[i]] = cnt++;
    rep(i, M) if (mp[T[i]] == 0) mp[T[i]] = cnt++;
    vector<vector<int>> g(cnt);
    rep(i, N) g[mp[S[i]]].push_back(d1[i]);
    rep(i, cnt) sort(ALL(g[i]));
    int ok = 1, cd = 1000000000;
    for (int i = M - 1; i >= 0; i--) {
        int ind = mp[T[i]];
        int ok2 = 0;
        while (g[ind].size()) {
            int sz = (int)g[mp[T[i]]].size();
            int x = g[mp[T[i]]][sz - 1];
            g[ind].pop_back();
            if (x < cd) {
                ok2 = 1;
                cd = x;
                break;
            }
        }
        if (ok2) continue;
        ok = 0;
        break;
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}

/**
 * 大きい順に貪欲に使っていけば良い
 * 一度使ったやつは使えなくなるので二分探索でも良かった
 */
