#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ld EPS = 10e-10;

struct Point {
    ld x, y;
};

void solve() {
    Point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    int n;
    cin >> n;
    vector<pair<pair<ld, ld>, int>> kou;
    vector<int> O(n), L(n);
    for (int i = 0; i < n; i++) {
        Point s, t;
        cin >> s.x >> s.y >> t.x >> t.y >> O[i] >> L[i];
        if (abs((b.x - a.x) * (t.y - s.y) - (b.y - a.y) * (t.x - s.x)) <= EPS) continue;
        ld hoge = (b.x - a.x) * (t.y - s.y) - (b.y - a.y) * (t.x - s.x);
        ld u = ((s.x - a.x) * (b.y - a.y) - (s.y - a.y) * (b.x - a.x)) / hoge;
        ld v = ((s.x - a.x) * (t.y - s.y) - (s.y - a.y) * (t.x - s.x)) / hoge;
        if (!(0 <= u && u <= 1 && 0 <= v && v <= 1)) continue;
        ld x = s.x + u * (t.x - s.x), y = s.y + u * (t.y - s.y);
        kou.push_back({{x, y}, i});
    }
    sort(kou.begin(), kou.end());
    int ans = 0, cur = (O[kou[0].second] + L[kou[0].second]) % 2;
    for (auto x : kou) {
        if (cur != (O[x.second] + L[x.second]) % 2) {
            ans++;
            cur = (O[x.second] + L[x.second]) % 2;
        }
    }
    cout << ans << endl;
    return;
}

int main() {
    int N;
    cin >> N;
    while (N--) solve();
    return 0;
}

/*
幾何
線分の交差判定
交点を順番にソートする
*/
