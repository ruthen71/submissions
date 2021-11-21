#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll modpow(ll a, ll N, ll mod) {
    a %= mod;
    ll res = 1;
    while (N) {
        if (N & 1) res = res * a % mod;
        a = a * a % mod;
        N >>= 1;
    }
    return res;
}

const ll MOD = 998244353ll;

int main() {
    ll N, K, M;
    cin >> N >> K >> M;
    ll beki = modpow(K, N, MOD - 1);
    if (M % MOD == 0) {
        return puts("0") & 0;
    }
    ll ans = modpow(M, beki, MOD);
    cout << ans << endl;
    return 0;
}

/*
まずx=K^N(modP-1)を求めてから、M^x(modP)を求める
P=998244353
*/