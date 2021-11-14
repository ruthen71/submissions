#include <bits/stdc++.h>
using namespace std;

int Not[3] = {2, 1, 0};
int And[3][3] = {{0, 0, 0}, {0, 1, 1}, {0, 1, 2}};
int Or[3][3] = {{0, 1, 2}, {1, 1, 2}, {2, 2, 2}};

int f(string s, int p, int q, int r) {
    int c = 0, notc = 0;
    int n = s.size();
    vector<int> stk, op, cv;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            cv.push_back(notc);
            notc = 0;
        }
        if (s[i] == ')') {
            int a = stk.back();
            stk.pop_back();
            int b = stk.back();
            stk.pop_back();
            int ope = op.back();
            op.pop_back();
            int ret;
            if (ope == 0)
                ret = Or[a][b];
            else
                ret = And[a][b];
            notc = cv.back();
            cv.pop_back();
            stk.push_back(notc ? Not[ret] : ret);
            notc = 0;
        }
        if (s[i] == '-') notc = 1 - notc;
        if (s[i] == 'P') {
            if (notc) {
                stk.push_back(Not[p]);
                notc = 0;
            } else {
                stk.push_back(p);
            }
        }
        if (s[i] == 'Q') {
            if (notc) {
                stk.push_back(Not[q]);
                notc = 0;
            } else {
                stk.push_back(q);
            }
        }
        if (s[i] == 'R') {
            if (notc) {
                stk.push_back(Not[r]);
                notc = 0;
            } else {
                stk.push_back(r);
            }
        }
        if (s[i] == '0') {
            if (notc) {
                stk.push_back(Not[0]);
                notc = 0;
            } else {
                stk.push_back(0);
            }
        }
        if (s[i] == '1') {
            if (notc) {
                stk.push_back(Not[1]);
                notc = 0;
            } else {
                stk.push_back(1);
            }
        }
        if (s[i] == '2') {
            if (notc) {
                stk.push_back(Not[2]);
                notc = 0;
            } else {
                stk.push_back(2);
            }
        }
        if (s[i] == '+') op.push_back(0);
        if (s[i] == '*') op.push_back(1);
    }
    assert(stk.size() == 1);
    return stk.back();
}

void solve(string s) {
    int ans = 0;
    for (int p = 0; p < 3; p++) {
        for (int q = 0; q < 3; q++) {
            for (int r = 0; r < 3; r++) {
                if (f(s, p, q, r) == 2) ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    string s;
    while (cin >> s, s != ".") solve(s);
    return 0;
}

/*
構文解析
DFSを使わなくともforループでできる
(に入るときにそれまでの-の回数をスタックに積んでおく必要がある
)で処理した後、積んでいた-の回数を反映させる
SSRSさんの実装がすごく綺麗だった
*/
