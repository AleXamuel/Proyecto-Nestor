//https://codeforces.com/gym/102890/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

unordered_set<char> nums;

void solve() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    int i = 0;
    unordered_map<int, int> pos;
    ll cnt = 0;
    while (i < n) {
        if (nums.find(s[i]) != nums.end()) {
            string cur = {s[i]};
            int j = i + 1;
            while (j < n && nums.find(s[j]) != nums.end())
                cur.push_back(s[j++]);
            if (cur.size() >= 9) {
                cout << "unfeasible" << ln;
                return;
            }
            i = j;
            pos[i] = stoi(cur);
        } else
            cnt++;
        i++;
    }
    for (const auto &e: pos)
        cnt += e.second;

    if (cnt > k) {
        cout << "unfeasible" << ln;
        return;
    }
    For(i, 0, n) {
        if (nums.find(s[i]) != nums.end())
            continue;
        if (pos.find(i) != pos.end())
            For(j, 0, pos[i])
                cout << s[i];
        else
            cout << s[i];
    }
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (char c = '0'; c <= '9'; c++)
        nums.insert(c);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
