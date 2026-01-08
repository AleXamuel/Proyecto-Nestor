//https://codeforces.com/contest/2171/problem/C2
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
    vector<int> B(n);
    for (int &i: B)
        cin >> i;
    int msb = -1;
    Rfor(j, 31, 0) {
        int a = 0;
        int b = 0;
        For(i, 0, n) {
            if ((A[i] >> j) & 1)
                a++;
            if (B[i] >> j & 1)
                b++;
        }
        if ((a & 1) ^ (b & 1)) {
            msb = j;
            break;
        }
    }
    if (msb == -1) {
        cout << "Tie" << ln;
        return;
    }
    Rfor(i, n-1, 0) {
        int a = A[i] >> msb & 1;
        int b = B[i] >> msb & 1;
        if ((a & 1) ^ (b & 1)) {
            cout << ((i & 1) ? "Mai" : "Ajisai") << ln;
            return;
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
