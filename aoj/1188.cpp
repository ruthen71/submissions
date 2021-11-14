#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

int dfs(string &S, int &id) {
    int n = sz(S);
    vector<int> b;
    int i;
    for (i = id + 1; i < n; i++) {
        if (S[i] == '[') {
            int ret = dfs(S, i);
            // ]で戻ってくる
            b.push_back(ret);
        } else if (S[i] != ']') {
            int c = i;
            while (S[c] != ']') c++;
            string t = S.substr(i, c - i);
            int bi = stoi(t);
            id = c;
            return (bi / 2 + 1);
        } else {
            break;
        }
    }
    id = i;
    sort(all(b));
    int s = 0;
    rep(i, sz(b) / 2 + 1) s += b[i];
    return s;
}

void solve() {
    string S;
    cin >> S;
    int n = sz(S);
    int i = 0;
    int ans = dfs(S, i);
    cout << ans << endl;
}

int main() {
    int N;
    cin >> N;
    while (N--) solve();
    return 0;
}

/*
DFSして頑張る
関数が戻るときに今見ているindexを持っておくと楽
*/