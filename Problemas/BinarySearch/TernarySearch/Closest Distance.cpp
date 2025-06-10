//https://vjudge.net/problem/LightOJ-1146
#include <bits/stdc++.h>
using namespace std;
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define ln "\n"


using pt = pair<double, double>;

istream &operator>>(istream &is, pt &p) {
    return is >> p.first >> p.second;
}

ostream &operator<<(ostream &os, const pt &p) {
    return os << "(" << p.first << "," << p.second << ")";
}

double dist(pt a, pt b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}


pt param(pt a, pt b, double t) {
    return {a.first + (b.first - a.first) * t, a.second + (b.second - a.second) * t};
}


void solve(int caso) {
    pt A, B, C, D;
    cin >> A >> B >> C >> D;
    double l = 0;
    double r = 1;
    double ans = 1e18;
    while (r - l > 1e-8) {
        double len = (r - l) / 3.0;
        double m1 = l + len;
        double m2 = r - len;
        double dist1 = dist(param(A, B, m1), param(C, D, m1));
        double dist2 = dist(param(A, B, m2), param(C, D, m2));
        if (dist1 < dist2) {
            ans = dist1;
            r = m2;
        } else {
            ans = dist2;
            l = m1;
        }
    }
    cout.precision(8);
    cout << fixed;
    cout << "Case " << caso << ": ";
    cout << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    For(i, 1, t+1)
        solve(i);
    return 0;
}
