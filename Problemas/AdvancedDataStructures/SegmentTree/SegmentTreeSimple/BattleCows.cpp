//https://codeforces.com/contest/2185/problem/F
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
#define VI vector<int>


struct Node {
    int val, cnt, cntL, cntR, child;
};

const int MAX = (1 << 18) + 1;
int A[MAX];
Node t[4 * MAX];


void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {a[tl], 1, 0, 0, -1};
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        int left = 2 * v;
        int right = left + 1;
        t[v].val = t[right].val ^ t[left].val;
        t[v].cnt = t[left].cnt + t[right].cnt;
        t[v].cntL = t[left].cnt;
        t[v].cntR = t[right].cnt;
        if (t[right].val > t[left].val)
            t[v].child = 1;
        else
            t[v].child = 0;
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        t[v] = {new_val, 1, 0, 0, -1};
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        int left = 2 * v;
        int right = left + 1;
        t[v].val = t[right].val ^ t[left].val;
        t[v].cnt = t[left].cnt + t[right].cnt;
        t[v].cntL = t[left].cnt;
        t[v].cntR = t[right].cnt;
        if (t[right].val > t[left].val)
            t[v].child = 1;
        else
            t[v].child = 0;
    }
}

int query(int v, int tl, int tr, int pos) {
    if (pos == tl && pos == tr)
        return 0;
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        if (t[v].child == 1)
            return t[v].cntR + query(2 * v, tl, tm, pos);
        return query(2 * v, tl, tm, pos);
    }
    if (t[v].child == 1)
        return query(2 * v + 1, tm + 1, tr, pos);
    return t[v].cntL + query(2 * v + 1, tm + 1, tr, pos);
}


void solve() {
    int n, q;
    cin >> n >> q;
    n = 1 << n;
    VI aux(n);
    For(i, 0, n) {
        cin >> A[i];
        aux[i] = A[i];
    }
    build(A, 1, 0, n - 1);
    while (q--) {
        int pos, val;
        cin >> pos >> val;
        pos--;
        update(1, 0, n - 1, pos, val);
        cout << query(1, 0, n - 1, pos) << ln;
        update(1, 0, n - 1, pos, aux[pos]);
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
