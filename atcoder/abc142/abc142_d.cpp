#include <bits/stdc++.h>
using namespace std;

vector<long long> prime_list(long long n) {
    vector<long long> res;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) res.push_back(n);
    return res;
}

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

ll gcd(ll A, ll B) { return B == 0 ? A : gcd(B, A % B); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll A, B;
    cin >> A >> B;
    vector<ll> ans = prime_list(gcd(A, B));
    sort(ALL(ans));
    ans.erase(unique(ALL(ans)), ans.end());
    cout << ans.size() + 1 << '\n';
    return 0;
}

/**
 * 最大公約数を求めて素因数分解して素数の種類数+1(1の分)を出力
 */