#include <bits/stdc++.h>
using namespace std;
// clang-format off
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
template <class T> using V = vector<T>;
// clang-format on

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll X;
    cin >> X;
    map<ll, mint> memo;
    auto rec = [&](auto self, ll X) -> mint {
        if (memo.count(X) != 0) return memo[X];
        if (X <= 4)
            return (mint)X;
        else
            return memo[X] = self(self, (X + 1) / 2) * self(self, X / 2);
    };
    cout << rec(rec, X).val() << '\n';
    return 0;
}

/**
 * メモ化
 * 再帰
 */