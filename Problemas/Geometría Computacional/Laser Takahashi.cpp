//https://atcoder.jp/contests/abc442/tasks/abc442_e
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
#define VI vector<ll>

struct pt {
    ll x, y;
};

ll cross(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
}

bool upper(const pt &a) {
    return a.y > 0 || (a.y == 0 && a.x > 0);
}

bool cmp(const pt &a, const pt &b) {
    bool upperA = upper(a);
    bool upperB = upper(b);
    if (upperA == upperB) {
        ll c = cross(a, b);
        return c > 0;
    }
    return upperA;
}

ostream &operator<<(ostream &os, const pt &a) {
    return os << "(" << a.x << "," << a.y << ")";
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pt> A(n);
    for (pt &a: A)
        cin >> a.x >> a.y;
    vector<pt> copy = A;
    sort(all(A), cmp);
    while (q--) {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        pt &a = copy[i];
        pt &b = copy[j];
        auto ita = lower_bound(all(A), a, cmp);
        auto itb = lower_bound(all(A), b, cmp);
        auto it = upper_bound(all(A), a, cmp);
        int posa = ita - A.begin();
        int posb = itb - A.begin();
        int posit = it - A.begin();
        if (posa >= posb)
            cout << posit - posb << ln;
        else
            cout << n - (posb - posit) << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
