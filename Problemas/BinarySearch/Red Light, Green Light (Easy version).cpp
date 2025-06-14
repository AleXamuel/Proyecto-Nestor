//https://codeforces.com/contest/2118/problem/D1
#include <bits/stdc++.h>
using namespace std;
#define For(i, k, n) for (ll i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define ln "\n"


const int MAX = 500;
ll n, k;

ll pos[MAX];
ll delay[MAX];

bool visited[MAX][MAX][2];


ll bs(ll x) {
    ll l = 0;
    ll r = n - 1;
    ll ans = -1;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (pos[mid] >= x) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}


bool solve(ll cur_pos, ll t, int d) {
    if (visited[cur_pos][t][d])
        return false;
    visited[cur_pos][t][d] = true;
    if (d == 0) {
        if (t == delay[cur_pos]) {
            if (cur_pos - 1 >= 0)
                return solve(cur_pos - 1, (t % k + abs(pos[cur_pos] - pos[cur_pos - 1]) % k) % k, 1);
            return true;
        }
        if (cur_pos + 1 < n)
            return solve(cur_pos + 1, (t % k + abs(pos[cur_pos] - pos[cur_pos + 1]) % k) % k, 0);
        return true;
    }
    if (t == delay[cur_pos]) {
        if (cur_pos + 1 < n)
            return solve(cur_pos + 1, (t % k + abs(pos[cur_pos] - pos[cur_pos + 1]) % k) % k, 0);
        return true;
    }
    if (cur_pos - 1 >= 0)
        return solve(cur_pos - 1, (t % k + abs(pos[cur_pos] - pos[cur_pos - 1]) % k) % k, 1);
    return true;
}


void solve() {
    cin >> n >> k;
    For(i, 0, n)
        cin >> pos[i];
    For(i, 0, n)
        cin >> delay[i];

    ll q;
    cin >> q;
    while (q--) {
        ll cur;
        cin >> cur;
        ll next_pos = bs(cur);
        if (next_pos == -1)
            cout << "YES" << ln;
        else
            cout << (solve(next_pos, abs(pos[next_pos] - cur) % k, 0) ? "YES" : "NO") << ln;
        For(i, 0, n)
            For(j, 0, k)
                For(x, 0, 2)
                    visited[i][j][x] = false;
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
