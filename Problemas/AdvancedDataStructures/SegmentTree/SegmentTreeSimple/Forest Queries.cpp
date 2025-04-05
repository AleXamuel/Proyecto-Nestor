//https://cses.fi/problemset/task/1652/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1000;

int t[4 * MAXN][4 * MAXN];
int a[MAXN][MAXN];
int n, m;

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx) {
            t[vx][vy] = a[lx][ly];
        } else {
            t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
        }
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy * 2, ly, my);
        build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
        t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx * 2, lx, mx);
        build_x(vx * 2 + 1, mx + 1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m - 1);
}

int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) return 0;
    if (ly == tly && try_ == ry) return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)) +
           sum_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx) return 0;
    if (lx == tlx && trx == rx) return sum_y(vx, 1, 0, m - 1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry) +
           sum_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);
}

void solve() {
    int q;
    cin >> n >> q;
    m = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = (c == '.' ? 0 : 1);
        }
    }
    build_x(1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; y2--; x1--; x2--;
        int res = sum_x(1, 0, n - 1, y1, y2, x1, x2);
        cout << res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
