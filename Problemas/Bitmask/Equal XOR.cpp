//https://codeforces.com/contest/1944/problem/B
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long


void solve() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> A;
    unordered_map<int, int> B;
    k <<= 1;
    For(i, 0, n) {
        int x;
        cin >> x;
        A[x]++;
    }
    For(i, 0, n) {
        int x;
        cin >> x;
        B[x]++;
    }
    vector<vector<int> > aux(3, vector<int>());
    for (const auto &e: B)
        aux[e.second].push_back(e.first);
    vector<pair<int, int> > help;
    for (const auto &i: A)
        help.emplace_back(i.second, i.first);
    sort(all(help),greater());

    vector<int> ans1;
    vector<int> ans2;
    for (const auto &i: help) {
        if (ans1.size() == k)
            break;
        int val = i.second;
        int freq = i.first;
        if (freq == 2) {
            if (ans1.size() == k - 1)
                continue;
            ans1.push_back(val);
            ans1.push_back(val);
            assert(!aux[2].empty());
            int cur = aux[2].back();
            aux[2].pop_back();
            ans2.push_back(cur);
            ans2.push_back(cur);
        } else {
            ans1.push_back(val);
            ans2.push_back(val);
        }
    }
    
    for (const auto &i: ans1)
        cout << i << " ";
    cout << ln;
    for (const auto &i: ans2)
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
