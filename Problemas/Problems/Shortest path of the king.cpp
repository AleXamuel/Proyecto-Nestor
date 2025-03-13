//https://codeforces.com/contest/3/problem/A
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(), A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

#define conv(a) (9-a)

void solve() {
    string a, b;
    cin >> a >> b;
    pair<int, int> s = {conv((a[1] - '0')), a[0] - 'a' + 1};
    pair<int, int> t = {conv((b[1] - '0')), b[0] - 'a' + 1};
    int d = max(abs(s.first - t.first), abs(s.second - t.second));
    cout << d << ln;
    pair<int, int> cur = {s.first - t.first, s.second - t.second};
    while (d--) {
        int dx = cur.first;
        int dy = cur.second;
        if (dx < 0 && dy < 0) {
            cout << "RD" << ln;
            dx++;
            dy++;
        } else if (dx > 0 && dy > 0) {
            dx--;
            dy--;
            cout << "LU" << ln;
        } else if (dx > 0 && dy < 0) {
            dx--;
            dy++;
            cout << "RU" << ln;
        } else if (dx < 0 && dy > 0) {
            dx++;
            dy--;
            cout << "LD" << ln;
        } else if (dx > 0) {
            dx--;
            cout << "U" << ln;
        } else if (dx < 0) {
            dx++;
            cout << "D" << ln;
        } else if (dy > 0) {
            dy--;
            cout << "L" << ln;
        } else {
            dy++;
            cout << "R" << ln;
        }
        cur.first = dx;
        cur.second = dy;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
