//https://codeforces.com/contest/2043/problem/B
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

int fact(int n) {
    int ans = 1;
    For(i, 1, n+1)
        ans *= i;
    return ans;
}


void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> ans = {1};
    for (int i = 3; i <= 9; i += 2) {
        unordered_set<int> cur;
        int aux = d;
        bool cond = true;
        while (true) {
            int val = aux % i;
            if (val == 0) {
                cur.insert(val);
                break;
            }
            if (cur.find(val) != cur.end()) {
                cond = false;
                break;
            }
            cur.insert(val);
            aux *= 10;
            aux += d;
        }
        if (cond) {
            int act = cur.size();
            if (n >= act)
                ans.push_back(i);
            else {
                aux = fact(n);
                if (aux % act == 0)
                    ans.push_back(i);
            }
        }
    }
    for (const auto &i: ans)
        cout << i << " ";
    cout << ln;
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
