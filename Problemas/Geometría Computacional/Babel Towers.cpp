//https://vjudge.net/problem/UVA-11116
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<double,double>
#define mk(a,b) make_pair(a,b)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define DBGM(M) cerr<<#M<<" = "; for(const auto &e:M) cerr<<"("<<e.first<<","<<e.second<<")"<<", ";cerr<<endl;
#define RAYA cerr << " ============================ " << endl;


struct pt {
    ll x, y, r;
};

Pair centro_de_masa(const vector<pt> &A, int j) {
    ll den = 0;
    ll x = 0;
    ll y = 0;
    For(i, j, sz(A)) {
        ll cur = A[i].r * A[i].r;
        x += cur * A[i].x;
        y += cur * A[i].y;
        den += cur;
    }
    return {(double) x / den, (double) y / den};
}

double dist(Pair a, Pair b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void solve() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<pt> A;
        int ans = -1;
        For(i, 0, n) {
            ll x, y, r;
            cin >> x >> y >> r;
            A.push_back({x, y, r});
            if (ans != -1)
                continue;
            For(j, 0, sz(A)-1) {
                Pair cur = centro_de_masa(A, j + 1);
                double d = dist({A[j].x, A[j].y}, cur);
                if (d >= A[j].r) {
                    ans = i;
                    break;
                }
            }
        }
        if (ans == -1) {
            cout << "Feasible" << ln;
        } else {
            cout << "Unfeasible " << ans << ln;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
