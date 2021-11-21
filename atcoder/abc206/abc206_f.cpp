#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int N, L[105], R[105], grandy[105][105];

int rec1(int l, int r) {
    if (grandy[l][r] != -1) return grandy[l][r];
    if (l >= r) return 0;
    set<int> s;
    rep(i, N) {
        if (l <= L[i] && R[i] <= r) {
            int c = 0;
            c ^= rec1(l, L[i]);
            c ^= rec1(R[i], r);
            s.insert(c);
        }
    }
    int g = 0;
    while (s.count(g) != 0) g++;
    return grandy[l][r] = g;
}

void solve() {
    cin >> N;
    rep(i, 105) rep(j, 105) grandy[i][j] = -1;
    rep(i, N) cin >> L[i] >> R[i];
    int a = rec1(0, 100);
    puts(a ? "Alice" : "Bob");
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

/*
解説AC?
Grundy数はゲームをいくつかの小さなゲームに分割できるときに使われる
TwitterでGrundy数というキーワードが見えてしまい、蟻本を読みながら考えた
（問題の解説は読んでいない）
蟻本p.284「状態が分裂した場合、それらの各状態のGrundy数のXORを取ったものと、
分裂前の状態のGrundy数は同じ」とある
よって、[l,r)に対してある区間[L[i],R[i])を置いたときのGrundy数を求められる。
あとは各区間を置いたときを全て考えると、それらのGrundy数には遷移できるということになる
よって、[l,r)のGrundy数は、遷移先に出現しない最小のGrundy数ということになる
最後に、[0,100)に対するGrundy数が0以外の時は、先手が0にして、後手が0以外にして…となるので先手の勝ち
0のときは、先手が0以外にして、後手が0にして…となるので後手の勝ち
*/