//https://codeforces.com/contest/1978/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"
#define Pair pair<int,int>


ll n, a, b;


ll bs() {
    ll l = 1;
    ll r = n;
    ll ans = 0;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (b - mid + 1 > a) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return ans;
}

void solve() {
    cin >> n >> a >> b;
    if (b <= a)
        cout << a * n << ln;
    else {
        ll i = bs();
        ll val = b - i + 1;
        val--;
        ll cur = b * (b + 1) / 2 - val * (val + 1) / 2;
        cout << cur + (n - i) * a << ln;
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
