//https://vjudge.net/problem/UVA-294
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long


int decompose(int n) {
    int ans = 1;
    for (int i = 2; (ll) i * i <= n; i++) {
        int e = 1;
        while (n % i == 0) {
            e++;
            n /= i;
        }
        ans *= e;
    }
    if (n > 1)
        ans <<= 1;
    return ans;
}


void solve() {
    int l, r;
    cin >> l >> r;
    int ans = -1;
    int cur = 0;
    For(i, l, r+1) {
        int divs = decompose(i);
        if (divs > ans) {
            ans = divs;
            cur = i;
        }
    }
    cout << "Between " << l << " and " << r << ", " << cur << " has a maximum of " << ans << " divisors." << ln;
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
