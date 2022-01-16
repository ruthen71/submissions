#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int rec(string &s1, string &s2, int ind) {
    if (ind >= s1.size()) return 0;
    int ret = 100;
    if (s1[ind] == s2[ind]) {
        ret = min(ret, rec(s1, s2, ind + 1));
    }
    int d = (s2[ind] - s1[ind] + 10) % 10;
    for (int i = ind; i < s1.size(); i++) {
        s1[i] = '0' + (s1[i] - '0' + d) % 10;
        ret = min(ret, rec(s1, s2, ind + 1) + 1);
    }
    for (int i = ind; i < s1.size(); i++) {
        s1[i] = '0' + (s1[i] - '0' - d + 10) % 10;
    }
    return ret;
}

void solve(int N) {
    string s1, s2;
    cin >> s1 >> s2;
    cout << rec(s1, s2, 0) << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while (cin >> N, N) solve(N);
    return 0;
}

/**
 * 解説AC
 * 左側からそろえるとして、各数を一致させるときに行った操作を
 * 「どこまで伸ばすか」を全探索することができる
 * マルチテストケースのK=10なので、O(K!)は厳しそうなどと考えて、bitDPでできないか考えてしまった…
 */
