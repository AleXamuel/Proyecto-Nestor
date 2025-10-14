//https://codeforces.com/contest/2160/problem/C
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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl


ostream &operator<<(ostream &os,Pair A) {
    os << "(" << A.first << "," << A.second << ")";
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, deque<T> A) {
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


void solve(int caso) {
    ll n;
    cin >> n;
    if (n == 0) {
        cout << "YES" << ln;
        return;
    }
    int j = -1;
    For(i, 0, 32) {
        if (n >> i & 1)
            j = i;
    }
    For(m, j, 64) {
        bool cond = true;
        For(i, 0, m) {
            ll val1 = n >> i & 1;
            ll val2 = n >> (m - i) & 1;
            if (val1 != val2) {
                cond = false;
                break;
            }
        }
        if (cond) {
            if (m & 1 || (n >> (m >> 1) & 1) == 0) {
                cout << "YES" << ln;
                return;
            }
        }
    }
    cout << "NO" << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    For(i, 0, t)
        solve(i + 1);
    return 0;
}
