//https://codeforces.com/contest/2117/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"

const int MAX = 2e5 + 1;
ll A[MAX];

void solve() {
    int n;
    cin >> n;
    For(i, 0, n)
        cin >> A[i];
    ll val = (A[0] << 1) - A[1];
    if (val % (n + 1) != 0) {
        cout << "NO" << ln;
        return;
    }
    val /= n + 1;
    ll x = A[0] - val * n;
    if (x < 0 || val < 0) {
        cout << "NO" << ln;
        return;
    }
    For(i, 0, n)
        if ((i + 1) * x + val * (n - i) != A[i]) {
            cout << "NO" << ln;
            return;
        }
    cout << "YES" << ln;
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
