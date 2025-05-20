//https://codeforces.com/contest/2085/problem/C
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long


void solve() {
    int x, y;
    cin >> x >> y;
    if (x == y)
        cout << -1 << ln;
    else {
        int a = max(x, y);
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if ((a & 1 << i) != 0) {
                ans = 1 << (i + 1);
                break;
            }
        }
        cout << ans - a << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
