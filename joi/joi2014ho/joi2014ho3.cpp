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
const ll modd = 998244353;
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
#define show(x) cout << #x << " = " << x << endl;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll rem(ll a, ll b) { return (a % b + b) % b; }
// clang-format on

// using mint = modint998244353;

int main() {
    IOS;
    int n;
    cin >> n;
    vll a(n);
    rep(n) cin >> a[i];
    vll cum(2 * n + 1, 0);
    rep(i, 2 * n) { cum[i + 1] = cum[i] + a[i % n]; }
    cum.pb(cum[2 * n]);
    ll lb = 0, ub = INF;
    while (ub - lb > 1) {
        ll md = (ub + lb) / 2;
        int r = 0, ok = 0;
        rep(l, n) {
            while (r < l + n && cum[r] - cum[l] < md) r++;
            int r2 = lower_bound(all(cum), cum[r] + md) - cum.begin();
            ll s1 = cum[r] - cum[l];
            ll s2 = cum[r2] - cum[r];
            ll s3 = cum[l + n] - cum[r2];
            if (s1 >= md && s2 >= md && s3 >= md) ok = 1;
        }
        if (ok)
            lb = md;
        else
            ub = md;
    }
    cout << lb << endl;
    return 0;
}

/*
メモ
実装上、数列を2倍にすることで累積和を使いやすくする
「数列を3つに区切った時の和の最小値がx以上」
とするとxは単調になる(lb=0ではできる、ub=INFではできない)
左端lに対し、初めて和がxを超えるrを尺取りで求める
rは最小値だけ見れば良い(rを大きくしても残り部分の和が小さくなるだけなので、得をしないため)
残りの部分の和もxを超えるか(s3)
*/
