//https://vjudge.net/problem/UVA-10020
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"

void solve() {
    int M;
    cin >> M;
    vector<pair<int, int> > A;
    while (true) {
        int l, r;
        cin >> l >> r;
        if (l == 0 && r == 0)
            break;
        A.emplace_back(l, r);
    }
    sort(all(A));
    int cur = 0;
    vector<pair<int, int> > ans;
    while (cur < M) {
        pair<int, int> need = {INT_MIN,INT_MIN};
        for (const auto &e: A) {
            int l = e.first;
            int r = e.second;
            if (l <= cur && r >= cur)
                if (r >= need.second)
                    need = {l, r};
        }
        cur = need.second;
        if (cur == INT_MIN) {
            cout << 0 << ln;
            cout << ln;
            return;
        }
        A.erase(remove(all(A), need), A.end());
        ans.emplace_back(need);
    }
    cout << ans.size() << ln;
    for (const auto &e: ans)
        cout << e.first << " " << e.second << ln;
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
