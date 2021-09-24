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
#define rep1(n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 0; i < (n); i++)
#define rep3(i, a, b) for (int i = (a); i < (b); i++)
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

bool stop = 0;

void solve() {
    int w, h, n;
    cin >> h >> w;
    if (h == 0 && w == 0) {
        stop = 1;
        return;
    }
    cin >> n;
    vii x1(n), y1(n), x2(n), y2(n);
    rep(n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    vii xs = {0, h}, ys = {0, w};
    rep(i, n) {
        int tx1 = x1[i], tx2 = x2[i];
        int ty1 = y1[i], ty2 = y2[i];
        if (0 <= tx1 && tx1 < h) xs.pb(tx1);
        if (0 <= tx2 && tx2 < h) xs.pb(tx2);
        if (0 <= ty1 && ty1 < w) ys.pb(ty1);
        if (0 <= ty2 && ty2 < w) ys.pb(ty2);
    }
    sort(all(xs));
    sort(all(ys));
    uniq(xs);
    uniq(ys);
    rep(i, n) {
        x1[i] = lower_bound(all(xs), x1[i]) - xs.begin();
        x2[i] = lower_bound(all(xs), x2[i]) - xs.begin();
        y1[i] = lower_bound(all(ys), y1[i]) - ys.begin();
        y2[i] = lower_bound(all(ys), y2[i]) - ys.begin();
    }
    int H = lower_bound(all(xs), h) - xs.begin(), W = lower_bound(all(ys), w) - ys.begin();
    vvii fld(H + 2, vii(W + 2, 0));
    rep(i, n) {
        fld[x1[i] + 1][y1[i] + 1]++;
        fld[x1[i] + 1][y2[i] + 1]--;
        fld[x2[i] + 1][y1[i] + 1]--;
        fld[x2[i] + 1][y2[i] + 1]++;
    }
    rep(x, H + 1) rep(y, W + 1) fld[x + 1][y + 1] += fld[x][y + 1] + fld[x + 1][y] - fld[x][y];
    show(fld);
    int ans = 0;
    rep(x, 1, H + 1) {
        rep(y, 1, W + 1) {
            if (fld[x][y]) continue;
            ans++;
            queue<pii> que;
            que.push(make_pair(x, y));
            while (!que.empty()) {
                int cx = que.front().fi, cy = que.front().se;
                que.pop();
                rep(i, 4) {
                    int nx = cx + dx[i], ny = cy + dy[i];
                    if (!(1 <= nx && nx <= H && 1 <= ny && ny <= W)) continue;
                    if (fld[nx][ny]) continue;
                    que.push(make_pair(nx, ny));
                    fld[nx][ny] = 1;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    // IOS;
    solve();
    return 0;
}

/*
メモ
座標圧縮
2次元座圧する
2次元座圧
配列に対応させると(X1,Y1)が領域内、(X2,Y2)が余白部分に対応するので
蟻本の例題のように複数行見なくてOK
蟻本p151~の実装を参考に
*/

/*
上記のはAtCoder用(MLが64MBなのでズルで通している)
ズル：n<=50のときだけ丁寧にやっている
追記：ズルをせずに通した(周辺2行を見なくても良いことが分かった)
AOJで通った普通のやつ
↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

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
#define rep1(n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 0; i < (n); i++)
#define rep3(i, a, b) for (int i = (a); i < (b); i++)
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

bool stop = 0;

void solve() {
    int w, h, n;
    cin >> h >> w;
    if (h == 0 && w == 0) {
        stop = 1;
        return;
    }
    cin >> n;
    vii x1(n), y1(n), x2(n), y2(n);
    rep(n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    vii xs, ys;
    rep(i, n) {
        rep(d, -1, 2) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            int ty1 = y1[i] + d, ty2 = y2[i] + d;
            if (0 <= tx1 && tx1 < h) xs.pb(tx1);
            if (0 <= tx2 && tx2 < h) xs.pb(tx2);
            if (0 <= ty1 && ty1 < w) ys.pb(ty1);
            if (0 <= ty2 && ty2 < w) ys.pb(ty2);
        }
    }
    sort(all(xs));
    sort(all(ys));
    uniq(xs);
    uniq(ys);
    rep(i, n) {
        x1[i] = lower_bound(all(xs), x1[i]) - xs.begin();
        x2[i] = lower_bound(all(xs), x2[i]) - xs.begin();
        y1[i] = lower_bound(all(ys), y1[i]) - ys.begin();
        y2[i] = lower_bound(all(ys), y2[i]) - ys.begin();
    }
    int H = lower_bound(all(xs), h) - xs.begin(), W = lower_bound(all(ys), w) - ys.begin();
    vvii fld(H + 2, vii(W + 2, 0));
    rep(i, n) {
        fld[x1[i] + 1][y1[i] + 1]++;
        fld[x1[i] + 1][y2[i] + 1]--;
        fld[x2[i] + 1][y1[i] + 1]--;
        fld[x2[i] + 1][y2[i] + 1]++;
    }
    rep(x, H + 1) rep(y, W + 1) fld[x + 1][y + 1] += fld[x][y + 1] + fld[x + 1][y] - fld[x][y];
    int ans = 0;
    rep(x, 1, H + 1) {
        rep(y, 1, W + 1) {
            if (fld[x][y]) continue;
            ans++;
            queue<pii> que;
            que.push(make_pair(x, y));
            while (!que.empty()) {
                int cx = que.front().fi, cy = que.front().se;
                que.pop();
                rep(i, 4) {
                    int nx = cx + dx[i], ny = cy + dy[i];
                    if (!(1 <= nx && nx <= H && 1 <= ny && ny <= W)) continue;
                    if (fld[nx][ny]) continue;
                    que.push(make_pair(nx, ny));
                    fld[nx][ny] = 1;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    // IOS;
    while (stop == 0) solve();
    return 0;
}
*/