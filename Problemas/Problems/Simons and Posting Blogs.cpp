//https://codeforces.com/contest/2205/problem/C
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
#define VI vector<int>


void solve() {
    int n;
    cin >> n;
    vector<VI > A;
    For(i, 0, n) {
        int m;
        cin >> m;
        VI cur(m);
        for (int &j: cur)
            cin >> j;
        set<int> vis;
        VI act;
        Rfor(j, m-1, 0) {
            if (vis.find(cur[j]) == vis.end()) {
                vis.insert(cur[j]);
                act.push_back(cur[j]);
            }
        }
        A.push_back(act);
    }

    vector<int> ans;
    vector<bool> vis(n, false);
    For(i, 0, n) {
        int w = -1;
        For(j, 0, n)
            if (!vis[j])
                if (w == -1 || A[j] < A[w])
                    w = j;

        if (w == -1)
            break;
        vis[w] = true;
        set<int> H;
        for (const auto &j: A[w]) {
            ans.push_back(j);
            H.insert(j);
        }
        For(j, 0, n) {
            if (vis[j])
                continue;
            VI aux;
            for (const auto &k: A[j])
                if (H.find(k) == H.end())
                    aux.push_back(k);
            A[j] = aux;
        }
    }
    for (const auto &i: ans)
        cout << i << " ";
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
