//https://codeforces.com/contest/1519/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> u(n);
        for (int i = 0; i < n; i++)
            cin >> u[i];

        vector<int> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        vector<vector<ll>> un(n);
        for (int i = 0; i < n; i++)
            un[u[i] - 1].push_back(s[i]);


        for (int i = 0; i < n; i++)
            sort(un[i].rbegin(), un[i].rend());

        vector<ll> ans(n, 0);
        for (int u = 0; u < n; u++) {
            int l = un[u].size();
            vector<ll> p(l + 1, 0);

            for (int i = 0; i < l; i++)
                p[i + 1] = un[u][i] + p[i];

            for (int k = 1; k <= l; k++)
                ans[k - 1] += p[(l / k) * k];
        }


        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
