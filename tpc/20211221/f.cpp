#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int N;
ll r[100005];  // 点番号を入れると点に対するハッシュ値を返す
map<ll, int> mp;

ll rec(string &S, int &ind) {
    if (S[ind] == '(') {
        ind++;
        ll left = rec(S, ind);
        assert(S[ind] == ',');
        ind++;
        ll right = rec(S, ind);
        assert(S[ind] == ')');
        ind++;
        ll ret = left ^ right;  // left集合とright集合の和集合のハッシュ値を計算
        mp[ret]++;
        return ret;
    } else {
        // s[ind]='1'~'9'
        int c = 0;
        while (S[ind] != ',' and S[ind] != ')') {
            c = c * 10 + (S[ind] - '0');
            ind++;
        }
        mp[r[c]]++;
        return r[c];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());
    uniform_int_distribution<ll> dist(0, INT64_MAX);
    cin >> N;
    rep(i, N + 1) r[i] = dist(rnd);
    string S, T;
    cin >> S >> T;
    int indS = 0, indT = 0;
    rec(S, indS);
    rec(T, indT);
    int ans = 0;
    for (auto p : mp) {
        assert(p.second <= 2);
        if (p.second == 2) ans++;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 構文解析
 * Zobrist Hash
 * できる集合と構文木の葉または合流点は一対一対応する
 * Zobrist Hash で集合に対してハッシュ値を計算し、mapに記録することで
 * 集合同士の一致判定を高速に行うことができる
 */
