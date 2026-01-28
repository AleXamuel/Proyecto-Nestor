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

// Splits the plane into two half-planes to allow polar sorting.

// Needed when the reference point is the origin or an interior point.
bool upper(const pt &a) {//Requiered if the reference point has points around it. 
    //Example, the origin (0,0) may have points around it.
    //for example, in convex hull this is not requiered because the point of reference is the
    //lowest in x and y.
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
    int n;
    cin >> n;
    vector<pt> A(n);
    for (pt &a: A)
        cin >> a.x >> a.y;
    sort(all(A), cmp);
    //From now points are polar sorted, it means, sort by angle with a point of reference
    //in this case, the origin (0,0).
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
