//https://codeforces.com/contest/2203/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rfor(i, n, k) for (ll i = n; i >= k; i--)
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
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    sort(all(A));
    A.erase(unique(all(A)), A.end());
    n = sz(A);
    vector<int> B(m);
    int N = 0;
    for (int &i: B) {
        cin >> i;
        N = max(N, i);
    }
    vector<int> sieve(N + 1, 0);
    For(i, 0, n)
        for (int j = A[i]; j <= N; j += A[i])
            sieve[j]++;

    int a = 0;
    int b = 0;
    int c = 0;
    For(i, 0, m) {
        if (sieve[B[i]] == n)
            a++;
        else if (sieve[B[i]] == 0)
            b++;
        else
            c++;
    }
    if (c & 1) {
        if (b > a)
            cout << "Bob" << ln;
        else
            cout << "Alice" << ln;
    } else {
        if (a > b) {
            cout << "Alice" << ln;
        } else
            cout << "Bob" << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
