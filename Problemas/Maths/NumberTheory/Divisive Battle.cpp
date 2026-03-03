//https://codeforces.com/contest/2200/problem/E
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


const int MAX = 1e6 + 5;
vector<int> spf;


void build() {
    spf.assign(MAX, 0);
    For(i, 0, MAX)
        spf[i] = i;
    For(i, 2, MAX) {
        if (spf[i] == i) {
            if ((ll) i * i > MAX)
                continue;
            for (int j = i * i; j < MAX; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    if (is_sorted(all(A))) {
        cout << "Bob" << ln;
        return;
    }
    vector<int> cur;
    For(i, 0, n) {
        if (A[i] == 1) {
            cur.push_back(1);
            continue;
        }
        vector<int> act;
        while (A[i] != 1) {
            if (act.empty() || spf[A[i]] != act.back())
                act.push_back(spf[A[i]]);
            A[i] /= spf[A[i]];
        }
        if (sz(act) > 1) {
            cout << "Alice" << ln;
            return;
        }
        cur.push_back(act.back());
    }
    cout << (is_sorted(all(cur)) ? "Bob" : "Alice") << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
