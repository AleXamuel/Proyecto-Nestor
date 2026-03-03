//https://codeforces.com/contest/2205/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(v) (int)((v).size())
#define Pair pair<int,int>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    vector<int> F(n), B(n);
    stack<int> cur;
    Rfor(i, n-1, 0) {
        while (!cur.empty() && A[i] > cur.top())
            cur.pop();
        F[i] = sz(cur);
        cur.push(A[i]);
    }
    while (!cur.empty())
        cur.pop();
    For(i, 0, n) {
        while (!cur.empty() && A[i] > cur.top())
            cur.pop();
        B[i] = sz(cur);
        cur.push(A[i]);
    }
    int ans = 0;
    For(i, 0, n) {
        ans = max(ans, F[i] + B[i]);
    }
    cout << n - ans - 1 << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
