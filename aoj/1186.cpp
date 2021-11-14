#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

int main() {
    vector<vector<pair<int, int>>> a(50000);
    for (int i = 1; i <= 150; i++) {
        for (int j = i + 1; j <= 150; j++) {
            a[i * i + j * j].push_back({i, j});
        }
    }
    for (auto ai : a) {
        sort(all(ai));
    }
    int h, w;
    while (cin >> h >> w, h) {
        ll s = h * h + w * w;
        int idx = lower_bound(all(a[s]), make_pair(h, w)) - a[s].begin();
        if (idx != (int)a[s].size() - 1) {
            cout << a[s][idx + 1].first << " " << a[s][idx + 1].second << endl;
        } else {
            int ss = s + 1;
            while (a[ss].size() == 0) ss++;
            cout << a[ss][0].first << " " << a[ss][0].second << endl;
        }
    }
    return 0;
}

/*
あらかじめペアを全列挙
*/