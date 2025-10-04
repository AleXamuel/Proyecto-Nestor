//https://codeforces.com/contest/2152/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(v) (int)((v).size())
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl

template<typename T>
ostream &operator<<(ostream &os, vector<T> A) {
    if (A.empty()) {
        os << "[]";
        return os;
    }
    os << "[";
    For(i, 0, sz(A)-1)
        os << A[i] << ", ";
    os << A.back() << "]";
    return os;
}

int mod(int a, int b) {
    if (b < 0)
        b *= -1;
    return (a % b + b) % b;
}


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    vector<int> pref0(n, 0);
    vector<int> pref1(n, 0);
    pref0[0] = A[0] == 0;
    pref1[0] = A[0] == 1;
    For(i, 1, n) {
        if (A[i] == 0) {
            pref0[i] = pref0[i - 1] + 1;
            pref1[i] = pref1[i - 1];
        } else {
            pref1[i] = pref1[i - 1] + 1;
            pref0[i] = pref0[i - 1];
        }
    }

    vector<int> dp(n);
    dp[0] = 1;
    For(i, 1, n)
        if (A[i] != A[i - 1])
            dp[i] = 1 + dp[i - 1];
        else
            dp[i] = 1;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int cnt0 = pref0[r] - (l == 0 ? 0 : pref0[l - 1]);
        int cnt1 = pref1[r] - (l == 0 ? 0 : pref1[l - 1]);
        if (cnt0 % 3 != 0 || cnt1 % 3 != 0) {
            cout << -1 << ln;
            continue;
        }
        int ans = cnt0 / 3 + cnt1 / 3;
        int R = dp[r];
        R--;
        if (r - R <= l)
            ans++;
        cout << ans << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
