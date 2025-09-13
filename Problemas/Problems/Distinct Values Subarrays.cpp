//https://cses.fi/problemset/task/3420/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

const int MAX = 2e5;

int A[MAX];

void solve() {
    int n;
    cin >> n;
    For(i, 0, n)
        cin >> A[i];
    unordered_set<int> H;
    int l = 0;
    ll ans = 0;
    For(r, 0, n) {
        while (H.find(A[r]) != H.end()) {
            H.erase(A[l]);
            l++;
        }
        H.insert(A[r]);
        ans += (r - l + 1);
    }
    cout << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}

