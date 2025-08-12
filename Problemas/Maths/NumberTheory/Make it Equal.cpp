//https://codeforces.com/contest/2131/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    map<int, int> freq;
    For(i, 0, n) {
        int x;
        cin >> x;
        freq[x % k]++;
    }
    for (const auto &i: A) {
        int a = i % k;
        int j = i / k;
        int b = k - (i - j * k);
        if (freq.find(a) != freq.end() && freq[a] > 0)
            freq[a]--;
        else if (freq.find(b) != freq.end())
            freq[b]--;
    }
    for (const auto &[k,v]: freq)
        if (v != 0) {
            cout << "NO" << ln;
            return;
        }
    cout << "YES" << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
