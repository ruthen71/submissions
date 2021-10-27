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
    int N, M, K;
    cin >> N >> M >> K;
    vii D(M);
    rep(M) {
        cin >> D[i];
        D[i]--;
    }
    vvii v(N, vii(K));
    rep(i, N) rep(j, K) {
        cin >> v[i][j];
        v[i][j]--;
    }
    vii da(N, -1);
    rep(i, M) da[D[i]] = i;
    int M2 = (1 << M);

    V2<pii> g(M2);
    rrep(bit, M2) {
        rep(i, K) {
            // i番目の道を使うときの行先
            int bit2 = 0;
            rep(j, M) {
                if (bit >> j & 1) {
                    if (da[v[D[j]][i]] != -1) bit2 |= (1 << da[v[D[j]][i]]);
                }
            }
            g[bit].push_back({bit2, 1});
        }
    }
    vii dist(M2, inf);
    dist[M2 - 1] = 0;
    pque<pii> que;
    que.push({0, M2 - 1});
    while (!que.empty()) {
        int v = que.top().se, d = que.top().fi;
        que.pop();
        if (dist[v] < d) continue;
        rep(i, K) {
            if (chmin(dist[g[v][i].fi], dist[v] + g[v][i].se)) {
                que.push({dist[g[v][i].fi], g[v][i].fi});
            }
        }
    }
    cout << dist[0] << endl;
    return 0;
}

/*
メモ
bitDP?
bitで現在いる可能性がある場所を管理
現在人がいる可能性がある地点を集合とみてまず各道でどのような集合に移動するかを前計算した後に
ダイクストラでやる
辺の重みが全部1だからダイクストラではなくBFSで良い
*/
