//https://atcoder.jp/contests/abc450/tasks/abc450_d
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (ll i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    sort(all(A));
    A.erase(unique(all(A)), A.end());
    n = sz(A);
    For(i, 0, n-1)
        A[i] = A[i] + ((A.back() - A[i]) / k) * k;
    sort(all(A));
    A.erase(unique(all(A)), A.end());
    int ans = A.back() - A[0];
    For(i, 0, n-1)
        ans = min(ans, A[i] + k - A[i + 1]);
    cout << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
}
