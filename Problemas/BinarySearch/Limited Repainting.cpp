//https://codeforces.com/contest/2070/problem/C
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

int n, k;
string s;
vector<ll> A;

bool valid(ll x) {
    char last = '*';
    int cnt = 0;
    fori(i, 0, n) {
        if (A[i] <= x)
            continue;
        if (s[i] == 'B' && last != 'B')
            cnt++;
        last = s[i];
    }
    return cnt <= k;
}

ll bs() {
    ll l = 0;
    ll r = 1e18;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (valid(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}

void solve() {
    cin >> n >> k >> s;
    A.resize(n);
    fori(i, 0, n)
        cin >> A[i];
    cout << bs() << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
