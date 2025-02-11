//https://codeforces.com/contest/702/problem/B
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    unordered_map<int, int> freq;
    fori(i, 0, n) {
        cin >> A[i];
        freq[A[i]]++;
    }
    long long c = 0;
    fori(i, 0, n) {
        freq[A[i]]--;
        fori(j, 1, 31) {
            int need = (1 << j) - A[i];
            if (freq.find(need) != freq.end())
                c += freq[need];
        }
    }
    cout << c << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
