#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define popcnt(x) __builtin_popcountll(x)

int N, K;

int f(int i, int j) { return i * N + j; }

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    cin >> N >> K;
    vector<string> s(N);
    rep(i, N) cin >> s[i];
    map<ull, int> seen;
    queue<ull> que;
    rep(i, N) rep(j, N) {
        if (s[i][j] != '#') {
            ull x = (1ull << f(i, j));
            que.push(x);
        }
    }
    while (!que.empty()) {
        ull c = que.front();
        que.pop();
        if (seen[c]) continue;
        seen[c] = 1;
        if (popcnt(c) >= K) continue;
        rep(i, N) rep(j, N) {
            if ((c >> f(i, j) & 1) == 0 && s[i][j] != '#') {
                // 周辺4マスに塗ったやつがあるか見る
                rep(k, 4) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) continue;
                    if ((c >> f(nx, ny) & 1) == 1) {
                        ull nex = (c | (1ull << f(i, j)));
                        if (seen[nex]) continue;
                        que.push(nex);
                        break;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (auto mpi : seen) {
        if (popcnt(mpi.first) == K) ans++;
    }
    cout << ans << endl;
    return 0;
}

/*
解説AC
ポリオミノ
サンプルやwikipediaを見ると意外と種類数が少ないことが分かるので、全探索できる
次埋めるマスは埋まっているマスに隣接していなければならないが、その判定は
・全部のマスを見て、埋まってなくてかつ周囲4マスのいずれかが埋まっている
でできる
すでに埋まっているマス目線で考えてしまうが、ここで新たに埋めるマス目線で考えるのが重要
*/