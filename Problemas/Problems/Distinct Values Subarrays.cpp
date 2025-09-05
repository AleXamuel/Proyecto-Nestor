//https://cses.fi/problemset/task/3420/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define Pair pair<int,int>

const int MAX = 2e5;

int A[MAX];

void solve() {
    int n;
    cin >> n;
    For(i, 0, n)
        cin >> A[i];
    ll ans = 0;
    int l = 0;
    int r = 0;
    unordered_set<int> H;
    while (r < n && l < n) {
        while (r < n && H.find(A[r]) == H.end())
            H.insert(A[r++]);
        if (r < n) {
            int rep = A[r];
            r--;
            ans += r - l + 1;
            H.erase(A[l]);
            H.erase(rep);
            while (l < n && A[l] != rep) {
                l++;
                ans += r - l + 1;
                H.erase(A[l]);
            }
            l++;
            r++;
        } else {
            r--;
            while (l < n) {
                ans += r - l + 1;
                l++;
            }
        }
    }
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
