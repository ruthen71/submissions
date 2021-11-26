#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll INF = 1ll << 60;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll N, S, K;
        cin >> N >> S >> K;
        ll x, y;
        ll g = extgcd(K, N, x, y);
        if (S % g != 0) {
            cout << -1 << '\n';
        } else {
            ll ans = x * S / g;
            ans = -ans;
            ans %= N / g;
            if (ans < 0) ans += N / g;
            cout << ans << '\n';
        }
    }
    return 0;
}

/*
拡張ユークリッドの互除法、逆元
S+xK=yNとなる(x,y)のうちxが最小のものを求める問題に帰着する
まずg=gcd(K,N)として、Sがgの倍数じゃなかったらアウト
Sがgの倍数のとき、両辺をgで割ったものの解を1つ求める
正で最小となるように調整

別解
S+xK=0(modN)より
xK=-S(modN)
よってx=(-S)/K(modN)
両辺をgcd(N,K)で割っておく必要がある
(割らないといけなさそうだけどちゃんとその理由はわかってない)
*/