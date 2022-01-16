#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int M = 1000000005;

void solve(int N) {
    set<pair<pair<int, int>, int>> S;
    S.insert({{0, M}, -1});  // {{start, siz}, id}
    rep(i, N) {
        char type;
        cin >> type;
        if (type == 'W') {
            int id, siz;
            cin >> id >> siz;
            int cs = 0;
            auto it = S.begin();
            vector<pair<pair<int, int>, int>> v;
            while (cs < siz) {
                if ((*it).second == -1) {
                    cs += (*it).first.second;
                    v.push_back(*it);
                }
                it++;
            }
            for (auto vi : v) S.erase(vi);
            cs = 0;
            for (auto vi : v) {
                int rem = siz - cs;
                if (vi.first.second <= rem) {
                    S.insert({vi.first, id});
                } else {
                    S.insert({{vi.first.first, rem}, id});
                    S.insert({{vi.first.first + rem, vi.first.second - rem}, -1});
                }
                cs += vi.first.second;
            }

        } else if (type == 'D') {
            int id;
            cin >> id;
            vector<pair<pair<int, int>, int>> v;
            for (auto &si : S) {
                if (si.second == id) {
                    v.push_back(si);
                }
            }
            for (auto &vi : v) {
                S.erase(vi);
                S.insert({vi.first, -1});
            }
        } else {
            // R query
            int loc;
            cin >> loc;
            for (auto &si : S) {
                if (si.first.first <= loc && loc < si.first.first + si.first.second) {
                    cout << si.second << '\n';
                    break;
                }
            }
        }
    }
    cout << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while (cin >> N, N) solve(N);
    return 0;
}

/**
 * {{開始位置,サイズ},id}をsetに入れて頑張った
 * よく考えるとsetじゃなくて良い(どうせO(N^2)なので)
 * whileやforで1つずつ見ている部分を上手く一気に見つけられればO(NlogN)になりそう
 */
