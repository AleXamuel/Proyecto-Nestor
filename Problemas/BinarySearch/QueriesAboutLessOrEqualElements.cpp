//https://codeforces.com/contest/600/problem/B
using namespace std;
#include <bits/stdc++.h>

#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"

vector<int> A;
int n;

int binarySearch(int x) {
    int l = 0;
    int r = n - 1;
    int ans = INT_MIN;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (A[mid] <= x) {
            ans = max(ans, mid);
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return ans == INT_MIN ? 0 : ans+1;
}

void solve() {
    int m;
    cin >> n >> m;
    A.assign(n, 0);
    fori(i, 0, n)
        cin >> A[i];
    sort(A.begin(), A.end());
    while (m--) {
        int x;
        cin >> x;
        cout << binarySearch(x) << " ";
    }
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    solve();
    return 0;
}
