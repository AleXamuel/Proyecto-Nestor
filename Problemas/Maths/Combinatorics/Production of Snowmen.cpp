//https://codeforces.com/contest/2182/problem/C
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

const int MAX = 5e3;
int A[3][MAX];

void solve() {
    ll n;
    cin >> n;
    For(i, 0, 3)
        For(j, 0, n)
            cin >> A[i][j];
    ll a = 0;
    For(j, 0, n) {
        int x = 1;
        For(_, 0, n)
            if (A[0][_] >= A[1][(j + _) % n]) {
                x = 0;
                break;
            }
        if (x)
            a++;
    }
    ll b = 0;
    For(j, 0, n) {
        int x = 1;
        For(_, 0, n)
            if (A[1][_] >= A[2][(j + _) % n]) {
                x = 0;
                break;
            }
        if (x)
            b++;
    }
    cout << a * b * n << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
