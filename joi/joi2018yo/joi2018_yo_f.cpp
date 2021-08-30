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

int main() {
    // IOS;
    ll N, K, L;
    cin >> N >> K >> L;
    vll a(N);
    rep(N) cin >> a[i];
    int lb = 0, ub = N + 10;
    while (ub - lb > 1) {
        int x = (lb + ub) / 2;
        show(x);
        vii cnt(N, 0);
        rep(i, N) if (x > a[i]) cnt[i] = 1;
        int r = 0, sum = 0;
        ll ko = 0;
        rep(l, N) {
            while (r < N && sum + cnt[r] < K) sum += cnt[r++];
            // 区間の幅 = r - l
            ko += max(0ll, (r - l) + 1 - K);
            sum -= cnt[l];
        }
        show(ko);
        ll kukan = (N - K + 1) * (N - K + 2) / 2;
        show(kukan);
        if (kukan - ko < L)
            lb = x;
        else
            ub = x;
    }
    cout << lb << endl;
    return 0;
}

/*
メモ
連続したK個の数を選び、K番目のカードを取る
という操作を行ったときにL番目に来る数がx以上である
としたときのxの最大値
xのlb=0, ub=max(A)+1, [lb,ub)
K番目の数がx以上である区間の個数を求める
全体から、その個数を引く
残りが、x未満である区間の個数で、これがL個以上あるとアウト

K番目の数がx以上である区間の個数を数えられればOK
K番目の数がx以上である区間<=>その区間にx未満の数がK個未満
x未満の数が(K-1)個になるように区間を選ぶ
x未満の数を1で表し、x以上の数を0で表すと
sample1は
x=2のとき
K=3,L=2
[4 3 1 2]->[0 0 1 0]
そもそもK個ないので好きに選べる
x未満である区間の個数は0で、L個以上ないのでセーフ
x=3のとき
[4 3 1 2]->[0 0 1 1]
[(0 0 1) 1]と[(0 0 1 1)]と[0 (0 1 1)]で3つ選べる
x未満である区間の個数は0で、L個以上ないのでセーフ
x=4のとき
[4 3 1 2]->[0 1 1 1]
1は2個までしか持てないので、連続した3個以上の数という点も考慮すると
[(0 1 1) 1]ここしか選べず、区間の個数は1となる
x未満である区間の個数は2で、L個以上あるのでアウト
*/
