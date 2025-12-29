//https://vjudge.net/problem/UVA-11111
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


void solve() {
    string in;
    while (getline(cin, in)) {
        stringstream ss(in);
        vector<int> A;
        int x;
        while (ss >> x)
            A.push_back(x);
        int n = sz(A);
        stack<Pair > Q;
        bool cond = true;
        For(i, 0, n) {
            if (A[i] < 0) {
                if (!Q.empty())
                    Q.top().second += abs(A[i]);
                Q.emplace(abs(A[i]), 0);
            } else {
                if (Q.empty()) {
                    cond = false;
                    break;
                }
                Pair head = Q.top();
                if (head.first != A[i] || head.second >= A[i]) {
                    cond = false;
                    break;
                }
                Q.pop();
            }
        }
        cout << (cond && Q.empty() ? ":-) Matrioshka!" : ":-( Try again.") << ln;
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
