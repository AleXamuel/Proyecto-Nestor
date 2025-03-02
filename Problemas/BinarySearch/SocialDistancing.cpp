//https://vjudge.net/problem/USACO-1038
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

int n, m;
vector<pair<ll,ll> > A;

ll bs() {
    ll l = 0;
    ll r = INT_MAX;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        int i = 0;
        int cnt = 1;
        ll cur = A[i].first;
        while (i < m && cnt < n) {
            if (cur + mid <= A[i].second) {
                cur = max(cur + mid, A[i].first);
                cnt++;
            } else
                i++;
        }
        if (cnt >= n) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return ans;
}


void solve() {
    cin >> n >> m;
    A.assign(m, {});
    fori(i, 0, m)
        cin >> A[i].first >> A[i].second;
    sort(all(A));
    cout << bs() << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("socdist.in", "r",stdin);
    freopen("socdist.out", "w",stdout);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
