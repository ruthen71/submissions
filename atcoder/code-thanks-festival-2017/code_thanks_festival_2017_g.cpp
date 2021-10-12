#include <bits/stdc++.h>
using namespace std;

// clang-format off
//#include <atcoder/modint>
//using namespace atcoder;
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
const ll dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const ll dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
// using mint = modint1000000007;

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

int main() {
    ll N, M;
    cin >> N >> M;
    vll a(M), b(M);
    rep(M) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    ll N2 = N / 2;
    vll dp((1 << N2), 0);
    rep(i, (1 << N2)) {
        int ok = 1;
        rep(j, M) {
            if ((i >> a[j] & 1) && (i >> b[j] & 1)) {
                ok = 0;
                break;
            }
        }
        if (ok) chmax(dp[i], (ll)popcnt(i));
        rep(j, N2) chmax(dp[i | (1 << j)], dp[i]);
    }
    ll ans = 0;
    rep(i, (1 << (N - N2))) {
        ll bit = i << N2;
        int ok = 1;
        ll ind = 0;
        rep(j, M) {
            if (bit >> b[j] & 1) {
                if (bit >> a[j] & 1) {
                    ok = 0;
                    break;
                } else if (a[j] < N2) {
                    ind |= (1 << a[j]);
                }
            }
        }
        if (ok == 0) continue;
        chmax(ans, popcnt(i) + dp[(1 << N2) - 1 - ind]);
    }
    cout << ans << endl;

    return 0;
}

/*
メモ
半分全列挙
一般グラフの最大安定集合問題
O(M2^(N/2))
頂点集合を2つに分ける(V1,V2とする)
dp[i] = 頂点集合i(in V1)について、iの最大独立集合のサイズ
各iからi|(1<<j)(0<=j<size(V1))にだけdpの更新を行えば十分
もしiが最大独立集合ならdp[i]=size(i)だし、そうでないときには上記の更新でsize(i)より
小さな値だがdp[i]にはちゃんと値が入ってる
V2についても各頂点集合iに対し、iが独立集合じゃなかったらアウト、独立集合なら
M個の条件から含めてはいけないV1の頂点を列挙し、前計算したdpの値を使い、和を計算

O(N2^(N/2))解もある

int main() {
    ll N, M;
    cin >> N >> M;
    vvll g(N);
    rep(M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    ll N2 = N / 2;
    vii ok((1 << N2), 1);
    rep(i, N2) {
        for (auto ee : g[i]) {
            if (ee < N2) ok[(1 << i) + (1 << ee)] = 0;
        }
    }
    rep(i, (1 << N2)) {
        if (ok[i] == 0) {
            rep(j, N2) ok[i | (1 << j)] = 0;
        }
    }
    ll N3 = N - N2;
    vii set((1 << N2), (1 << N3) - 1);
    rep(i, N2) {
        for (auto ee : g[i]) {
            if (ee >= N2) set[1 << i] -= (1 << (ee - N2));
        }
    }
    rep(i, (1 << N2)) { rep(j, N2) set[i | (1 << j)] = set[i] & set[1 << j]; }
    vii ok2((1 << N3), 1);
    rep(i, N3) {
        for (auto ee : g[i + N2]) {
            if (ee >= N2) ok2[(1 << i) + (1 << (ee - N2))] = 0;
        }
    }
    rep(i, (1 << N3)) {
        if (ok2[i] == 0) {
            rep(j, N3) ok2[i | (1 << j)] = 0;
        }
    }
    vii dp(1 << N3, 0);
    rep(i, 1 << N3) if (ok2[i]) dp[i] = popcnt(i);
    rep(i, 1 << N3) rep(j, N3) chmax(dp[i | (1 << j)], dp[i]);
    int ans = 0;
    rep(i, 1 << N2) {
        if (ok[i]) chmax(ans, popcnt(i) + dp[set[i]]);
    }
    cout << ans << endl;
    return 0;
}

*/
