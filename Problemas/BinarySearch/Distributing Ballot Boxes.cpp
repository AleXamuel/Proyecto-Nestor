//https://vjudge.net/problem/SPOJ-BALLOT
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"


void solve() {
    int n, b;
    while (cin >> n >> b && n != -1) {
        vector<int> A(n);
        fori(i, 0, n)
            cin >> A[i];
        int l = 0;
        int r = INT_MAX;
        int ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cont = 0;
            for (const auto &i: A)
                cont += (i + mid - 1) / mid;
            if (cont <= b) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        cout << ans << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
