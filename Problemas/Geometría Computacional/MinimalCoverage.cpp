//https://vjudge.net/problem/UVA-10020
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<pair<int, int> > v;
        while (true) {
            int x, y;
            cin >> x >> y;
            if (x == 0 && y == 0) break;
            v.emplace_back(x, y);
        }
        sort(v.begin(), v.end());
        vector<pair<int, int> > ans;
        int cur = 0;
        int index = -1;
        bool flag = true;
        while (cur < m) {
            pair<int, int> aux = {INT_MIN, INT_MIN};
            for (int i = index + 1; i < v.size(); i++) {
                int left = v[i].first;
                int right = v[i].second;
                if (left <= cur && right >= cur) {
                    if (right >= aux.second) {
                        aux = v[i];
                        index = i;
                    }
                }
            }

            cur = aux.second;
            if (cur == INT_MIN) {
                flag = false;
                break;
            }
            ans.emplace_back(aux);
        }
        if (flag) {
            cout << ans.size() << endl;
            for (const auto &x: ans) {
                cout << x.first << ' ' << x.second << endl;
            }
        } else cout << 0 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
