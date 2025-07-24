//https://codeforces.com/contest/597/problem/C
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define ull unsigned long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define ln "\n"
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > ch = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int nmax = 2e5 + 1, MOD = 998244353, inf = 1e9;
class ST {
    vector<ull> t;
    int n;
    ull combine(ull a, ull b) { return a + b; }
    void buildST(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            buildST(a, v * 2, tl, tm);
            buildST(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

    ull sumST(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return combine(sumST(v * 2, tl, tm, l, min(r, tm)),
                       sumST(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void updateST(int v, int tl, int tr, int pos, ull new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                updateST(v * 2, tl, tm, pos, new_val);
            else
                updateST(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

public:
    ST(int sz) {
        n = sz;
        t.assign(4 * n,0);
        //vector<int> a(n, 0);
        //buildST(a, 1, 0, n - 1);
    }

    ull query(int l, int r) { return sumST(1, 0, n - 1, l, r); }

    void update(int pos, ull x) { updateST(1, 0, n - 1, pos, x); }
};
void solve() {
    int n,k;cin>>n>>k;
    vector<ST>Q;
    For(i,0,k+1)
        Q.eb(n+1);
    vector<int>A(n);
    For(i,0,n)
        cin>>A[i];
    For(i,0,n) {
        For(j,0,k+1) {
            if(j>i)break;
            if(j==0)
                Q[j].update(A[i],1);
            else {
                ull act=Q[j-1].query(0,A[i]-1);
                Q[j].update(A[i],act);
            }
        }
    }
    cout<<(Q[k].query(0,n));
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
