#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void push(vector<pair<char, ll>>& ans, pair<char, ll> x) {
    if (ans.size() == 0) {
        ans.push_back(x);
    } else {
        char last = ans[ans.size() - 1].first;
        if (last == x.first) {
            ans[ans.size() - 1].second += x.second;
        } else {
            ans.push_back(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<char, ll>> A, B, C;
    rep(_, 3) {
        while (1) {
            char c;
            cin >> c;
            if (c == '$') break;
            ll L;
            cin >> L;
            if (_ == 0)
                A.push_back({c, L});
            else if (_ == 1)
                B.push_back({c, L});
            else
                C.push_back({c, L});
        }
    }
    int na = A.size(), nb = B.size(), nc = C.size();
    for (int i = 0; i < na - nb + 1; i++) {
        if (A[i].first != B[0].first) continue;
        if (A[i].second < B[0].second) continue;
        int ok = 1;
        for (int j = 1; j < nb - 1; j++) {
            if (A[i + j].first != B[j].first || A[i + j].second != B[j].second) {
                ok = 0;
                break;
            }
        }
        if (ok == 0) continue;
        if (A[i + nb - 1].first != B[nb - 1].first) continue;
        if (A[i + nb - 1].second < B[nb - 1].second) continue;
        if (B.size() == 1) {
            vector<pair<char, ll>> ans;
            rep(k, i) push(ans, A[k]);
            rep(k, nc) push(ans, C[k]);
            if (A[i].second > B[0].second) push(ans, {B[0].first, A[i].second - B[0].second});
            for (int k = i + nb; k < na; k++) push(ans, A[k]);
            for (auto p : ans) cout << p.first << " " << p.second << " ";
            cout << "$\n";
            return 0;
        }
        vector<pair<char, ll>> ans;
        rep(k, i) push(ans, A[k]);
        if (A[i].second > B[0].second) push(ans, {B[0].first, A[i].second - B[0].second});
        rep(k, nc) push(ans, C[k]);
        if (A[i + nb - 1].second > B[nb - 1].second) push(ans, {B[nb - 1].first, A[i + nb - 1].second - B[nb - 1].second});
        for (int k = i + nb; k < na; k++) push(ans, A[k]);
        for (auto p : ans) cout << p.first << " " << p.second << " ";
        cout << "$\n";
        return 0;
    }
    for (auto p : A) cout << p.first << " " << p.second << " ";
    cout << "$\n";
    return 0;
}

/**
 * 基本的には端から順に境界を揃えて一致しているか判定するだけ
 * Bのサイズが1のときにハマった
 */
