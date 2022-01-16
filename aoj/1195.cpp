#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

string op(string S) {
    vector<int> seen(26, 0);
    seen[0] = 1;
    int N = (int)S.size();
    rep(i, N) if (seen[S[i] - 'a'] == 0) seen[S[i] - 'a'] = 1, S[i]--;
    return S;
}

void solve(string &S) {
    int N = (int)S.size();
    int N2 = 1 << N;
    int z = 0;
    rep(i, N) if (S[N - 1 - i] == 'z') z += (1 << i);
    vector<string> ans;
    int k = 0;
    rep(b, N2) {
        if (b & z) continue;
        string S2 = S;
        rep(i, N) {
            if (b >> i & 1) S2[N - 1 - i]++;
        }
        if (op(S2) == S) {
            ans.push_back(S2);
            k++;
            if (ans.size() > 10) {
                vector<string> c;
                rep(i, 5) c.push_back(ans[i]);
                rep(i, 5) c.push_back(ans[6 + i]);
                ans = c;
            }
        }
    }
    cout << k << '\n';
    for (auto &v : ans) cout << v << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    while (cin >> S, S != "#") solve(S);
    return 0;
}

/**
 * 各文字を変えるか変えないかを全探索すれば良いが…
 * bit全探索の場合、定数倍高速化が大変
 * 自分はsort()を使わず、かつb->a,c->b,...の操作をO(σ|S|)ではなくO(|S|)にすることで通した
 * 前から順に変えていくDFSをして、k番目までの文字列が操作によって元に戻らない時には打ち切る
 * という枝刈りをするとかなり早く通る
 */
