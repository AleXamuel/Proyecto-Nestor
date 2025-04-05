//https://cses.fi/problemset/task/1620/
using namespace std;
#include <bits/stdc++.h>

#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"

vector<int> A;

long long binarySearch(int t) {
    long long l = 0;
    long long r = LLONG_MAX;
    long long ans = LLONG_MAX;
    while (l <= r) {
        long long mid = l + ((r - l) >> 1); //Better than (l+r)/2, avoid overflow
        unsigned long long cur = 0;
        for (const auto &i: A)
            cur += mid / i;
        if (cur >= t) {
            ans = min(ans, mid);
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}

void solve() {
    int n, t;
    cin >> n >> t;
    A.assign(n, 0);
    fori(i, 0, n)
        cin >> A[i];
    cout << binarySearch(t) << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    solve();
    return 0;
}
