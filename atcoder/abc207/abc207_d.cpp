#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

const ld EPS = 1e-10;
const ld PI = 3.1415926535897932;

int main() {
    int N;
    cin >> N;
    vector<complex<ld>> P(N), Q(N);
    rep(i, N) {
        ld a, b;
        cin >> a >> b;
        P[i] = {a, b};
    }
    rep(i, N) {
        ld a, b;
        cin >> a >> b;
        Q[i] = {a, b};
    }
    complex<ld> G1 = {0, 0}, G2 = {0, 0};
    rep(i, N) G1 += P[i];
    rep(i, N) G2 += Q[i];
    G1 /= N, G2 /= N;
    rep(i, N) P[i] -= G1;
    rep(i, N) Q[i] -= G2;
    vector<complex<ld>> PP, QQ;
    rep(i, N) if (abs(P[i]) > EPS) PP.push_back(P[i]);
    rep(i, N) if (abs(Q[i]) > EPS) QQ.push_back(Q[i]);
    if (PP.size() != QQ.size()) return puts("No") & 0;
    N = PP.size();
    if (N == 0) return puts("Yes") & 0;
    sort(PP.begin(), PP.end(), [](complex<ld> i, complex<ld> j) {
        if (arg(i) != arg(j)) return arg(i) < arg(j);
        return abs(i) < abs(j);
    });
    sort(QQ.begin(), QQ.end(), [](complex<ld> i, complex<ld> j) {
        if (arg(i) != arg(j)) return arg(i) < arg(j);
        return abs(i) < abs(j);
    });
    int ok = 0;
    rep(i, N) {
        // P[0]とQ[i]が一致するとする
        if (abs(abs(QQ[i]) - abs(PP[0])) > EPS) continue;
        int ok2 = 1;
        rep(j, N) {
            // P[j]とQ[j+i]の一致を判定
            ld d1 = abs(PP[j]), d2 = abs(QQ[(i + j) % N]);
            if (abs(d1 - d2) > EPS) ok2 = 0;
            ld r1 = arg(PP[j] / PP[0]), r2 = arg(QQ[(i + j) % N] / QQ[i]);
            ld r12 = fmodl(r2 - r1, PI);
            if (abs(r12) > EPS) ok2 = 0;
        }
        if (ok2) ok = 1;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}

/*
コンテスト終了後自力AC
ABC022-D Big Bangを解いていたこともあって重心を使うのはすぐに思いついた
なぜか拡大縮小ができると勘違いしていた
ハマりポイント
・偏角ソートしたときに偏角が同じだとどうするか(距離でソートする)
・fmodlの使い忘れ
・重心といずれかの点が一致する(argの計算でゼロ除算になる？)
複素数に関してもう少し詳しくなると良いと思った
*/
