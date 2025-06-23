//https://codeforces.com/contest/142/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"


vector<ll> get_divisors(ll n) {
    vector<ll> ans;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (n / i != i)
                ans.push_back(n / i);
        }
    }
    return ans;
}


void solve() {
    ll n;
    cin >> n;
    vector<ll> divs = get_divisors(n);
    sort(all(divs));
    ll mx = -1;
    ll mn = LLONG_MAX;
    int m = (int) divs.size();
    For(i, 0, m) {
        For(j, 0, m) {
            ll cur = divs[i] * divs[j];
            if (n % cur == 0) {
                ll a = divs[i];
                ll b = divs[j];
                ll c = n / cur;
                mx = max(mx, (a + 1) * (b + 2) * (c + 2));
                mx = max(mx, (b + 1) * (a + 2) * (c + 2));
                mx = max(mx, (c + 1) * (b + 2) * (a + 2));

                mn = min(mn, (a + 1) * (b + 2) * (c + 2));
                mn = min(mn, (b + 1) * (a + 2) * (c + 2));
                mn = min(mn, (c + 1) * (b + 2) * (a + 2));
            }
        }
    }
    cout << mn - n << " " << mx - n << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
