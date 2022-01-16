#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll X, Y, Z, A, B, C, N;
    cin >> X >> Y >> Z >> A >> B >> C >> N;
    vector<ll> ans(N, 0);
    // rep(i, X) rep(j, Y) rep(k, Z) ans[(abs(A - i) + abs(B - j) + abs(C - k)) % N]++;
    rep(i, X) ans[abs(i - A) % N]++;
    {
        // y方向
        ll y1 = B, y2 = Y - 1 - B;
        vector<ll> s1(N, 0);
        ll ind = N - 1;
        rep(i, y1) {
            s1[0] += ans[ind];
            ind = (ind - 1 + N) % N;
        }
        for (int i = N - 1; i > 0; i--) {
            s1[i] = s1[(i + 1) % N] - ans[i] + ans[ind];
            ind = (ind - 1 + N) % N;
        }
        vector<ll> s2(N, 0);
        ind = N - 1;
        rep(i, y2) {
            s2[0] += ans[ind];
            ind = (ind - 1 + N) % N;
        }
        for (int i = N - 1; i > 0; i--) {
            s2[i] = s2[(i + 1) % N] - ans[i] + ans[ind];
            ind = (ind - 1 + N) % N;
        }
        rep(i, N) ans[i] += s1[i] + s2[i];
    }
    {
        // z方向
        ll z1 = C, z2 = Z - 1 - C;
        vector<ll> s1(N, 0);
        ll ind = N - 1;
        rep(i, z1) {
            s1[0] += ans[ind];
            ind = (ind - 1 + N) % N;
        }
        for (int i = N - 1; i > 0; i--) {
            s1[i] = s1[(i + 1) % N] - ans[i] + ans[ind];
            ind = (ind - 1 + N) % N;
        }
        vector<ll> s2(N, 0);
        ind = N - 1;
        rep(i, z2) {
            s2[0] += ans[ind];
            ind = (ind - 1 + N) % N;
        }
        for (int i = N - 1; i > 0; i--) {
            s2[i] = s2[(i + 1) % N] - ans[i] + ans[ind];
            ind = (ind - 1 + N) % N;
        }
        rep(i, N) ans[i] += s1[i] + s2[i];
    }
    rep(i, N) { cout << ans[i] << (i == N - 1 ? '\n' : ' '); }
    return 0;
}

/**
 * FFT(Nがもっと大きいとき)
 * O(N+X+Y+Z)で解いたが、実はO(N^2+X+Y+Z)で良いのでもっと簡単に書ける
 * rep(i, n) rep(j, n) xres[(i + j) % n] += xsum[i] * ysum[j];
 * rep(i, n) rep(j, n) zres[(i + j) % n] += zsum[i] * xres[j];
 * という感じ
 * この計算を高速化するなら高速フーリエ変換(FFT)を使う
 */
