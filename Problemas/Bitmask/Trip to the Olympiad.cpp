//https://codeforces.com/contest/2057/problem/C
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long


void solve() {
    int l, r;
    cin >> l >> r;
    if (r - l + 1 == 3)
        cout << l << " " << l + 1 << " " << r << ln;
    else {
        int a = -1;
        for (int i = 31; i >= 0; i--)
            if (r >> i & 1) {
                a = 1 << i;
                break;
            }
        int b = a >> 1;
        if (a < l || b < l || b - 1 < l) {
            int cur = 0;
            for (int i = 31; i >= 0; i--) {
                int bL = l >> i & 1;
                int bR = r >> i & 1;
                if (bL == bR)
                    cur += bL * (1 << i);
                else {
                    a = cur + (1 << i);
                    b = a - 1;
                    break;
                }
            }
            For(i, l, r+1)
                if (i != a && i != b) {
                    cout << a << " " << b << " " << i << ln;
                    return;
                }
            assert(false);
        }
        cout << a << " " << b << " " << b - 1 << ln;
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
