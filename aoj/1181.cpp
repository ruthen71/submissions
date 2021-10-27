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

vvii dice(7, vii(4));
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve(int n) {
    vvii h(200, vii(200, 0));
    vvii num(200, vii(200, -1));
    rep(tt, n) {
        int t, f;
        cin >> t >> f;
        // (100,100)から落とすとする
        int cx = 100, cy = 100;
        while (1) {
            // まず移動できる方向を調べる
            int dis;
            rep(i, 4) if (dice[t][i] == f) dis = i;
            int cm = 0, di = -1;
            rep(i, 4) {
                if (dice[t][(dis + i) % 4] >= 4 && h[cx][cy] > h[cx + dx[i]][cy + dy[i]] && cm < dice[t][(dis + i) % 4]) {
                    cm = dice[t][(dis + i) % 4];
                    di = i;
                }
            }
            // 移動できない場合
            if (di == -1) {
                h[cx][cy]++;
                num[cx][cy] = t;
                break;
            }
            // 移動後の座標、上面、前面の計算
            // 前面が複雑
            cx += dx[di];
            cy += dy[di];
            int nt = dice[t][(dis + di + 2) % 4];
            rep(i, 4) {
                if (dice[nt][i] == t) f = dice[nt][(i + 4 - di) % 4];
            }
            t = nt;
        }
    }
    vii cnt(7, 0);
    rep(i, 200) rep(j, 200) if (num[i][j] != -1) cnt[num[i][j]]++;
    printf("%d %d %d %d %d %d\n", cnt[1], cnt[2], cnt[3], cnt[4], cnt[5], cnt[6]);
    return;
}

int main() {
    dice[1] = {2, 4, 5, 3};
    dice[2] = {1, 3, 6, 4};
    dice[3] = {1, 5, 6, 2};
    dice[4] = {1, 2, 6, 5};
    dice[5] = {1, 4, 6, 3};
    dice[6] = {2, 3, 5, 4};
    int n;
    while (cin >> n, n) solve(n);
    return 0;
}

/*
メモ
実装実装実装
サイコロの次の上面と前面がどうなるかを考えるのが難しい
*/
