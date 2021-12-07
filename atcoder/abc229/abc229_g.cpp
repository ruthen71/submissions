#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    string S;
    cin >> S;
    ll K;
    cin >> K;
    ll len = S.size();
    vector<ll> C;
    rep(i, len) if (S[i] == 'Y') C.push_back(i);
    int n = C.size();
    if (n == 0) return puts("0") & 0;
    vector<ll> D(n);
    rep(i, n) D[i] = C[i] - i;
    vector<ll> Dc(n + 1, 0);
    rep(i, n) Dc[i + 1] = Dc[i] + D[i];
    ll ok = 1, ng = n + 1;
    while (ng - ok > 1) {
        ll md = (ok + ng) / 2;
        ll cmin = 1ll << 60;
        for (int k = 0; k <= n - md; k++) {
            // calc
            ll x = D[k + md / 2];  // [k,k+md-1]のDの中央値
            int ind = k + md / 2;
            ll cost = x * (ind - k) - (Dc[ind] - Dc[k]) + (Dc[k + md] - Dc[ind]) - x * (k + md - ind);
            cmin = min(cmin, cost);
        }
        if (cmin <= K)
            ok = md;
        else
            ng = md;
    }
    cout << ok << '\n';
    return 0;
}

/**
 * 解説AC
 * 公式解説は読んでいないが、Twitterで解法ツイートの断片をいくつか見てしまった
 * 答え決め打ち二分探索
 * 累積和で高速化
 * マンハッタン距離の最小化は中央値
 * sample 1の場合の答えを決め打ったあとの処理を説明する
 * md=3とする(mdは二分探索の答えを決め打った値)
 * C[i]=i個目のYが出てくるindex(iもindexも0-indexed)とすると
 * C=[0 1 5 7 9]
 * 隣接する3(md)要素についてのみ考えれば良いから
 * 0,1,2個目のYか、1,2,3個目のYか、2,3,4個目のYを連結にすることを考える
 * k=0,1,2として、xをk個目のYを置く位置とすると
 * cost0=abs(C[0]-(x+0))+abs(C[1]-(x+1))+abs(C[2]-(x+2))
 * cost1=abs(C[1]-(x+0))+abs(C[2]-(x+1))+abs(C[3]-(x+2))
 * cost2=abs(C[2]-(x+0))+abs(C[3]-(x+1))+abs(C[4]-(x+2))
 * cost1においてx=x'+1とおくと(平行移動のイメージ)
 * cost1=abs(C[1]-(x'+1))+abs(C[2]-(x'+2))+abs(C[3]-(x'+3))
 * cost2においてx=x''+2とおくと
 * cost2=abs(C[2]-(x''+2))+abs(C[3]-(x''+3))+abs(C[4]-(x''+4))
 * D[i]=C[i]-iとおくと
 * cost0=abs(D[0]-x)+abs(D[1]-x)+abs(D[2]-x)
 * cost1=abs(D[1]-x')+abs(D[2]-x')+abs(D[3]-x')
 * cost2=abs(D[2]-x'')+abs(D[3]-x'')+abs(D[4]-x'')
 * マンハッタン距離の最小化より、
 * cost0はx=D[1]で、cost1はx=D[2]で、cost2はx=D[3]で最小となる
 * 実際に最小値を計算するときは、absの中身が負になる部分と0以上になる部分で分けて行う
 * (xがDの要素と分かったので累積和を使うと案外簡単)
 */