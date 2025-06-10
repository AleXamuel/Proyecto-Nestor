//https://open.kattis.com/problems/tricktreat
#include <bits/stdc++.h>
using namespace std;
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define ln "\n"

const int MAX = 5e4;

using pt = pair<double, double>;
pt A[MAX];
int n;

double dist(pt p1, pt p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double f(double x) {
    double ans = -1;
    For(i, 0, n)
        ans = max(ans, dist(A[i], {x, 0}));
    return ans;
}

void solve() {
    while (cin >> n && n != 0) {
        For(i, 0, n)
            cin >> A[i].first >> A[i].second;
        double l = -2e5;
        double r = 2e5;
        double ans = 0;
        while (r - l > 1e-5) {
            double len = (r - l) / 3.0;
            double m1 = l + len;
            double m2 = r - len;
            if (f(m1) < f(m2)) {
                ans = m1;
                r = m2;
            } else {
                l = m1;
                ans = m2;
            }
        }
        cout.precision(5);
        cout << fixed;
        cout << ans << " " << f(ans) << ln;
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
