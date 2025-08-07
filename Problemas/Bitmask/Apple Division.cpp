//https://cses.fi/problemset/task/1623/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

int A[20];
int n;

ll f(int i, int S1, int S2) {
    if (i == n) {
        ll ans1 = 0;
        for (int j = 0; j < 32; j++)
            if ((S1 >> j) & 1)
                ans1 += A[j];

        ll ans2 = 0;
        for (int j = 0; j < 32; j++)
            if ((S2 >> j) & 1)
                ans2 += A[j];

        return abs(ans1 - ans2);
    }
    return min(f(i + 1, S1 | (1 << i), S2), f(i + 1, S1, S2 | (1 << i)));
}


void solve() {
    cin >> n;
    For(i, 0, n)
        cin >> A[i];
    cout << f(0, 0, 0) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
