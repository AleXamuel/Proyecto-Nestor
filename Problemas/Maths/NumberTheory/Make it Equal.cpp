//https://codeforces.com/contest/2131/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"


void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (ll &i: A)
        cin >> i;
    unordered_map<ll, int> freq;
    For(i, 0, n) {
        ll x;
        cin >> x;
        freq[x % k]++;
    }
    for (const auto &i: A) {
        ll a = i % k;
        ll j = i / k;
        ll b = k - (i - j * k);
        if (freq.find(a) != freq.end() && freq[a] > 0)
            freq[a]--;
        else if (freq.find(b) != freq.end())
            freq[b]--;
    }
    for (const auto &[k,v]: freq) {
        if (v != 0) {
            cout << "NO" << ln;
            return;
        }
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
}
