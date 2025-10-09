//https://vjudge.net/problem/UVA-11572
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

const int MAX = 1e6;
int A[MAX];

void solve() {
    int n;
    cin >> n;
    For(i, 0, n)
        cin >> A[i];
    unordered_set<int> visited;
    int l = 0;
    int r = 0;
    int ans = 0;
    while (l < n && r < n) {
        while (r < n && visited.find(A[r]) == visited.end()) {
            visited.insert(A[r]);
            ans = max(ans, r - l + 1);
            r++;
        }
        while (l < r && l < n && A[l] != A[r]) {
            visited.erase(A[l]);
            l++;
        }
        l++;
        r++;
    }
    cout << ans << ln;
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
