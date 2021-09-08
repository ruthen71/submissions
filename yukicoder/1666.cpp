#include <bits/stdc++.h>
using namespace std;

// clang-format off
//#include <atcoder/all>
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
template<typename T> T min(const vector<T> &x) { return *min_element(all(x)); }
template<typename T> T max(const vector<T> &x) { return *max_element(all(x)); }
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

ll mysqrt(ll x) {
    ll lb = 1, ub = inf;
    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        if (mid * mid <= x)
            lb = mid;
        else
            ub = mid;
    }
    return lb;
}

bool isRoot(ll x) {
    ll res = mysqrt(x);
    return (res * res == x);
}

void solve(vll &b3) {
    ll k;
    cin >> k;
    // x以下の累乗数がcnt(x)個ある
    // cnt(x) >= Kとなるxの最小値
    // (lb, ub]
    ll ub = INF, lb = 0;
    while (ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        ll cnt = upper_bound(all(b3), mid) - b3.begin();
        cnt += mysqrt(mid);
        if (cnt >= k)
            ub = mid;
        else
            lb = mid;
    }
    cout << ub << endl;
    return;
}

int main() {
    vll b3;
    rep(a, 2, 1000001) {
        ll x = a * a * a;
        while (1) {
            if (!isRoot(x)) b3.pb(x);
            if (x > INF / a) break;
            x *= a;
        }
    }
    sort(all(b3));
    uniq(b3);
    int t;
    cin >> t;
    while (t--) solve(b3);
    return 0;
}

/*
メモ
二分探索
b>=3の場合でa^2の形で表せないものを前もって列挙する
b>=3よりa<=10^6まで考えれば良いので全部列挙できる
ある数xより小さい累乗数は
b=2のものはsqrt(x)で、b>=3は全列挙したものから二分探索することで求められる
(ll)sqrt(x)はxが大きいとめちゃくちゃ誤差が出るので自作する
オーバーフロー判定は
a,b,xが正の整数なら
ab>x <-> x > floor(b/a)=b//a
*/
