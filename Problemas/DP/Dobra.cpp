//https://open.kattis.com/problems/dobra
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define Pair pair<ll,ll>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl

template<typename T>
ostream &operator<<(ostream &os, vector<T> A) {
    if (A.empty()) {
        os << "[]";
        return os;
    }
    os << "[";
    For(i, 0, A.size()-1)
        os << A[i] << ", ";
    os << A.back() << "]";
    return os;
}

int mod(int a, int b) {
    if (b < 0)
        b *= -1;
    return (a % b + b) % b;
}

string s;
int n;
unordered_set<char> V;

const int MAX = 100;

ll dp[MAX][3][3][2];

ll f(int i, int v, int c, int l) {
    if (i == n) {
        if (v >= 3)
            return 0;
        if (c >= 3)
            return 0;
        if (!l)
            return 0;
        return 1;
    }
    if (v >= 3 || c >= 3)
        return 0;
    if (dp[i][v][c][l] != -1)
        return dp[i][v][c][l];
    if (V.find(s[i]) != V.end()) {
        return dp[i][v][c][l] = f(i + 1, v + 1, 0, l);
    }
    if (s[i] == '_') {
        ll ans = 0;
        for (char C = 'A'; C <= 'Z'; C++) {
            if (V.find(C) == V.end())
                ans += f(i + 1, 0, c + 1, (C == 'L') || l);
            else
                ans += f(i + 1, v + 1, 0, l);
        }
        return dp[i][v][c][l] = ans;
    }
    return dp[i][v][c][l] = f(i + 1, 0, c + 1, (s[i] == 'L') || l);
}

void solve() {
    cin >> s;
    n = (int) s.size();
    V.insert('A');
    V.insert('E');
    V.insert('I');
    V.insert('O');
    V.insert('U');
    For(i, 0, n)
        For(j, 0, 3)
            For(k, 0, 3)
                For(u, 0, 2)
                    dp[i][j][k][u] = -1;
    cout << f(0, 0, 0, 0) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
