#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int sig = 52;
const int V = sig * sig * sig;

int num(char &c) {
    if ('a' <= c && c <= 'z')
        return c - 'a';
    else
        return c - 'A' + 26;
}

int StoV(string s) {
    int ret = 0;
    rep(i, 3) ret = ret * sig + num(s[i]);
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    vector<vector<int>> G1(V), G2(V);
    vector<int> Gout(V, 0);

    rep(i, N) {
        int v = StoV(S[i].substr(0, 3)), u = StoV(S[i].substr(S[i].size() - 3, 3));
        G1[v].push_back(u);
        G2[u].push_back(v);
        Gout[v]++;
    }
    // 引き分け:-1, 負け:0, 勝ち:1
    vector<int> memo(V, -1), seen(V, 0);
    queue<int> que;
    rep(i, V) {
        if (Gout[i] == 0) {
            memo[i] = 0;
            que.push(i);
        }
    }
    while (!que.empty()) {
        int i = que.front();
        que.pop();
        if (seen[i]) continue;
        seen[i] = 1;
        if (memo[i] == 0) {
            // 今いるのは負けノード
            // 負けノードにいけるノードは全て勝ちノード
            for (int nx : G2[i]) {
                memo[nx] = 1;
                que.push(nx);
            }
        } else {
            // 今いるのは勝ちノード
            for (int nx : G2[i]) {
                Gout[nx]--;
                // ここで初めて出次数が0になったということは勝ちノードしか周りにないので負けノード
                if (Gout[nx] == 0) {
                    memo[nx] = 0;
                    que.push(nx);
                }
            }
        }
    }
    rep(i, N) {
        int v = StoV(S[i].substr(0, 3));
        int u = StoV(S[i].substr(S[i].size() - 3, 3));
        if (memo[u] == -1) {
            puts("Draw");
        } else if (memo[u] == 0) {
            puts("Takahashi");
        } else {
            puts("Aoki");
        }
    }
    return 0;
}

/*
ゲーム問題
グラフ
後退解析
有向グラフ上で移動ができなくなったら負け
後退解析できる
・1本も有向点が出ていない頂点は負け
・負け頂点に行ける頂点は勝ち頂点
・勝ち頂点にしかいけない頂点は負け頂点
・他は全て引き分け頂点
この辺のことを実装すると上記のようになる
*/