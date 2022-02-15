#include <bits/stdc++.h>
using namespace std;
// clang-format off
using ll = long long;
template <class T> using V = vector<T>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
// clang-format on

void solve(int m, int n) {
    V<string> s(n);
    rep(i, n) cin >> s[i];
    map<V<int>, int> mp;
    auto rec = [&](auto self, V<int> S) -> int {
        // S=候補の集合
        if (mp.count(S) != 0) return mp[S];
        if (S.size() <= 1) return mp[S] = 0;
        int ret = 1 << 30;
        rep(i, m) {
            V<int> S0, S1;
            for (auto j : S) {
                if (s[j][i] == '1') {
                    S1.push_back(j);
                } else {
                    S0.push_back(j);
                }
            }
            if (S == S1 || S == S0) continue;
            int cur = max(self(self, S0), self(self, S1)) + 1;
            ret = min(ret, cur);
        }
        return mp[S] = ret;
    };
    V<int> S;
    rep(i, n) S.push_back(i);
    cout << rec(rec, S) << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    while (cin >> m >> n, !(m == 0 && n == 0)) solve(m, n);
    return 0;
}

/**
 * メモ化再帰
 * ラムダ再帰
 * 集合Sに対する質問回数の最小値
 * としてdpする
 * 一見状態数が2^n通りあるように見えるが、集合の別れ方が3^m通りしかないので、間に合う
 * (選んだbitが1/0?あるいは選んでいないか)
 * たしかに毎回結果を見てから次の一手を選択できることにはなっているが
 * 結局選んだbitの集合に対してSは一意に定まるのがポイント
 * よってbitの状態がどういうものが今Sに入っているか？を考えると、bitの状態が3^mしかないので(以下略)
 */
