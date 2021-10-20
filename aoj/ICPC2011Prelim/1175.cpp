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

struct circle {
    ld x, y, r;
    int c;
};

int cross(circle &a, circle &b) {
    ld dis = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return (sqrt(dis) < a.r + b.r);
}
/*
int dfs(vector<circle> &d, vii s) {
    int n = sz(d);
    vii t(n, 1);  // 重なってないやつ=1、重なってるやつ=0
    rep(j, n) {
        if (s[j]) continue;
        rep(i, j) {
            if (s[i]) continue;
            if (cross(d[i], d[j])) t[j] = 0;
        }
    }
    show(t);
    // 重なってないやつの各色の個数を数える
    vii cnt(4, 0);
    rep(i, n) {
        if (s[i]) continue;
        if (t[i]) cnt[d[i].c]++;
    }
    // 偶数枚の色のやつは全て取る
    int res = 0;
    rep(i, 4) {
        if (cnt[i] % 2 == 0) {
            rep(j, n) {
                if (s[j]) continue;
                if (d[j].c == i) s[j] = 0, res++;
            }
        }
    }
    // 奇数枚のやつの取りかたでDFSする
    int res2 = 0;
    rep(i, 4) {
        if (cnt[i] % 2 == 1) {
            int cur = 0;
            vii candi;  // candidate
            rep(j, n) {
                if (s[j]) continue;
                if (d[j].c == i) {
                    candi.pb(j);
                    s[j] = 0;
                }
            }
            for (auto c : candi) {
                s[c] = 1;
                chmax(cur, dfs(d, s));
                s[c] = 0;
            }
            chmax(res2, cur + sz(candi) - 1);
            for (auto c : candi) {
                s[c] = 1;
            }
        }
    }
    chmax(res2, dfs(d, s));
    return res + res2;
}
*/

void solve(int n) {
    if (n == 0) return;
    vector<circle> d(n);
    rep(n) {
        cin >> d[i].x >> d[i].y >> d[i].r >> d[i].c;
        d[i].c--;
    }

    int n2 = (1 << n);
    vii dp(n2, 0);
    dp[n2 - 1] = 1;
    rrep(bit, n2) {
        if (dp[bit] == 0) continue;
        vii t(n, 1);  // 重なってないやつ=1、重なってるやつ=0
        rep(j, n) {
            if ((bit >> j & 1) == 0) continue;
            rep(i, j) {
                if ((bit >> i & 1) == 0) continue;
                if (cross(d[i], d[j])) t[j] = 0;
            }
        }
        show(bit);
        show(t);
        rep(i, n) {
            if ((bit >> i & 1) == 0) continue;
            rep(j, i) {
                if ((bit >> j & 1) == 0) continue;
                if (t[i] == 1 && t[j] == 1 && d[i].c == d[j].c) {
                    dp[bit - (1 << i) - (1 << j)] = 1;
                    show(i) show(j);
                }
            }
        }
    }
    int ans = 0;
    rrep(bit, n2) {
        if (dp[bit]) chmax(ans, n - popcnt(bit));
    }
    show(dp);
    cout << ans << endl;
}

int main() {
    int n;
    while (cin >> n) solve(n);
    return 0;
}

/*
メモ
dp[S]=集合Sとなる取り除き方が存在すれば1、存在しなければ0
bitDP
S=111...1から始める
*/