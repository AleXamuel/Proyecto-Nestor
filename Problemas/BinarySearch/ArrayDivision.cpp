//https://cses.fi/problemset/task/1085/
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

int n, k;
vector<ll> A;

bool valid(ll x) {
    ll cum = 0;
    int cnt = 1;
    fori(i, 0, n) {
        if (A[i] > x)
            return false;
        if (cum + A[i] > x) {
            cnt++;
            cum = A[i];
        } else
            cum += A[i];
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
    cin >> n >> k;
    A.resize(n);
    fori(i, 0, n)
        cin >> A[i];
    cout << bs() << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
