//https://cses.fi/problemset/task/1646
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> prefixSum(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0)
            prefixSum[i] = a[i];
        else
            prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == 0)
            cout << prefixSum[r] << endl;
        else
            cout << prefixSum[r] - prefixSum[l - 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
