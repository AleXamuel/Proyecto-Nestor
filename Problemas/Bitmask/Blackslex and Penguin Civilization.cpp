//https://codeforces.com/contest/2179/problem/D
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
#define Pair pair<ll,ll>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


void solve() {
    int n;
    cin >> n;
    unordered_set<int> H;
    for (int msk = (1 << n) - 1; msk >= 1; msk >>= 1)
        For(i, 0, 1<<n)
            if ((i & msk) == msk && H.find(i) == H.end()) {
                cout << i << " ";
                H.insert(i);
            }
    For(i, 0, 1<<n)
        if ((i & 1) == 0)
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
}
