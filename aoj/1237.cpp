#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

vector<int> cut(string &S, int b) {
    vector<int> ret;
    int N = (int)S.size();
    int c = S[0] - '0';
    rep(i, N - 1) {
        if (b >> i & 1) {
            ret.push_back(c);
            c = S[i + 1] - '0';
        } else {
            c = c * 10 + S[i + 1] - '0';
        }
    }
    ret.push_back(c);
    return ret;
}

void solve(int &t, string &S) {
    int N = (int)S.size();
    int ans = -1, mul = 0;
    vector<int> ansv;
    rep(b, 1 << (N - 1)) {
        vector<int> res = cut(S, b);
        int s = 0;
        for (auto r : res) s += r;
        if (s > t) continue;
        if (ans < s) {
            ans = s;
            mul = 0;
            ansv = res;
        } else if (ans == s) {
            mul = 1;
        }
    }
    if (mul) {
        cout << "rejected\n";
    } else if (ans == -1) {
        cout << "error\n";
    } else {
        cout << ans;
        for (auto c : ansv) cout << " " << c;
        cout << '\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    string S;
    while (cin >> t >> S, t != 0 && S != "0") solve(t, S);
    return 0;
}

/**
 * bit全探索
 * 切るところをbit全探索する
 * errorやrejectedの判定がややめんどくさい
 */