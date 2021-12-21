#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void solve(string &S) {
    string T = "";
    int N = S.size();
    rep(i, N) {
        T += S[i];
        T += '$';
    }
    T.pop_back();
    assert(2 * N - 1 == (int)T.size());
    set<string> ans;
    int M = 2 * N - 1;
    for (int i = 1; i < M - 1; i++) {
        for (int j = (T[i] != '$') + 1; i - j >= 0 && i + j < M; j += 2) {
            if (T[i - j] != T[i + j]) break;
            ans.insert(T.substr(i - j, 2 * j + 1));
        }
    }
    for (auto &c : ans) {
        string ansci = "";
        for (auto &ci : c) {
            if (ci == '$') continue;
            ansci += ci;
        }
        if (ansci.size() > 1) cout << ansci << '\n';
    }
    cout << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    while (cin >> S) solve(S);
    return 0;
}

/**
 * 愚直で通ることを期待して投げると、通る
 * 回文の愚直判定で$を入れると実装が楽
 */
