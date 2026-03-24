//https://codeforces.com/contest/2209/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl

const int MAX = 5e3;

vector<int> t[4 * MAX];
int A[MAX];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = vector<int>(1, a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        t[v].clear();
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(),
              back_inserter(t[v]));
    }
}

int queryU(int v, int tl, int tr, int l, int r, int x) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        auto pos = upper_bound(t[v].begin(), t[v].end(), x);
        return sz(t[v]) - (pos - t[v].begin());
    }
    int tm = (tl + tr) / 2;
    return queryU(v * 2, tl, tm, l, min(r, tm), x) +
           queryU(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}

int queryL(int v, int tl, int tr, int l, int r, int x) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        auto pos = lower_bound(t[v].begin(), t[v].end(), x);
        return pos - t[v].begin();
    }
    int tm = (tl + tr) / 2;
    return queryL(v * 2, tl, tm, l, min(r, tm), x) +
           queryL(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}


void solve() {
    int n;
    cin >> n;
    For(i, 0, n)
        cin >> A[i];
    build(A, 1, 0, n - 1);
    For(i, 0, n) {
        int a = queryU(1, 0, n - 1, i + 1, n - 1, A[i]);
        int b = queryL(1, 0, n - 1, i + 1, n - 1, A[i]);
        cout << max(a, b) << " ";
    }
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
