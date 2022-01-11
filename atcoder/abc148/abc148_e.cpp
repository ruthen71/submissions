#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    if (N & 1) {
        cout << 0 << '\n';
    } else {
        N /= 2;
        ll c = 5;
        ll ans = 0;
        while (c <= N) {
            ans += N / c;
            c *= 5;
        }
        cout << ans << '\n';
    }
    return 0;
}

/**
 * Nが奇数なら答えは0
 * そうでないとき、素因数5の個数を数える
 * N/=2してから5,25,125,...,で割っていくやつ(高校数学にある)
 *
 */