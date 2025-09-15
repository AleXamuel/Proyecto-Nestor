//https://codeforces.com/gym/102890/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

const int MOD = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    n++;
    k++;
    ll val = n * (n + 1) >> 1;
    cout << ((val % MOD) * (k % MOD)) % MOD << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
