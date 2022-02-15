#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    map<ll, ll> mp;
    rep(i, N) {
        auto res = prime_list(A[i]);
        map<ll, ll> mp2;
        for (auto &d : res) mp2[d]++;
        for (auto &p : mp2) mp[p.first] = max(mp[p.first], p.second);
    }
    mint ans = 1;
    for (auto &p : mp) {
        mint x = p.first;
        ans *= x.pow(p.second);
    }
    mint inv = 0;
    rep(i, N) inv += (mint)1 / A[i];
    ans *= inv;
    cout << ans.val() << '\n';
    return 0;
}

/**
 * 最小公倍数をLとすると
 * ans=L(1/A[0]+1/A[1]+...+1/A[N-1])
 * 最小公倍数は連想配列で求める
 * 逆元はmodintで
 */
