//https://atcoder.jp/contests/abc456/tasks/abc456_e
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


struct PairHash {
    template<typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        size_t h1 = hash<T1>{}(p.first);
        size_t h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 * 2654435761ULL + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

const int MAX = 1e5 + 1;

int n, m, w;
vector<int> adj[MAX];
string A[MAX];
unordered_map<Pair, vector<Pair >, PairHash> G;
unordered_map<Pair, int, PairHash> color;
unordered_set<Pair, PairHash> vis;


bool dfs(Pair u) {
    bool ans = false;
    color[u] = 1;
    for (const auto &v: G[u])
        if (color.find(v) == color.end())
            ans |= dfs(v);
        else if (color[v] == 1)
            return true;
    color[u] = 2;
    return ans;
}


void solve() {
    cin >> n >> m;
    G.clear();
    vis.clear();
    color.clear();
    For(u, 0, n) {
        adj[u].clear();
        adj[u].push_back(u);
    }
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> w;
    For(i, 0, n)
        cin >> A[i];

    queue<Pair > Q;
    For(u, 0, n)
        if (A[u][0] == 'o') {
            Q.push(mk(u, 0));
            vis.insert(mk(u, 0));
        }

    while (!Q.empty()) {
        Pair e = Q.front();
        Q.pop();
        int u = e.first;
        int d = e.second;
        for (const auto &v: adj[u]) {
            Pair next = {v, (d + 1) % w};
            if (A[v][(d + 1) % w] == 'o') {
                G[e].push_back(next);
                if (vis.find(next) == vis.end()) {
                    Q.push(next);
                    vis.insert(next);
                }
            }
        }
    }


    for (const auto &[u,v]: G)
        if (color.find(u) == color.end())
            if (dfs(u)) {
                cout << "Yes" << ln;
                return;
            }
    cout << "No" << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
