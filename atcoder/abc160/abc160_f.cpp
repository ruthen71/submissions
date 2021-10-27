#include <bits/stdc++.h>
using namespace std;

// clang-format off
#include <atcoder/modint>
using namespace atcoder;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vii = vector<int>;
using vll = vector<ll>;
using vdd = vector<ld>;
using vvii = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvdd = vector<vector<ld>>;
using vvvii = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<ll>>>;
using vvvdd = vector<vector<vector<ld>>>;
template<class T, class U> using P = pair<T, U>;
template<class T> using V1 = vector<T>;
template<class T> using V2 = vector<vector<T>>;
template<class T> using V3 = vector<vector<vector<T>>>;
template<class T> using pque = priority_queue<T, vector<T>, greater<T>>;
#define _overload3(_1, _2, _3, name, ...) name
#define rep1(n) for (ll i = 0; i < (n); i++)
#define rep2(i, n) for (ll i = 0; i < (n); i++)
#define rep3(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(...) _overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for (ll i = (n) - 1; i >= 0; i--)
#define rrep2(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rrep3(i, a, b) for (ll i = (b) - 1; i >= (a); i--)
#define rrep(...) _overload3(__VA_ARGS__, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define popcnt(x) __builtin_popcountll(x)
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end());
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
const int inf = 1 << 30;
const ll INF = 1ll << 60;
const ld DINF = numeric_limits<ld>::infinity();
const ll mod = 1000000007;
//const ll mod = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932;
//const ll dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const ll dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<typename T> T minV(const vector<T> &x) { return *min_element(all(x)); }
template<typename T> T maxV(const vector<T> &x) { return *max_element(all(x)); }
template<class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { return os << "(" << p.fi << ", " << p.se << ")"; }
template<class T> ostream &operator<<(ostream &os, const vector<T> &v) { os << "[ "; for (auto &z : v) os << z << " "; os << "]"; return os; }
#ifdef _DEBUG
#define show(x) cout << #x << " = " << x << endl;
#else
#define show(x)
#endif
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll rem(ll a, ll b) { return (a % b + b) % b; }
// clang-format on

// using mint = modint998244353;
using mint = modint1000000007;
ostream &operator<<(ostream &os, const mint &p) { return os << p.val(); }

ll modpow(ll a, ll N, ll mod) {
    ll res = 1;
    // 例えば3=101(2)なので、下位bitから順に1ならa倍する
    while (N) {
        if (N & 1) res = res * a % mod;
        a = a * a % mod;
        N >>= 1;
    }
    return res;
}

struct edge {
    ll to, cost;
};

mint facl[200005], facl_inv[200005];

// 頂点0(0-indexed)からの答えを求める
// dp[i] = iを根とする部分木の答え
// siz[i] = iを根とする部分木のサイズ
void dfs1(V2<edge> &g, int cur, int par, vector<ll> &siz, vector<mint> &dp) {
    for (edge &es : g[cur]) {
        if (es.to == par) continue;
        dfs1(g, es.to, cur, siz, dp);
        siz[cur] += siz[es.to];
        dp[cur] *= facl_inv[siz[es.to]];
        dp[cur] *= dp[es.to];
    }
    dp[cur] *= facl[siz[cur] - 1];
    return;
}
// 全方位木DPをする
// だいたいdp[es.to]に必要となる値は格納されている
void dfs12(V2<edge> &g, int cur, int par, vector<ll> &siz, vector<mint> &dp, vector<mint> &ans, mint d_par) {
    ll siz_sum = 0;
    for (edge &es : g[cur]) {
        // 基本的にはelseの処理をする
        if (es.to == par) {
            ans[cur] *= d_par;
        } else {
            ans[cur] *= dp[es.to];
            ans[cur] *= facl_inv[siz[es.to]];
            siz_sum += siz[es.to];
        }
    }
    ans[cur] *= facl_inv[sz(g) - 1 - siz_sum];

    for (edge &es : g[cur]) {
        if (es.to == par) continue;
        mint nx = ans[cur];
        nx *= facl[siz[es.to]] / dp[es.to] * facl[sz(g) - 1 - siz[es.to]] * facl_inv[sz(g) - 1];
        dfs12(g, es.to, cur, siz, dp, ans, nx);
    }
}

int main() {
    // 前計算(階乗)
    facl[0] = facl_inv[0] = 1;
    rep(i, 1, 200005) {
        facl[i] = facl[i - 1] * i;
        facl_inv[i] = 1 / facl[i];
    }

    ll n;
    cin >> n;
    V2<edge> g(n);
    rep(i, n - 1) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        g[s].push_back({t, 1});
        g[t].push_back({s, 1});
    }
    vector<mint> ans(n, facl[n - 1]), dp(n, 1);
    vll siz(n, 1);
    dfs1(g, 0, -1, siz, dp);
    show(dp);
    show(siz);
    dfs12(g, 0, -1, siz, dp, ans, 1);
    show(ans);
    rep(i, n) { cout << ans[i].val() << endl; }

    return 0;
}

/*
全方位木DP
参考
https://ei1333.hateblo.jp/entry/2017/04/10/224413
親からの部分木に対するdp[par]をd_parに格納する
この計算方法がちょっと難しい

*/
