//https://codeforces.com/contest/2005/problem/B2
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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl


ostream &operator<<(ostream &os,Pair A) {
    os << "(" << A.first << "," << A.second << ")";
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> A) {
    if (A.empty()) {
        os << "[]";
        return os;
    }
    os << "[";
    For(i, 0, sz(A)-1)
        os << A[i] << ", ";
    os << A.back() << "]";
    return os;
}

int mod(int a, int b) {
    if (b < 0)
        b *= -1;
    return (a % b + b) % b;
}


void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    set<int> Q;
    For(i, 0, m) {
        int x;
        cin >> x;
        Q.insert(x);
    }
    while (q--) {
        int pos;
        cin >> pos;
        auto l = Q.lower_bound(pos);
        auto r = Q.upper_bound(pos);
        if (l == Q.begin()) {
            cout << pos - 1 + (*r - pos) << ln;
            continue;
        }
        --l;
        if (r != Q.end()) {
            int cur = *r - *l;
            cout << (cur >> 1) << ln;
            continue;
        }
        cout << n - pos + (pos - *l) << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
