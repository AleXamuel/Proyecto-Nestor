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
#define mk(a,b) make_pair(a,b)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define DBGM(M) cerr<<#M<<" = "; for(const auto &e:M) cerr<<"("<<e.first<<","<<e.second<<")"<<", ";cerr<<endl;
#define RAYA cerr << " ============================ " << endl;

const int MAX = 1e5;

int low[MAX], d[MAX], t, cmp[MAX], n;
vector<Pair > adj[MAX];
vector<int> BT[MAX];
bool bridge[MAX];

void tarjan(int u, int par) {
    d[u] = ++t;
    low[u] = d[u];
    for (auto &e: adj[u]) {
        int v = e.first;
        int i = e.second;
        if (v == par)
            continue;
        if (d[v] == -1) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > d[u])
                bridge[i] = true;
        } else
            low[u] = min(low[u], d[v]);
    }
}

void dfs1(int u, int ncmp) {
    cmp[u] = ncmp;
    for (const auto &e: adj[u]) {
        int v = e.first;
        int i = e.second;
        if (!bridge[i] && cmp[v] == -1)
            dfs1(v, ncmp);
    }
}

void buildBT() {
    For(i, 0, n)
        d[i] = -1;
    t = 1;
    For(u, 0, n)
        if (d[u] == -1)
            tarjan(u, -1);
    For(i, 0, n)
        cmp[i] = -1;
    int ncmp = 0;
    For(i, 0, n)
        if (cmp[i] == -1)
            dfs1(i, ncmp++);

    For(u, 0, n)
        for (const auto &e: adj[u]) {
            int v = e.first;
            int i = e.second;
            if (bridge[i])
                BT[cmp[u]].push_back(cmp[v]);
        }
}


void solve() {
    int m;
    cin >> n >> m;
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    buildBT();
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
