//https://codeforces.com/contest/2094/problem/H
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long


vector<ll> get_divisors(const ll n) {
    vector<ll> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.emplace_back(i);
            if (i != n / i)
                divisors.emplace_back(n / i);
        }
    }
    return divisors;
}

ll bs(ll x, const vector<ll> &arr) {
    ll l = 0;
    ll r = arr.size() - 1;
    ll ans = INT_MAX;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (arr[mid] >= x) {
            ans = arr[mid];
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}

unordered_map<ll, vector<ll> > dp;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> A(n);
    unordered_map<ll, vector<ll> > pos;
    For(i, 0, n) {
        cin >> A[i];
        pos[A[i]].push_back(i);
    }

    while (q--) {
        ll k, l, r;
        cin >> k >> l >> r;
        l--;
        r--;
        ll ans = 0;
        bool hayCambios = true;
        while (hayCambios) {
            hayCambios = false;
            ll index = INT_MAX;
            vector<ll> divs;
            if (dp.find(k) != dp.end())
                divs = dp[k];
            else {
                divs = get_divisors(k);
                dp[k] = divs;
            }
            for (const auto &i: divs) {
                if (pos.find(i) == pos.end())
                    continue;
                index = min(index, bs(l, pos[i]));
            }
            if (index == INT_MAX || index > r)
                ans += k * (r - l + 1);
            else {
                ans += k * (index - l);
                while (k % A[index] == 0)
                    k /= A[index];
                ans += k;
                hayCambios = true;
                l = index + 1;
            }
        }
        cout << ans << ln;
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
