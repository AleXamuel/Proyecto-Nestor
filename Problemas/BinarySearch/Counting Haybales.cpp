//https://vjudge.net/problem/USACO-666
using namespace std;
#include <bits/stdc++.h>

#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"

vector<int> A;
int n;

int menor_igual(int x) {
    int l = 0;
    int r = n - 1;
    int ans = INT_MIN;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (A[mid] == x)
            return mid;
        if (A[mid] < x) {
            ans = max(ans, mid);
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return ans;
}

int mayor_igual(int x) {
    int l = 0;
    int r = n - 1;
    int ans = INT_MAX;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (A[mid] == x)
            return mid;
        if (A[mid] < x)
            l = mid + 1;
        else {
            ans = min(ans, mid);
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    int q;
    cin >> n >> q;
    A.assign(n, 0);
    fori(i, 0, n)
        cin >> A[i];
    sort(A.begin(), A.end());
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans1 = menor_igual(r);
        int ans2 = mayor_igual(l);
        if (ans1 == INT_MIN || ans2 == INT_MAX)
            cout << 0 << ln;
        else
            cout << ans1 - ans2 + 1 << ln;
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    solve();
    return 0;
}
