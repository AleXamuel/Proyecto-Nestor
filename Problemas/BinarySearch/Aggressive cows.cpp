//https://vjudge.net/problem/SPOJ-AGGRCOW
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"


void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> A(n);
    fori(i, 0, n)
        cin >> A[i];
    sort(all(A));
    int l = 0;
    int r = INT_MAX;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int low = 0;
        int high = 1;
        int cont = 0;
        while (high < n && cont != c - 1) {
            int dist = abs(A[low] - A[high]);
            if (dist >= mid) {
                cont++;
                low = high;
            }
            high++;
        }
        if (cont >= c - 1) {
            l = mid + 1;
            ans = mid;
        } else
            r = mid - 1;
    }
    cout << ans << ln;
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
