//https://codeforces.com/contest/2029/problem/A
using namespace std;
#include <bits/stdc++.h>

#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"

long long f(long long l, long long r, long long k) {
    long long ans = LLONG_MAX;
    long long R = r;
    long long L = l;
    if (r - l == 1)
        return l * k <= r;
    while (l < r - 1) {
        long long mid = (l + r) >> 1;
        if (mid * k > R) {
            ans = min(ans, mid);
            r = mid;
        } else
            l = mid;
    }
    return ans - L;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long l, r, k;
        cin >> l >> r >> k;
        if (k == 1)
            cout << r - l + 1 << ln;
        else if (l * k > r)
            cout << 0 << ln;
        else
            cout << f(l, r, k) << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    solve();
    return 0;
}
//It can be solved in O(1) using math
