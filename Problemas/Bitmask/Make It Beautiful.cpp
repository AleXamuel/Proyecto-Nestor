//https://codeforces.com/contest/2118/problem/C
#include <bits/stdc++.h>
using namespace std;
#define For(i, k, n) for (ll i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define ln "\n"

const int MAX = 5000;

ll A[MAX];

void solve() {
    ll n, k;
    cin >> n >> k;
    For(i, 0, n)
        cin >> A[i];

    For(i, 0, 63) {
        For(j, 0, n) {
            ll cur = A[j];
            if ((cur >> i & 1) == 0) {
                ll cost = 1ll << i;
                if (k > 0 && k >= cost) {
                    k -= cost;
                    A[j] += cost;
                }
            }
        }
    }
    ll ans = 0;
    For(i, 0, n)
        ans += __builtin_popcountll(A[i]);
    cout << ans << ln;
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
