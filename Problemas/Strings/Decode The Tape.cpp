//https://vjudge.net/problem/UVA-10878
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n - 1; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"

void solve() {
    string s;
    getline(cin, s);
    while (true) {
        getline(cin, s);
        if (s[0] == '_')
            break;
        string bin = "";
        int n = s.size();
        For(i, 0, n) {
            if (s[i] == ' ')
                bin += '0';
            else if (s[i] == 'o')
                bin += '1';
        }
        char ch = (char)stoi(bin,nullptr, 2);
        cout << ch;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

