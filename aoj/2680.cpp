#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

string S;
string memo[55][55];
int seen[55][55];

string f(string s1, string s2) {
    if (s1.size() > s2.size()) return s1;
    if (s1.size() < s2.size()) return s2;
    int m = s1.size();
    for (int i = 0; i < m; i++) {
        if (s1[i] > s2[i]) return s1;
        if (s1[i] < s2[i]) return s2;
    }
    return s1;
}

string rec(int l, int r) {
    if (seen[l][r]) return memo[l][r];
    if (l == r) return "";
    int nd = 0;
    for (int i = l; i < r; i++) {
        if (!(('0' <= S[i] && S[i] <= '9') || S[i] == '?')) {
            nd = 1;
        }
    }
    if (nd == 0) {
        // 小細工せずに全部9で埋めるのが最強
        string t = "";
        for (int i = l; i < r; i++) {
            if (S[i] == '?')
                t += '9';
            else
                t += S[i];
        }
        seen[l][r] = 1;
        if (t.size() >= 2 && t[0] == '0') {
            // leading zero
            return memo[l][r] = "";
        }
        return memo[l][r] = t;
    }
    if ((S[l] == 'L' || S[l] == 'R' || S[l] == '?') && (S[l + 1] == '(' || S[l + 1] == '?') && (S[r - 1] == ')' || S[r - 1] == '?')) {
        // L(x,y)やR(x,y)を試す
        string t = "";
        for (int i = l + 3; i < r - 2; i++) {
            if (S[i] != ',' && S[i] != '?') continue;
            string L = rec(l + 2, i);
            string R = rec(i + 1, r - 1);
            if (L == "" || R == "") continue;
            if (S[l] == 'L')
                t = f(t, L);
            else if (S[l] == 'R')
                t = f(t, R);
            else
                t = f(t, f(L, R));
        }
        seen[l][r] = 1;
        return memo[l][r] = t;
    } else {
        seen[l][r] = 1;
        return "";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> S;
    int N = S.size();
    rep(i, 55) rep(j, 55) memo[i][j] = "";
    string res = rec(0, N);
    cout << (res == "" ? "invalid" : res) << '\n';
    return 0;
}

/**
 * 構文解析+区間DP+メモ化再帰
 */
