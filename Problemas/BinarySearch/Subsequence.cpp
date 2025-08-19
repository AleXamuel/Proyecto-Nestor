//https://vjudge.net/contest/738626#problem/E
#include<iostream>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define ln "\n"

const int MAX = 1e5;

int n;
ll s;
int A[MAX];
ll pref[MAX];

bool valid(int x) {
    int last = 0;
    For(i, x-1, n) {
        ll cur_sum = pref[i] - (last == 0 ? 0 : pref[last - 1]);
        if (cur_sum >= s)
            return true;
        last++;
    }
    return false;
}


void solve() {
    cin >> n >> s;
    For(i, 0, n)
        cin >> A[i];
    pref[0] = A[0];
    For(i, 1, n)
        pref[i] = pref[i - 1] + A[i];
    int l = 0;
    int r = n + 1;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (valid(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
