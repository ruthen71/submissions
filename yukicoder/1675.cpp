#include <bits/stdc++.h>
using namespace std;

// clang-format off
#include <atcoder/segtree>
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

ll op(ll a, ll b) { return min(a, b); }

ll e() { return INF; }

int main() {
    // IOS;
    int N, Q;
    cin >> N >> Q;
    V1<P<ll, pii>> lrB(Q);
    rep(Q) {
        cin >> lrB[i].se.fi >> lrB[i].se.se >> lrB[i].fi;
        lrB[i].se.fi--, lrB[i].se.se--;
    }
    sort(all(lrB));
    reverse(all(lrB));
    segtree<ll, op, e> Seg(N);
    set<int> Set;
    rep(i, N + 1) Set.insert(i);
    rep(i, Q) {
        int l = lrB[i].se.fi, r = lrB[i].se.se, B = lrB[i].fi;
        while (1) {
            auto itr = Set.lower_bound(l);
            if ((*itr) > r) break;
            Seg.set((*itr), B);
            Set.erase(itr);
        }
        int m = Seg.prod(l, r + 1);
        if (m > B) {
            cout << -1 << endl;
            return 0;
        }
    }
    vll ans(N);
    rep(i, N) ans[i] = Seg.get(i);
    rep(i, N) if (ans[i] == INF) ans[i] = 1000000000;
    rep(i, N) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
/*
メモ
構築
RMQを満たす数列の構築
Bの大きい順にソートする
各要素につき高々1回しか更新されないので、setに値が未確定の値を挿入
セグメントツリーで実際に更新する
セグメント木
*/