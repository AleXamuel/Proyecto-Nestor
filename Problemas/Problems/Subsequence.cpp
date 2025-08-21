//https://vjudge.net/contest/738626#problem/E
#include<iostream>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define ln "\n"

const int MAX = 1e5;

ll A[MAX];

void solve() {
    int n;
    ll s;
    cin >> n >> s;
    For(i, 0, n)
        cin >> A[i];

    ll sum = 0;
    int l = 0;
    int r = 0;
    int ans = 1 << 30;
    while (l < n && r < n) {
        while (sum < s && r < n) {
            sum += A[r++];
        }

        if (sum >= s)
            ans = min(ans, r - 1 - l + 1);
        while (l <= r - 1) {
            if (sum < s)
                break;
            ans = min(ans, r - 1 - l + 1);
            sum -= A[l++];
        }
    }

    cout << (ans == (1 << 30) ? 0 : ans) << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}

