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
    // ?????????3=101(2)??????????????????bit????????????1??????a?????????
    while (N) {
        if (N & 1) res = res * a % mod;
        a = a * a % mod;
        N >>= 1;
    }
    return res;
}

int compress(vii &x1, vii &x2, int w) {
    int N = sz(x1);
    vii xs;
    rep(i, N) {
        rep(d, 0, 2) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            if (0 <= tx1 && tx1 < w) xs.pb(tx1);
            if (0 <= tx2 && tx2 < w) xs.pb(tx2);
        }
    }
    sort(all(xs));
    uniq(xs);
    rep(i, N) {
        x1[i] = lower_bound(all(xs), x1[i]) - xs.begin();
        x2[i] = lower_bound(all(xs), x2[i]) - xs.begin();
    }
    return sz(xs);
}

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vii X1(N), X2(N), Y1(N), Y2(N);
    rep(i, N) cin >> X1[i] >> X2[i] >> Y1[i] >> Y2[i];
    vvii grid(H, vii(W, 0));
    rep(i, N) rep(x, X1[i], X2[i] + 1) rep(y, Y1[i], Y2[i] + 1) grid[x][y] = 1;

    int h = compress(X1, X2, H);
    int w = compress(Y1, Y2, W);
    show(w);
    show(h);
    vvii grid2(h, vii(w, 0));
    rep(i, N) rep(x, X1[i], X2[i] + 1) rep(y, Y1[i], Y2[i] + 1) grid2[x][y] = 1;
    puts("grid");
    rep(i, H) {
        rep(j, W) {
            if (grid[i][j])
                cout << '#';
            else
                cout << '.';
        }
        cout << endl;
    }
    puts("grid2");
    rep(i, h) {
        rep(j, w) {
            if (grid2[i][j])
                cout << '#';
            else
                cout << '.';
        }
        cout << endl;
    }
    return 0;
}

/*
??????
??????
????????????????????????
d???+0???+1???????????????OK

*/
