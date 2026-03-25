//https://domjudgeacademicueb.com/team/problems/29/statement
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

const int MAX = 1e5;

int A[MAX], t[4 * MAX];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm))
           + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void solve(int caso) {
    cout << "Case " << caso << ": " << ln;
    string s;
    cin >> s;
    int n = sz(s);
    memset(A, 0, sizeof(A));
    build(A, 1, 0, n - 1);
    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == 'I') {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            update(1, 0, n - 1, l, 1);
            if (r + 1 < n)
                update(1, 0, n - 1, r + 1, -1);
        } else {
            int pos;
            cin >> pos;
            pos--;
            int sum = query(1, 0, n - 1, 0, pos);
            if (sum & 1)
                cout << (char)(s[pos] ^ 1) << ln;
            else
                cout << s[pos] << ln;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    For(i, 0, T)
        solve(i + 1);
}
