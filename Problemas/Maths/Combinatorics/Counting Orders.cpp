//https://codeforces.com/contest/1827/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int &i: A)
        cin >> i;
    for (int &i: B)
        cin >> i;
    sort(all(A));
    sort(all(B));
    ll ans = 1;
    Rfor(i, n-1, 0) {
        auto it = upper_bound(all(A), B[i]);
        if (it == A.end()) {
            cout << 0 << ln;
            return;
        }
        ll val = n - (it - A.begin());
        ans *= val - (n - i - 1);
        ans %= MOD;
    }
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
