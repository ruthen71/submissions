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

int M = 1000005;
int m = 105;

int main() {
    // IOS;
    int N, K;
    cin >> N >> K;
    vii X1(N), Y1(N), Z1(N), X2(N), Y2(N), Z2(N);
    rep(N) cin >> X1[i] >> Y1[i] >> Z1[i] >> X2[i] >> Y2[i] >> Z2[i];
    vii XS, YS, ZS;
    rep(i, N) {
        int tx1 = X1[i], tx2 = X2[i];
        int ty1 = Y1[i], ty2 = Y2[i];
        int tz1 = Z1[i], tz2 = Z2[i];
        if (0 <= tx1 && tx1 < M) XS.pb(tx1);
        if (0 <= tx2 && tx2 < M) XS.pb(tx2);
        if (0 <= ty1 && ty1 < M) YS.pb(ty1);
        if (0 <= ty2 && ty2 < M) YS.pb(ty2);
        if (0 <= tz1 && tz1 < M) ZS.pb(tz1);
        if (0 <= tz2 && tz2 < M) ZS.pb(tz2);
    }
    sort(all(XS));
    sort(all(YS));
    sort(all(ZS));
    uniq(XS);
    uniq(YS);
    uniq(ZS);
    vii x1(N), y1(N), z1(N), x2(N), y2(N), z2(N);
    rep(i, N) {
        x1[i] = lower_bound(all(XS), X1[i]) - XS.begin();
        y1[i] = lower_bound(all(YS), Y1[i]) - YS.begin();
        z1[i] = lower_bound(all(ZS), Z1[i]) - ZS.begin();
        x2[i] = lower_bound(all(XS), X2[i]) - XS.begin();
        y2[i] = lower_bound(all(YS), Y2[i]) - YS.begin();
        z2[i] = lower_bound(all(ZS), Z2[i]) - ZS.begin();
    }
    vvvii fld(m, vvii(m, vii(m, 0)));
    rep(i, N) rep(x, x1[i], x2[i]) rep(y, y1[i], y2[i]) rep(z, z1[i], z2[i]) fld[x][y][z]++;
    ll ans = 0;
    rep(x, m) rep(y, m) rep(z, m) {
        if (fld[x][y][z] >= K) {
            ans += (ll)(XS[x + 1] - XS[x]) * (YS[y + 1] - YS[y]) * (ZS[z + 1] - ZS[z]);
        }
    }
    cout << ans << endl;
    return 0;
}
/*
メモ
座標圧縮
3次元座圧する
三次元座圧
配列に対応させると(X1,Y1,Z1)が領域内、(X2,Y2,Z2)が余白部分に対応するので
蟻本の例題のように複数行見なくてOK
蟻本p151~の実装を参考に
*/
