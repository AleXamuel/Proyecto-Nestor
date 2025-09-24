//https://codeforces.com/contest/2146/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl


void solve() {
    int n;
    string s;
    cin >> n >> s;
    if ((s.back() == '0' && s[n - 2] == '1') || (s.front() == '0' && s[1] == '1')
        || (s.find("101") < s.size())) {
        cout << "NO" << ln;
        return;
    }
    vector<int> index;
    set<int> Q;
    For(i, 0, n) {
        Q.insert(i + 1);
        if (s[i] == '1') {
            index.push_back(i);
        }
    }
    index.push_back(n);
    cout << "YES" << ln;
    For(i, 0, n) {
        if (s[i] == '1')
            cout << i + 1 << " ";
        else {
            auto it = Q.upper_bound(*upper_bound(all(index), i));
            --it;
            cout << *it << " ";
            Q.erase(it);
        }
    }
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
