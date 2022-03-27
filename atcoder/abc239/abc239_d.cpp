#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) begin(x), end(x)
template <class T> using V = vector<T>;

vector<bool> Era(int n) {
    vector<bool> isprime(n + 1, 1);
    isprime[0] = 0;
    isprime[1] = 0;
    for (int i = 2; i < n + 1; i++) {
        if (isprime[i]) {
            for (int j = 2 * i; j < n + 1; j += i) isprime[j] = 0;
        }
    }
    return isprime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    int win = 0;
    auto jud = Era(10000);
    for (ll x = A; x <= B; x++) {
        int ok = 0;
        for (ll y = C; y <= D; y++) {
            if (jud[x + y]) {
                ok = 1;
                break;
            }
        }
        if (ok == 0) {
            win = 1;
            break;
        }
    }
    cout << (win ? "Takahashi" : "Aoki") << '\n';
    return 0;
}

/**
 * エラトステネスの篩を使って高速に素数判定ができるようにしてから
 * 全探索する
 */
