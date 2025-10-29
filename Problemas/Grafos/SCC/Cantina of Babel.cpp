//https://open.kattis.com/problems/cantinaofbabel?tab=metadata
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
#define MOD (a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;

const int MAX = 100;

unordered_set<int> adj[MAX];
unordered_set<int> adjT[MAX];
stack<int> topsort;
int scc[MAX];
vector<bool> visited;


void dfs(int u) {
    visited[u] = true;
    for (const auto &v: adj[u])
        if (!visited[v])
            dfs(v);
    topsort.push(u);
}

void dfsK(int u, int nscc) {
    scc[u] = nscc;
    visited[u] = true;
    for (const auto &v: adjT[u]) {
        if (!visited[v])
            dfsK(v, nscc);
    }
}

void solve() {
    int n;
    cin >> n;
    cin.ignore();
    unordered_map<string, vector<string> > H;
    unordered_map<string, string> trad;
    unordered_map<string, int> mp;
    For(i, 0, n) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string a, b;
        ss >> a >> b;
        mp[a] = i;
        trad[a] = b;
        while (ss >> b)
            H[a].push_back(b);
    }
    for (const auto &[k1,v1]: trad)
        for (const auto &[k2,v2]: trad)
            if (k1 != k2 && v1 == v2) {
                adj[mp[k1]].insert(mp[k2]);
                adj[mp[k2]].insert(mp[k1]);
                adjT[mp[k1]].insert(mp[k2]);
                adjT[mp[k2]].insert(mp[k1]);
            }
    for (const auto &[k1,v1]: H)
        for (const auto &i: v1)
            for (const auto &[k2,v2]: trad)
                if (k1 != k2 && v2 == i) {
                    adj[mp[k2]].insert(mp[k1]);
                    adjT[mp[k1]].insert(mp[k2]);
                }

    visited.assign(n, false);
    For(i, 0, n)
        if (!visited[i])
            dfs(i);
    visited.assign(n, false);
    int nscc = 0;
    while (!topsort.empty()) {
        int u = topsort.top();
        topsort.pop();
        if (!visited[u])
            dfsK(u, nscc++);
    }
    unordered_map<int, int> freq;
    For(i, 0, n)
        freq[scc[i]]++;
    int val = -1;
    for (const auto &[k,v]: freq)
        val = max(val, v);
    cout << n - val << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
