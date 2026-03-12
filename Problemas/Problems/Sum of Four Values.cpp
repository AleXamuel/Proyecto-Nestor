//https://cses.fi/problemset/task/1642/
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
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl


struct item {
    int sum, i, j;

    bool operator<(const item &o) const {
        if (sum != o.sum)
            return sum < o.sum;
        if (i != o.i)
            return i < o.i;
        return j < o.j;
    }
};

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    set<item> H;
    For(i, 0, n)
        For(j, i+1, n)
            H.insert({A[i] + A[j], i, j});

    For(i, 0, n) {
        For(j, i+1, n)
            H.erase({A[i] + A[j], i, j});
        Rfor(j, i-1, 0) {
            int val = x - A[i] - A[j];
            auto it = H.lower_bound({val, -1, -1});
            if (it != H.end()) {
                item curr = *it;
                if (curr.sum == val) {
                    cout << i + 1 << " " << j + 1 << " " << curr.i + 1 << " " << curr.j + 1 << ln;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
}
