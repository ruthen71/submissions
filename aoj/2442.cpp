#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ld eps = 10e-7;

int main() {
    int n;
    cin >> n;
    ld sx = 0, sy = 0;
    vector<ld> vx(n), vy(n);
    for (int i = 0; i < n; i++) {
        ld x, y;
        cin >> x >> y;
        sx += x, sy += y;
        vx[i] = x, vy[i] = y;
    }
    if (n % 2 == 1) {
        puts("NA");
        return 0;
    }
    sx /= n, sy /= n;
    ld r = (vx[0] - sx) * (vx[0] - sx) + (vy[0] - sy) * (vy[0] - sy);
    int ok = 1;
    for (int i = 0; i < n / 2; i++) {
        ld cr = (vx[i] - sx) * (vx[i] - sx) + (vy[i] - sy) * (vy[i] - sy);
        ld cr2 = (vx[i + n / 2] - sx) * (vx[i + n / 2] - sx) + (vy[i + n / 2] - sy) * (vy[i + n / 2] - sy);
        if (abs(cr - cr2) <= eps) continue;
        ok = 0;
    }
    if (ok) {
        printf("%.15Lf %.15Lf\n", sx, sy);
    } else {
        cout << "NA" << endl;
    }
    return 0;
}

/*
幾何
凸多角形の二等分

直感的にnが奇数だと無理そう
nが偶数の時、点対称なら良さそう
->重心を求め、そこからの距離がi,i+n/2番目の頂点で等しければOK

*/