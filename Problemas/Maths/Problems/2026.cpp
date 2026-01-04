//https://atcoder.jp/contests/abc439/tasks/abc439_c
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

const int MAX = 1e7 + 1;

int A[MAX];

void solve() {
    int n;
    cin >> n;
    memset(A, 0, sizeof(A));
    for (int i = 1; i * i <= n; i++)
        for (int j = i + 1; i * i + j * j <= n; j++)
            A[i * i + j * j]++;
    vector<int> ans;
    For(i, 1, n+1)
        if (A[i] == 1)
            ans.push_back(i);
    cout << sz(ans) << ln;
    for (const auto &i: ans)
        cout << i << " ";
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
