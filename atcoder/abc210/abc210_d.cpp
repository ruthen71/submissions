#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll INF = 1ll << 60;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
    ll H, W, C;
    cin >> H >> W >> C;
    vector<vector<ll>> A(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    ll ans = INF;
    rep(i, H) {
        int id = 0;
        // id < j
        for (int j = 1; j < W; j++) {
            ans = min(ans, A[i][j] + A[i][id] + C * (j - id));
            if (A[i][id] - C * id > A[i][j] - C * j) id = j;
        }
    }
    vector<ll> Y(W);
    rep(j, W) Y[j] = A[H - 1][j] + C;
    for (int i = H - 2; i >= 0; i--) {
        int id = 0;
        // id <= j
        for (int j = 0; j < W; j++) {
            if (Y[id] - C * id > Y[j] - C * j) id = j;
            ans = min(ans, A[i][j] + Y[id] + C * (j - id));
        }
        reverse(Y.begin(), Y.end());
        reverse(A[i].begin(), A[i].end());
        id = 0;
        for (int j = 0; j < W; j++) {
            if (Y[id] - C * id > Y[j] - C * j) id = j;
            ans = min(ans, A[i][j] + Y[id] + C * (j - id));
        }
        reverse(Y.begin(), Y.end());
        reverse(A[i].begin(), A[i].end());
        rep(j, W) Y[j] = min(Y[j], A[i][j]) + C;
    }
    cout << ans << endl;
    return 0;
}

/*
解説AC
(解説の1行目だけ見た)
以下不等号の等号の有無に注意すること
一般性を失うことなく, i<=i'とできる

i=i'についてまず考える
一般性を失うことなく、j<j'とできる
このときコストはAj+Aj'+C(j'-j)(絶対値が外れる)
Aj-CjとAj'+Cj'に分離して、j'に着目しながらAj-Cjの累積minを更新することで各行につきO(W)でできる

次に、i<i'の場合
例えばsample 1の場合
まずi=1(9,6,3,7)に対してi'=2しかない(7 8 6 4)
(7 8 6 4) -> (9 10 8 6)(Cを足す)として、(9 10 8 6)と(9 6 3 7)から1つずつ選んで考えればOK
今度はj<j'のような制限が付けられない…と思いきや
j<=j'とj>=j'を両方やればOK
なのでi=1,i'=2の場合はできた
で、i=0(1 7 7 9)に対しては、i'=1,2があるが
どうせ最小値だけしか見ないので、min((9 10 8 6), (9 6 3 7)) = (9 6 3 6)にしてそれぞれにCを足す
(1 7 7 9)と(11 8 5 8)で考える
*/
