//https://domjudgeacademicueb.com/team/problems/21/statement
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


struct pt {
    int x, y;

    pt operator-(const pt &o) const {
        return {x - o.x, y - o.y};
    }

    pt operator+(const pt &o) const {
        return {x + o.x, y + o.y};
    }

    int operator*(const pt &o) const {
        return x * o.y - y * o.x;
    }
};

void solve(int caso) {
    cout << "Case " << caso << ": ";
    pt a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    pt d = c - b;
    d = d + a;
    pt v1 = b - a;
    pt v2 = d - a;
    cout << d.x << " " << d.y << " " << abs(v1 * v2) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    For(i, 1, T+1)
        solve(i);
}
