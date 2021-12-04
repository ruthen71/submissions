#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

const int INF = 1 << 30;

int dp[205][205];
int N;
string S;
vector<int> ps;

int rec(int l, int r) {
    // [l, r)
    if (dp[l][r] != -1) return dp[l][r];
    if (r - l <= 1) return dp[l][r] = 1;
    int ret = INF;
    for (int m = l + 1; m < r; m++) ret = min(ret, rec(l, m) + rec(m, r));
    int L = r - l;
    for (auto &pi : ps) {
        if (pi > L) break;
        if (L % pi != 0) continue;
        int c = L / pi;  // 1つ分の長さ
        int ok = 1;
        rep(i, pi) if (S.substr(l + i * c, c) != S.substr(l, c)) ok = 0;
        if (ok) ret = min(ret, rec(l, l + c));
    }
    return dp[l][r] = ret;
}

vector<int> Era_list(int n) {
    vector<int> isprime(n + 1, 1);
    vector<int> res;
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) {
            res.push_back(i);
            for (int j = 2 * i; j < n + 1; j += i) isprime[j] = 0;
        }
    }
    return res;
}

int main() {
    ps = Era_list(100);
    cin >> S;
    N = S.size();
    rep(i, N + 5) rep(j, N + 5) dp[i][j] = -1;
    int ans = rec(0, N);
    cout << ans << '\n';
    return 0;
}

/**
 * メモ化dp
 * 区間DP、区間dp
 * AA=A^2みたいな表現方法を使って与えられた文字列を別の方法で表すことを考える
 * もっともアルファベット数が少なくなるときのアルファベット数を求めよ
 * dp[l][r]=S[l:r]を表すのに使うアルファベット数として、メモ化再帰する
 * dp[l][r]の計算では、dp[l][m]+dp[m][r](m=l+1,...,r-1)の最小値と
 * S[l:r]をd分割できるか(できるときにはdp[l][l+d])の最小値を使う
 * dは素数だけで良いとかで枝刈りしたら通った(いらないかも)
 */