#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int INF = 1 << 30;

int N, M;
int a[52], b[52];
int seen[52][52][52][52][2][2], memo[52][52][52][52][2][2];

int rec(int at, int ab, int bt, int bb, int trn, int pc) {
    if (seen[at][ab][bt][bb][trn][pc]) return memo[at][ab][bt][bb][trn][pc];
    if (trn == 0) {
        // 先手
        int ret = -INF;
        // 自分のデッキの一番上のカードをスタックの一番上に置く
        if (at < N) {
            int x;
            if (a[at] == -1)
                x = rec(at + 1, ab, bt, bt, 1, 0);
            else
                x = rec(at + 1, ab, bt, bb, 1, 0);
            ret = max(ret, x);
        }
        // 自分のターンをパスする
        int y = 0;
        for (int i = ab; i < at; i++) y += (a[i] == -1 ? 0 : a[i]);
        for (int i = bb; i < bt; i++) y -= (b[i] == -1 ? 0 : b[i]);
        if (at != ab || bt != bb) {
            y += rec(at, at, bt, bt, 1, 0);
        } else if (pc == 0) {
            y += rec(at, at, bt, bt, 1, 1);
        }
        ret = max(ret, y);
        seen[at][ab][bt][bb][trn][pc] = 1;
        return memo[at][ab][bt][bb][trn][pc] = ret;
    } else {
        // 後手
        int ret = INF;
        // 自分のデッキの一番上のカードをスタックの一番上に置く
        if (bt < M) {
            int x;
            if (b[bt] == -1)
                x = rec(at, at, bt + 1, bb, 0, 0);
            else
                x = rec(at, ab, bt + 1, bb, 0, 0);
            ret = min(ret, x);
        }
        // 自分のターンをパスする
        int y = 0;
        for (int i = ab; i < at; i++) y += (a[i] == -1 ? 0 : a[i]);
        for (int i = bb; i < bt; i++) y -= (b[i] == -1 ? 0 : b[i]);
        if (at != ab || bt != bb) {
            y += rec(at, at, bt, bt, 0, 0);
        } else if (pc == 0) {
            y += rec(at, at, bt, bt, 0, 1);
        }
        ret = min(ret, y);
        seen[at][ab][bt][bb][trn][pc] = 1;
        return memo[at][ab][bt][bb][trn][pc] = ret;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];
    cout << rec(0, 0, 0, 0, 0, 0) << endl;
    return 0;
}

/*
スタックを2つに分ける
今各デッキのトップにあるカードと、スタックの一番下にあるカード
の4情報をもってdp
さらに今どっちのターンかと、何回スタックが空の状態でスキップしたかも必要
*/
