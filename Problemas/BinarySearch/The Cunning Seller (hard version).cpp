//https://codeforces.com/contest/2132/problem/C2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"


int coef[19];

ll cost(int x) {
    ll val = pow(3, x);
    return val * 3 + x * (val / 3);
}


void solve() {
    ll n, k;
    cin >> n >> k;
    memset(coef, 0, sizeof(coef));
    int cur_sum = 0;
    int j = 0;
    while (n > 0) {
        int val = n % 3;
        coef[j++] = val;
        cur_sum += val;
        n /= 3;
    }
    if (cur_sum > k) {
        cout << -1 << ln;
        return;
    }
    for (int i = 18; i >= 1; i--)
        if (coef[i] != 0) {
            cur_sum -= coef[i];
            int ans = -1;
            int l = 0;
            int r = coef[i] - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int val = (coef[i] - mid) * 3;
                if (val + mid + cur_sum <= k) {
                    ans = mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            if (ans == -1)
                break;
            int val = (coef[i] - ans) * 3;
            coef[i - 1] += val;
            coef[i] -= coef[i] - ans;
            cur_sum += ans + val;
        }

    ll ans = 0;
    For(i, 0, 19)
        ans += coef[i] * cost(i);
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
