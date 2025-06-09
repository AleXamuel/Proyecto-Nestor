//https://codeforces.com/contest/2111/problem/E
#include <bits/stdc++.h>
using namespace std;
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define ln "\n"


void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    unordered_map<string, set<int> > pos;
    For(i, 0, q) {
        char x, y;
        cin >> x >> y;
        string cur = {x, y};
        pos[cur].insert(i);
    }
    For(i, 0, n) {
        if (s[i] == 'a')
            continue;
        if (s[i] == 'b') {
            string cur = "ba";
            if (pos.find(cur) != pos.end() && !pos[cur].empty()) {
                s[i] = 'a';
                pos[cur].erase(pos[cur].begin());
            } else {
                cur = "bc";
                string cur2 = "ca";
                if (pos.find(cur) != pos.end() && !pos[cur].empty())
                    if (pos.find(cur2) != pos.end() && !pos[cur2].empty()) {
                        auto j = pos[cur2].lower_bound(*pos[cur].begin());
                        if (j != pos[cur2].end()) {
                            s[i] = 'a';
                            pos[cur].erase(pos[cur].begin());
                            pos[cur2].erase(j);
                        }
                    }
            }
        } else {
            string cur = "ca";
            if (pos.find(cur) != pos.end() && !pos[cur].empty()) {
                s[i] = 'a';
                pos[cur].erase(pos[cur].begin());
            } else {
                cur = "cb";
                string cur2 = "ba";
                bool cond = false;
                if (pos.find(cur) != pos.end() && !pos[cur].empty())
                    if (pos.find(cur2) != pos.end() && !pos[cur2].empty()) {
                        auto j = pos[cur2].lower_bound(*pos[cur].begin());
                        if (j != pos[cur2].end()) {
                            cond = true;
                            s[i] = 'a';
                            pos[cur].erase(pos[cur].begin());
                            pos[cur2].erase(j);
                        }
                    }
                if (!cond)
                    if (pos.find(cur) != pos.end() && !pos[cur].empty()) {
                        s[i] = 'b';
                        pos[cur].erase(pos[cur].begin());
                    }
            }
        }
    }
    cout << s << ln;
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
