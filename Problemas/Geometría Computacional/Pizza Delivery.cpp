//https://codeforces.com/contest/2193/problem/F
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
#define Pair pair<ll,ll>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


struct pt {
    ll x, y;

    bool operator<(const pt &o) const {
        if (x != o.x)
            return x < o.x;
        return y < o.y;
    }

    bool operator==(const pt &o) const {
        return x == o.x && y == o.y;
    }
};

ll cost(pt a, pt b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve() {
    int n;
    cin >> n;
    pt s, t;
    cin >> s.x >> s.y >> t.x >> t.y;
    vector<pt> A(n);
    For(i, 0, n)
        cin >> A[i].x;
    For(i, 0, n)
        cin >> A[i].y;
    map<ll, pair<pt, pt> > H;
    n = sz(A);
    For(i, 0, n) {
        pt cur = A[i];
        if (H.find(cur.x) == H.end())
            H[cur.x] = {cur, cur};
        else {
            if (cur.y > H[cur.x].second.y)
                H[cur.x].second = cur;
            if (cur.y < H[cur.x].first.y)
                H[cur.x].first = cur;
        }
    }
    pair<ll, pair<pt, pt> > prev;
    prev.first = s.x;
    prev.second = {s, s};
    pair<ll,ll> prev_DP = {0, 0};
    for (const auto &e: H) {
        pt curT = e.second.second;
        pt curB = e.second.first;
        pair<ll,ll> cur_DP;
        cur_DP.first = min(prev_DP.first + cost(prev.second.second, curB) + cost(curB, curT),
                           prev_DP.second + cost(prev.second.first, curB) + cost(curB, curT));

        cur_DP.second = min(prev_DP.first + cost(prev.second.second, curT) + cost(curB, curT),
                            prev_DP.second + cost(prev.second.first, curT) + cost(curB, curT));
        prev = e;
        prev_DP = cur_DP;
    }
    cout << min(prev_DP.first + cost(prev.second.second, t),
                prev_DP.second + cost(prev.second.first, t)) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
