#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

char nxp[256], nxm[256];

string rec(string S, int l, int &r) {
    // l文字目以降を解析してえられた文字列を返す
    // どこまで読んだかをrに入れて返す(S[l:r-1]を読んだことになる)
    string ret = "";
    if (S[l] == '[') {
        l++;
        do {
            ret += rec(S, l, r);
            l = r;
        } while (S[l] != ']');
        reverse(ALL(ret));
        r++;
    } else if (S[l] == '+') {
        ret += rec(S, l + 1, r);
        ret[0] = nxp[ret[0]];
    } else if (S[l] == '-') {
        ret += rec(S, l + 1, r);
        ret[0] = nxm[ret[0]];
    } else {
        // alphabet
        r = l + 1;
        ret += S[l];
    }
    return ret;
}

void solve(string S) {
    int N = (int)S.size();
    int r = 0;
    string T = "";
    while (r != N) {
        int l = r;
        T += rec(S, l, r);
    }
    for (auto &Ti : T)
        if (Ti == '?') Ti = 'A';
    cout << T << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (char c = 'A'; c <= 'Y'; c++) {
        nxp[c] = c + 1;
    }
    for (char c = 'B'; c <= 'Z'; c++) {
        nxm[c] = c - 1;
    }
    nxp['Z'] = 'A';
    nxm['A'] = 'Z';
    nxp['?'] = nxm['?'] = '?';
    string S;
    while (cin >> S, S != ".") solve(S);
    return 0;
}

/**
 * 構文解析
 * ?は3個しかないので?の割当を全探索することもできるが
 * ?に+-を何回やっても?が得られるとして、最終的に得られた文字列の?を全てAにすればOK
 * 構文解析典型:S[l]によって場合分け
 * Stringが連結しうるので、何文字目まで解析したかを返させる(r)
 * ことで、r!=Nである間、構文解析を繰り返して結果を繋げる、としたほうが良い
 */